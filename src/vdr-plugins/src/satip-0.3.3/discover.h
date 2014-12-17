/*
 * discover.h: SAT>IP plugin for the Video Disk Recorder
 *
 * See the README file for copyright information and how to reach the author.
 *
 */

#ifndef __SATIP_DISCOVER_H
#define __SATIP_DISCOVER_H

#include <curl/curl.h>

#include <vdr/thread.h>
#include <vdr/tools.h>

#include "server.h"
#include "socket.h"

class cSatipDiscover : public cThread {
private:
  enum {
    eConnectTimeoutMs = 1500, // in milliseconds
    eDiscoveryPort    = 1900,
    eProbeBufferSize  = 1024, // in bytes
    eProbeTimeoutMs   = 2000, // in milliseconds
    eProbeIntervalMs  = 5000 // in milliseconds
  };
  static cSatipDiscover *instanceS;
  static const char *bcastAddressS;
  static const char *bcastMessageS;
  static size_t WriteCallback(char *ptrP, size_t sizeP, size_t nmembP, void *dataP);
  cMutex mutexM;
  CURL *handleM;
  cSatipSocket *socketM;
  cCondWait sleepM;
  cTimeMs probeIntervalM;
  cSatipServers *serversM;
  void Activate(void);
  void Deactivate(void);
  void Janitor(void);
  void Probe(void);
  void Read(void);
  void AddServer(const char *addrP, const char *descP, const char *modelP);
  // constructor
  cSatipDiscover();
  // to prevent copy constructor and assignment
  cSatipDiscover(const cSatipDiscover&);
  cSatipDiscover& operator=(const cSatipDiscover&);

protected:
  virtual void Action(void);

public:
  static cSatipDiscover *GetInstance(void);
  static bool Initialize(void);
  static void Destroy(void);
  virtual ~cSatipDiscover();
  void TriggerScan(void) { probeIntervalM.Set(0); }
  int GetServerCount(void);
  cSatipServer *GetServer(int sourceP, int systemP = -1);
  cSatipServer *GetServer(cSatipServer *serverP);
  cSatipServers *GetServers(void);
  cString GetServerString(cSatipServer *serverP);
  void UseServer(cSatipServer *serverP, bool onOffP);
  cString GetServerList(void);
  int NumProvidedSystems(void);
};

#endif // __SATIP_DISCOVER_H
