/*
 * discover.c: SAT>IP plugin for the Video Disk Recorder
 *
 * See the README file for copyright information and how to reach the author.
 *
 */

#include <string.h>
#ifdef USE_TINYXML
 #include <tinyxml/tinyxml.h>
#else
 #include <pugixml.hpp>
#endif
#include "common.h"
#include "config.h"
#include "socket.h"
#include "discover.h"

cSatipDiscover *cSatipDiscover::instanceS = NULL;

const char *cSatipDiscover::bcastAddressS = "239.255.255.250";
const char *cSatipDiscover::bcastMessageS = "M-SEARCH * HTTP/1.1\r\n"                  \
                                            "HOST: 239.255.255.250:1900\r\n"           \
                                            "MAN: \"ssdp:discover\"\r\n"               \
                                            "ST: urn:ses-com:device:SatIPServer:1\r\n" \
                                            "MX: 2\r\n\r\n";

cSatipDiscover *cSatipDiscover::GetInstance(void)
{
  if (!instanceS)
     instanceS = new cSatipDiscover();
  return instanceS;
}

bool cSatipDiscover::Initialize(void)
{
  debug("cSatipDiscover::%s()", __FUNCTION__);
  if (instanceS)
     instanceS->Activate();
  return true;
}

void cSatipDiscover::Destroy(void)
{
  debug("cSatipDiscover::%s()", __FUNCTION__);
  if (instanceS)
     instanceS->Deactivate();
}

size_t cSatipDiscover::WriteCallback(char *ptrP, size_t sizeP, size_t nmembP, void *dataP)
{
  cSatipDiscover *obj = reinterpret_cast<cSatipDiscover *>(dataP);
  size_t len = sizeP * nmembP;
  //debug("cSatipDiscover::%s(%zu)", __FUNCTION__, len);

  if (obj) {
     CURLcode res = CURLE_OK;
     const char *desc = NULL, *model = NULL, *addr = NULL;
#ifdef USE_TINYXML
     TiXmlDocument doc;
     char *xml = MALLOC(char, len + 1);
     memcpy(xml, ptrP, len);
     *(xml + len + 1) = 0;
     doc.Parse((const char *)xml);
     TiXmlHandle docHandle(&doc);
     TiXmlElement *descElement = docHandle.FirstChild("root").FirstChild("device").FirstChild("friendlyName").ToElement();
     if (descElement)
        desc = descElement->GetText() ? descElement->GetText() : "MyBrokenHardware";
     TiXmlElement *modelElement = docHandle.FirstChild("root").FirstChild("device").FirstChild("satip:X_SATIPCAP").ToElement();
     if (modelElement)
        model = modelElement->GetText() ? modelElement->GetText() : "DVBS2-1";
#else
     pugi::xml_document doc;
     pugi::xml_parse_result result = doc.load_buffer(ptrP, len);
     if (result) {
        pugi::xml_node descNode = doc.first_element_by_path("root/device/friendlyName");
        if (descNode)
           desc = descNode.text().as_string("MyBrokenHardware");
        pugi::xml_node modelNode = doc.first_element_by_path("root/device/satip:X_SATIPCAP");
        if (modelNode)
           model = modelNode.text().as_string("DVBS2-1");
        }
#endif
     SATIP_CURL_EASY_GETINFO(obj->handleM, CURLINFO_PRIMARY_IP, &addr);
     obj->AddServer(addr, desc, model);
     }

  return len;
}

cSatipDiscover::cSatipDiscover()
: cThread("SAT>IP discover"),
  mutexM(),
  handleM(curl_easy_init()),
  socketM(new cSatipSocket()),
  sleepM(),
  probeIntervalM(0),
  serversM(new cSatipServers())
{
  debug("cSatipDiscover::%s()", __FUNCTION__);
  // Start the thread
  Start();
}

cSatipDiscover::~cSatipDiscover()
{
  debug("cSatipDiscover::%s()", __FUNCTION__);
  Deactivate();
  cMutexLock MutexLock(&mutexM);
  // Free allocated memory
  DELETENULL(socketM);
  DELETENULL(serversM);
  if (handleM)
     curl_easy_cleanup(handleM);
  handleM = NULL;
}

void cSatipDiscover::Activate(void)
{
  // Start the thread
  Start();
}

void cSatipDiscover::Deactivate(void)
{
  debug("cSatipDiscover::%s()", __FUNCTION__);
  cMutexLock MutexLock(&mutexM);
  sleepM.Signal();
  if (Running())
     Cancel(3);
}

void cSatipDiscover::Action(void)
{
  debug("cSatipDiscover::%s(): entering", __FUNCTION__);
  // Do the thread loop
  while (Running()) {
        if (probeIntervalM.TimedOut()) {
           probeIntervalM.Set(eProbeIntervalMs);
           Probe();
           Janitor();
           }
        // to avoid busy loop and reduce cpu load
        sleepM.Wait(10);
        }
  debug("cSatipDiscover::%s(): exiting", __FUNCTION__);
}

void cSatipDiscover::Janitor(void)
{
  debug("cSatipDiscover::%s()", __FUNCTION__);
  cMutexLock MutexLock(&mutexM);
  if (serversM)
     serversM->Cleanup(eProbeIntervalMs * 2);
}

void cSatipDiscover::Probe(void)
{
  debug("cSatipDiscover::%s()", __FUNCTION__);
  if (socketM && socketM->Open(eDiscoveryPort)) {
     cTimeMs timeout(eProbeTimeoutMs);
     socketM->Write(bcastAddressS, reinterpret_cast<const unsigned char *>(bcastMessageS), strlen(bcastMessageS));
     while (Running() && !timeout.TimedOut()) {
           Read();
           // to avoid busy loop and reduce cpu load
           sleepM.Wait(100);
           }
     socketM->Close();
     }
}

void cSatipDiscover::Read(void)
{
  //debug("cSatipDiscover::%s()", __FUNCTION__);
  if (socketM) {
     unsigned char *buf = MALLOC(unsigned char, eProbeBufferSize + 1);
     if (buf) {
        memset(buf, 0, eProbeBufferSize + 1);
        int len = socketM->Read(buf, eProbeBufferSize);
        if (len > 0) {
           //debug("cSatipDiscover::%s(): len=%d", __FUNCTION__, len);
           bool status = false;
           char *s, *p = reinterpret_cast<char *>(buf), *location = NULL;
           char *r = strtok_r(p, "\r\n", &s);
           while (r) {
                 //debug("cSatipDiscover::%s(): %s", __FUNCTION__, r);
                 // Check the status code
                 // HTTP/1.1 200 OK
                 if (!status && startswith(r, "HTTP/1.1 200 OK")) {
                     status = true;
                     }
                 // Check the location data
                 // LOCATION: http://192.168.0.115:8888/octonet.xml
                 if (status && startswith(r, "LOCATION:")) {
                     location = compactspace(r + 9);
                     debug("cSatipDiscover::%s(): location='%s'", __FUNCTION__, location);
                     break;
                     }
                 r = strtok_r(NULL, "\r\n", &s);
                 }
           if (handleM && !isempty(location)) {
              long rc = 0;
              CURLcode res = CURLE_OK;
#ifdef DEBUG
              // Verbose output
              SATIP_CURL_EASY_SETOPT(handleM, CURLOPT_VERBOSE, 1L);
#endif
              // Set callback
              SATIP_CURL_EASY_SETOPT(handleM, CURLOPT_WRITEFUNCTION, cSatipDiscover::WriteCallback);
              SATIP_CURL_EASY_SETOPT(handleM, CURLOPT_WRITEDATA, this);

              // No progress meter and no signaling
              SATIP_CURL_EASY_SETOPT(handleM, CURLOPT_NOPROGRESS, 1L);
              SATIP_CURL_EASY_SETOPT(handleM, CURLOPT_NOSIGNAL, 1L);

              // Set timeouts
              SATIP_CURL_EASY_SETOPT(handleM, CURLOPT_TIMEOUT_MS, (long)eConnectTimeoutMs);
              SATIP_CURL_EASY_SETOPT(handleM, CURLOPT_CONNECTTIMEOUT_MS, (long)eConnectTimeoutMs);

              // Set user-agent
              SATIP_CURL_EASY_SETOPT(handleM, CURLOPT_USERAGENT, *cString::sprintf("vdr-%s/%s", PLUGIN_NAME_I18N, VERSION));

              // Set URL
              SATIP_CURL_EASY_SETOPT(handleM, CURLOPT_URL, location);

              // Fetch the data
              SATIP_CURL_EASY_PERFORM(handleM);
              SATIP_CURL_EASY_GETINFO(handleM, CURLINFO_RESPONSE_CODE, &rc);
              if (rc != 200)
                 error("Discovery detected invalid status code: %ld", rc);
              }
           }
        free(buf);
        }
     }
}

void cSatipDiscover::AddServer(const char *addrP, const char *descP, const char * modelP)
{
  debug("cSatipDiscover::%s(%s, %s, %s)", __FUNCTION__, addrP, descP, modelP);
  cMutexLock MutexLock(&mutexM);
  if (serversM) {
     cSatipServer *tmp = new cSatipServer(addrP, descP, modelP);
     // Validate against existing servers
     if (!serversM->Update(tmp)) {
        info("Adding device %s (%s %s)", tmp->Description(), tmp->Address(), tmp->Model());
        serversM->Add(tmp);
        }
     else
        DELETENULL(tmp);
     }
}

cSatipServer *cSatipDiscover::GetServer(int sourceP, int systemP)
{
  //debug("cSatipDiscover::%s(%d, %d)", __FUNCTION__, sourceP, systemP);
  cMutexLock MutexLock(&mutexM);
  return serversM ? serversM->Find(sourceP, systemP) : NULL;
}

cSatipServer *cSatipDiscover::GetServer(cSatipServer *serverP)
{
  //debug("cSatipDiscover::%s()", __FUNCTION__);
  cMutexLock MutexLock(&mutexM);
  return serversM ? serversM->Find(serverP) : NULL;
}

cSatipServers *cSatipDiscover::GetServers(void)
{
  //debug("cSatipDiscover::%s()", __FUNCTION__);
  cMutexLock MutexLock(&mutexM);
  return serversM;
}

cString cSatipDiscover::GetServerString(cSatipServer *serverP)
{
  //debug("cSatipDiscover::%s(%d)", __FUNCTION__, modelP);
  cMutexLock MutexLock(&mutexM);
  return serversM ? serversM->GetString(serverP) : "";
}

cString cSatipDiscover::GetServerList(void)
{
  //debug("cSatipDiscover::%s(%d)", __FUNCTION__, modelP);
  cMutexLock MutexLock(&mutexM);
  return serversM ? serversM->List() : "";
}

void cSatipDiscover::UseServer(cSatipServer *serverP, bool onOffP)
{
  //debug("cSatipDiscover::%s(%d)", __FUNCTION__, modelP);
  cMutexLock MutexLock(&mutexM);
  if (serversM)
     serversM->Use(serverP, onOffP);
}

int cSatipDiscover::NumProvidedSystems(void)
{
  //debug("cSatipDiscover::%s(%d)", __FUNCTION__, modelP);
  cMutexLock MutexLock(&mutexM);
  return serversM ? serversM->NumProvidedSystems() : 0;
}
