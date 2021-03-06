/*
 * dvbdevice.c: The DVB device tuner interface
 *
 * See the main source file 'vdr.c' for copyright information and
 * how to reach the author.
 *
 * $Id: dvbdevice.c 2.43 2011/08/26 12:57:34 kls Exp $
 */

#include "dvbdevice.h"
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <linux/dvb/dmx.h>
#include <linux/dvb/frontend.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include "channels.h"
#include "diseqc.h"
#include "dvbci.h"
#include "menuitems.h"
#include "sourceparams.h"

#define FE_CAN_TURBO_FEC  0x8000000 // TODO: remove this once it is defined in the driver

#define DVBS_TUNE_TIMEOUT  9000 //ms
#define DVBS_LOCK_TIMEOUT  2000 //ms
#define DVBC_TUNE_TIMEOUT  9000 //ms
#define DVBC_LOCK_TIMEOUT  2000 //ms
#define DVBT_TUNE_TIMEOUT  9000 //ms
#define DVBT_LOCK_TIMEOUT  2000 //ms
#define ATSC_TUNE_TIMEOUT  9000 //ms
#define ATSC_LOCK_TIMEOUT  2000 //ms

// --- DVB Parameter Maps ----------------------------------------------------

const tDvbParameterMap InversionValues[] = {
  {   0, INVERSION_OFF,  trNOOP("off") },
  {   1, INVERSION_ON,   trNOOP("on") },
  { 999, INVERSION_AUTO, trNOOP("auto") },
  {  -1, 0, NULL }
  };

const tDvbParameterMap BandwidthValues[] = {
  {   6, 6000000, "6 MHz" },
  {   7, 7000000, "7 MHz" },
  {   8, 8000000, "8 MHz" },
  {  -1, 0, NULL }
  };

const tDvbParameterMap CoderateValues[] = {
  {   0, FEC_NONE, trNOOP("none") },
  {  12, FEC_1_2,  "1/2" },
  {  23, FEC_2_3,  "2/3" },
  {  34, FEC_3_4,  "3/4" },
  {  35, FEC_3_5,  "3/5" },
  {  45, FEC_4_5,  "4/5" },
  {  56, FEC_5_6,  "5/6" },
  {  67, FEC_6_7,  "6/7" },
  {  78, FEC_7_8,  "7/8" },
  {  89, FEC_8_9,  "8/9" },
  { 910, FEC_9_10, "9/10" },
  { 999, FEC_AUTO, trNOOP("auto") },
  {  -1, 0, NULL }
  };

const tDvbParameterMap ModulationValues[] = {
  {  16, QAM_16,   "QAM16" },
  {  32, QAM_32,   "QAM32" },
  {  64, QAM_64,   "QAM64" },
  { 128, QAM_128,  "QAM128" },
  { 256, QAM_256,  "QAM256" },
  {   2, QPSK,     "QPSK" },
  {   5, PSK_8,    "8PSK" },
  {   6, APSK_16,  "16APSK" },
  {  10, VSB_8,    "VSB8" },
  {  11, VSB_16,   "VSB16" },
  { 998, QAM_AUTO, "QAMAUTO" },
  {  -1, 0, NULL }
  };

const tDvbParameterMap SystemValues[] = {
  {   0, SYS_DVBS,  "DVB-S" },
  {   1, SYS_DVBS2, "DVB-S2" },
  {  -1, 0, NULL }
  };

const tDvbParameterMap TransmissionValues[] = {
  {   2, TRANSMISSION_MODE_2K,   "2K" },
  {   8, TRANSMISSION_MODE_8K,   "8K" },
  { 999, TRANSMISSION_MODE_AUTO, trNOOP("auto") },
  {  -1, 0, NULL }
  };

const tDvbParameterMap GuardValues[] = {
  {   4, GUARD_INTERVAL_1_4,  "1/4" },
  {   8, GUARD_INTERVAL_1_8,  "1/8" },
  {  16, GUARD_INTERVAL_1_16, "1/16" },
  {  32, GUARD_INTERVAL_1_32, "1/32" },
  { 999, GUARD_INTERVAL_AUTO, trNOOP("auto") },
  {  -1, 0, NULL }
  };

const tDvbParameterMap HierarchyValues[] = {
  {   0, HIERARCHY_NONE, trNOOP("none") },
  {   1, HIERARCHY_1,    "1" },
  {   2, HIERARCHY_2,    "2" },
  {   4, HIERARCHY_4,    "4" },
  { 999, HIERARCHY_AUTO, trNOOP("auto") },
  {  -1, 0, NULL }
  };

const tDvbParameterMap RollOffValues[] = {
  {   0, ROLLOFF_AUTO, trNOOP("auto") },
  {  20, ROLLOFF_20, "0.20" },
  {  25, ROLLOFF_25, "0.25" },
  {  35, ROLLOFF_35, "0.35" },
  {  -1, 0, NULL }
  };

int UserIndex(int Value, const tDvbParameterMap *Map)
{
  const tDvbParameterMap *map = Map;
  while (map && map->userValue != -1) {
        if (map->userValue == Value)
           return map - Map;
        map++;
        }
  return -1;
}

int DriverIndex(int Value, const tDvbParameterMap *Map)
{
  const tDvbParameterMap *map = Map;
  while (map && map->userValue != -1) {
        if (map->driverValue == Value)
           return map - Map;
        map++;
        }
  return -1;
}

int MapToUser(int Value, const tDvbParameterMap *Map, const char **String)
{
  int n = DriverIndex(Value, Map);
  if (n >= 0) {
     if (String)
        *String = tr(Map[n].userString);
     return Map[n].userValue;
     }
  return -1;
}

const char *MapToUserString(int Value, const tDvbParameterMap *Map)
{
  int n = DriverIndex(Value, Map);
  if (n >= 0)
     return Map[n].userString;
  return "???";
}

int MapToDriver(int Value, const tDvbParameterMap *Map)
{
  int n = UserIndex(Value, Map);
  if (n >= 0)
     return Map[n].driverValue;
  return -1;
}

// --- cDvbTransponderParameters ---------------------------------------------

cDvbTransponderParameters::cDvbTransponderParameters(const char *Parameters)
{
  polarization = 0;
  inversion    = INVERSION_AUTO;
  bandwidth    = 8000000;
  coderateH    = FEC_AUTO;
  coderateL    = FEC_AUTO;
  modulation   = QPSK;
  system       = SYS_DVBS;
  transmission = TRANSMISSION_MODE_AUTO;
  guard        = GUARD_INTERVAL_AUTO;
  hierarchy    = HIERARCHY_AUTO;
  rollOff      = ROLLOFF_AUTO;
  Parse(Parameters);
}

int cDvbTransponderParameters::PrintParameter(char *p, char Name, int Value) const
{
  return Value >= 0 && Value != 999 ? sprintf(p, "%c%d", Name, Value) : 0;
}

cString cDvbTransponderParameters::ToString(char Type) const
{
#define ST(s) if (strchr(s, Type))
  char buffer[64];
  char *q = buffer;
  *q = 0;
  ST("  S ")  q += sprintf(q, "%c", polarization);
  ST("   T")  q += PrintParameter(q, 'B', MapToUser(bandwidth, BandwidthValues));
  ST(" CST")  q += PrintParameter(q, 'C', MapToUser(coderateH, CoderateValues));
  ST("   T")  q += PrintParameter(q, 'D', MapToUser(coderateL, CoderateValues));
  ST("   T")  q += PrintParameter(q, 'G', MapToUser(guard, GuardValues));
  ST("ACST")  q += PrintParameter(q, 'I', MapToUser(inversion, InversionValues));
  ST("ACST")  q += PrintParameter(q, 'M', MapToUser(modulation, ModulationValues));
  ST("  S ")  q += PrintParameter(q, 'O', MapToUser(rollOff, RollOffValues));
  ST("  S ")  q += PrintParameter(q, 'S', MapToUser(system, SystemValues));
  ST("   T")  q += PrintParameter(q, 'T', MapToUser(transmission, TransmissionValues));
  ST("   T")  q += PrintParameter(q, 'Y', MapToUser(hierarchy, HierarchyValues));
  return buffer;
}

const char *cDvbTransponderParameters::ParseParameter(const char *s, int &Value, const tDvbParameterMap *Map)
{
  if (*++s) {
     char *p = NULL;
     errno = 0;
     int n = strtol(s, &p, 10);
     if (!errno && p != s) {
        Value = MapToDriver(n, Map);
        if (Value >= 0)
           return p;
        }
     }
  esyslog("ERROR: invalid value for parameter '%c'", *(s - 1));
  return NULL;
}

#ifdef REELVDR
const char *cDvbTransponderParameters::ParseOldModulation(const char *s)
{
  if (*++s) {
     char *p = NULL;
     errno = 0;
     int n = strtol(s, &p, 10);
     if (!errno && p != s) {
        switch(n) {
            case 4 : modulation = QPSK;  system = SYS_DVBS;  break;
            case 42: modulation = QPSK;  system = SYS_DVBS2; break;
            case 8 : modulation = PSK_8; system = SYS_DVBS2; break;
            default: modulation = MapToDriver(n, ModulationValues);
        }
        if (modulation >= 0)
           return p;
        }
     }
  esyslog("ERROR: invalid value for parameter '%c'", *(s - 1));
  return NULL;
}
#endif /* REELVDR */

bool cDvbTransponderParameters::Parse(const char *s)
{
  while (s && *s) {
        switch (toupper(*s)) {
          case 'B': s = ParseParameter(s, bandwidth, BandwidthValues); break;
          case 'C': s = ParseParameter(s, coderateH, CoderateValues); break;
          case 'D': s = ParseParameter(s, coderateL, CoderateValues); break;
          case 'G': s = ParseParameter(s, guard, GuardValues); break;
          case 'H': polarization = *s++; break;
          case 'I': s = ParseParameter(s, inversion, InversionValues); break;
          case 'L': polarization = *s++; break;
#ifdef REELVDR
          case 'M': s = ParseOldModulation(s); break;                     // Support for old reel param
          case 'E': s = ParseParameter(s, rollOff, RollOffValues); break; // Support for old reel param
#else
          case 'M': s = ParseParameter(s, modulation, ModulationValues); break;
#endif /* REELVDR */
          case 'O': s = ParseParameter(s, rollOff, RollOffValues); break;
          case 'R': polarization = *s++; break;
          case 'S': s = ParseParameter(s, system, SystemValues); break;
          case 'T': s = ParseParameter(s, transmission, TransmissionValues); break;
          case 'V': polarization = *s++; break;
          case 'Y': s = ParseParameter(s, hierarchy, HierarchyValues); break;
          default: esyslog("ERROR: unknown parameter key '%c'", *s);
                   return false;
          }
        }
#ifdef REELVDR
  if((FEC_3_5 == coderateH) || (FEC_9_10 == coderateH)) system = SYS_DVBS2; // Always use DVB-S2 for 3/5 and 9/10
#endif /* REELVDR */
  return true;
}

// --- cDvbTuner -------------------------------------------------------------

#define TUNER_POLL_TIMEOUT  10 // ms

class cDvbTuner : public cThread {
private:
  enum eTunerStatus { tsIdle, tsSet, tsTuned, tsLocked };
#ifdef USE_ROTOR
 bool SendDiseqc;
#endif /* ROTOR */
  int device;
  int fd_frontend;
  int adapter, frontend;
  uint32_t subsystemId;
  int tuneTimeout;
  int lockTimeout;
  time_t lastTimeoutReport;
  fe_delivery_system frontendType;
  cChannel channel;
  const char *diseqcCommands;
  eTunerStatus tunerStatus;
  cMutex mutex;
  cCondVar locked;
  cCondVar newSet;
#ifdef USE_ROTOR
  dvb_diseqc_master_cmd diseqc_cmd;
#endif /* ROTOR */
  void ClearEventQueue(void) const;
  bool GetFrontendStatus(fe_status_t &Status) const;
  bool SetFrontend(void);
  virtual void Action(void);
public:
  cDvbTuner(int Device, int Fd_Frontend, int Adapter, int Frontend, fe_delivery_system FrontendType);
  virtual ~cDvbTuner();
  const cChannel *GetTransponder(void) const { return &channel; }
  uint32_t SubsystemId(void) const { return subsystemId; }
  bool IsTunedTo(const cChannel *Channel) const;
  void Set(const cChannel *Channel);
#ifdef USE_ROTOR
  bool SendDiseqcCmd(dvb_diseqc_master_cmd cmd);
#endif /* ROTOR */
  bool Locked(int TimeoutMs = 0);
  int GetSignalStrength(void) const;
  int GetSignalQuality(void) const;
  };

cDvbTuner::cDvbTuner(int Device, int Fd_Frontend, int Adapter, int Frontend, fe_delivery_system FrontendType)
{
  device = Device;
  fd_frontend = Fd_Frontend;
#ifdef USE_ROTOR
  SendDiseqc=false;
#endif /* ROTOR */
  adapter = Adapter;
  frontend = Frontend;
  frontendType = FrontendType;
  subsystemId = cDvbDeviceProbe::GetSubsystemId(adapter, frontend);
  tuneTimeout = 0;
  lockTimeout = 0;
  lastTimeoutReport = 0;
  diseqcCommands = NULL;
  tunerStatus = tsIdle;
  if (frontendType == SYS_DVBS || frontendType == SYS_DVBS2)
     CHECK(ioctl(fd_frontend, FE_SET_VOLTAGE, SEC_VOLTAGE_13)); // must explicitly turn on LNB power
  SetDescription("tuner on frontend %d/%d", adapter, frontend);
  Start();
}

cDvbTuner::~cDvbTuner()
{
  tunerStatus = tsIdle;
  newSet.Broadcast();
  locked.Broadcast();
  Cancel(3);
}

bool cDvbTuner::IsTunedTo(const cChannel *Channel) const
{
  if (tunerStatus == tsIdle)
     return false; // not tuned to
  if (channel.Source() != Channel->Source() || channel.Transponder() != Channel->Transponder())
     return false; // sufficient mismatch
  // Polarization is already checked as part of the Transponder.
  return strcmp(channel.Parameters(), Channel->Parameters()) == 0;
}

void cDvbTuner::Set(const cChannel *Channel)
{
  cMutexLock MutexLock(&mutex);
  if (!IsTunedTo(Channel))
     tunerStatus = tsSet;
  channel = *Channel;
  lastTimeoutReport = 0;
  newSet.Broadcast();
}

bool cDvbTuner::Locked(int TimeoutMs)
{
  bool isLocked = (tunerStatus >= tsLocked);
  if (isLocked || !TimeoutMs)
     return isLocked;

  cMutexLock MutexLock(&mutex);
  if (TimeoutMs && tunerStatus < tsLocked)
     locked.TimedWait(mutex, TimeoutMs);
  return tunerStatus >= tsLocked;
}

#ifdef USE_ROTOR
bool cDvbTuner::SendDiseqcCmd(dvb_diseqc_master_cmd cmd)
{
  cMutexLock MutexLock(&mutex);
  if ((frontendType!=SYS_DVBS2 && frontendType!=SYS_DVBS) || SendDiseqc)
    return false;
  diseqc_cmd=cmd;
  SendDiseqc=true;
  newSet.Broadcast();
  return true;
}
#endif /* ROTOR */

void cDvbTuner::ClearEventQueue(void) const
{
  cPoller Poller(fd_frontend);
  if (Poller.Poll(TUNER_POLL_TIMEOUT)) {
     dvb_frontend_event Event;
     while (ioctl(fd_frontend, FE_GET_EVENT, &Event) == 0)
           ; // just to clear the event queue - we'll read the actual status below
     }
}

bool cDvbTuner::GetFrontendStatus(fe_status_t &Status) const
{
  ClearEventQueue();
  while (1) {
        if (ioctl(fd_frontend, FE_READ_STATUS, &Status) != -1)
           return true;
        if (errno != EINTR)
           break;
        }
  return false;
}

//#define DEBUG_SIGNALSTRENGTH
//#define DEBUG_SIGNALQUALITY

int cDvbTuner::GetSignalStrength(void) const
{
  ClearEventQueue();
  uint16_t Signal;
  while (1) {
        if (ioctl(fd_frontend, FE_READ_SIGNAL_STRENGTH, &Signal) != -1)
           break;
        if (errno != EINTR)
           return -1;
        }
  uint16_t MaxSignal = 0xFFFF; // Let's assume the default is using the entire range.
  // Use the subsystemId to identify individual devices in case they need
  // special treatment to map their Signal value into the range 0...0xFFFF.
  switch (subsystemId) {
    case 0x13C21019: MaxSignal = 670; break; // TT-budget S2-3200 (DVB-S/DVB-S2)
    }
  int s = int(Signal) * 100 / MaxSignal;
  if (s > 100)
     s = 100;
#ifdef DEBUG_SIGNALSTRENGTH
  fprintf(stderr, "FE %d/%d: %08X S = %04X %04X %3d%%\n", adapter, frontend, subsystemId, MaxSignal, Signal, s);
#endif
  return s;
}

#define LOCK_THRESHOLD 5 // indicates that all 5 FE_HAS_* flags are set

int cDvbTuner::GetSignalQuality(void) const
{
  fe_status_t Status;
  if (GetFrontendStatus(Status)) {
     // Actually one would expect these checks to be done from FE_HAS_SIGNAL to FE_HAS_LOCK, but some drivers (like the stb0899) are broken, so FE_HAS_LOCK is the only one that (hopefully) is generally reliable...
     if ((Status & FE_HAS_LOCK) == 0) {
        if ((Status & FE_HAS_SIGNAL) == 0)
           return 0;
        if ((Status & FE_HAS_CARRIER) == 0)
           return 1;
        if ((Status & FE_HAS_VITERBI) == 0)
           return 2;
        if ((Status & FE_HAS_SYNC) == 0)
           return 3;
        return 4;
        }
     bool HasSnr = true;
     uint16_t Snr;
     while (1) {
           if (ioctl(fd_frontend, FE_READ_SNR, &Snr) != -1)
              break;
           if (errno == EOPNOTSUPP) {
              Snr = 0xFFFF;
              HasSnr = false;
              break;
              }
           if (errno != EINTR)
              return -1;
           }
     bool HasBer = true;
     uint32_t Ber;
     while (1) {
           if (ioctl(fd_frontend, FE_READ_BER, &Ber) != -1)
              break;
           if (errno == EOPNOTSUPP) {
              Ber = 0;
              HasBer = false;
              break;
              }
           if (errno != EINTR)
              return -1;
           }
     bool HasUnc = true;
     uint32_t Unc;
     while (1) {
           if (ioctl(fd_frontend, FE_READ_UNCORRECTED_BLOCKS, &Unc) != -1)
              break;
           if (errno == EOPNOTSUPP) {
              Unc = 0;
              HasUnc = false;
              break;
              }
           if (errno != EINTR)
              return -1;
           }
     uint16_t MaxSnr = 0xFFFF; // Let's assume the default is using the entire range.
     // Use the subsystemId to identify individual devices in case they need
     // special treatment to map their Snr value into the range 0...0xFFFF.
     switch (subsystemId) {
       case 0x13C21019: MaxSnr = 200; break; // TT-budget S2-3200 (DVB-S/DVB-S2)
       }
     int a = int(Snr) * 100 / MaxSnr;
     int b = 100 - (Unc * 10 + (Ber / 256) * 5);
     if (b < 0)
        b = 0;
     int q = LOCK_THRESHOLD + a * b * (100 - LOCK_THRESHOLD) / 100 / 100;
     if (q > 100)
        q = 100;
#ifdef DEBUG_SIGNALQUALITY
     fprintf(stderr, "FE %d/%d: %08X Q = %04X %04X %5d %5d %3d%%\n", adapter, frontend, subsystemId, MaxSnr, Snr, HasBer ? int(Ber) : -1, HasUnc ? int(Unc) : -1, q);
#endif
     return q;
     }
  return -1;
}

static unsigned int FrequencyToHz(unsigned int f)
{
  while (f && f < 1000000)
        f *= 1000;
  return f;
}

bool cDvbTuner::SetFrontend(void)
{
#ifdef RBMINI
  return false;
#else
#define MAXFRONTENDCMDS 16
#define SETCMD(c, d) { Frontend[CmdSeq.num].cmd = (c);\
                       Frontend[CmdSeq.num].u.data = (d);\
                       if (CmdSeq.num++ > MAXFRONTENDCMDS) {\
                          esyslog("ERROR: too many tuning commands on frontend %d/%d", adapter, frontend);\
                          return false;\
                          }\
                     }
  dtv_property Frontend[MAXFRONTENDCMDS];
  memset(&Frontend, 0, sizeof(Frontend));
  dtv_properties CmdSeq;
  memset(&CmdSeq, 0, sizeof(CmdSeq));
  CmdSeq.props = Frontend;
  SETCMD(DTV_CLEAR, 0);
  if (ioctl(fd_frontend, FE_SET_PROPERTY, &CmdSeq) < 0) {
     esyslog("ERROR: frontend %d/%d: %m", adapter, frontend);
     return false;
     }
  CmdSeq.num = 0;

  cDvbTransponderParameters dtp(channel.Parameters());

  if (frontendType == SYS_DVBS || frontendType == SYS_DVBS2) {
     unsigned int frequency = channel.Frequency();
     if (Setup.DiSEqC) {
        const cDiseqc *diseqc = Diseqcs.Get(device, channel.Source(), channel.Frequency(), dtp.Polarization());
        if (diseqc) {
           if (diseqc->Commands() && (!diseqcCommands || strcmp(diseqcCommands, diseqc->Commands()) != 0)) {
              cDiseqc::eDiseqcActions da;
              for (const char *CurrentAction = NULL; (da = diseqc->Execute(&CurrentAction)) != cDiseqc::daNone; ) {
                  switch (da) {
                    case cDiseqc::daNone:      break;
                    case cDiseqc::daToneOff:   CHECK(ioctl(fd_frontend, FE_SET_TONE, SEC_TONE_OFF)); break;
                    case cDiseqc::daToneOn:    CHECK(ioctl(fd_frontend, FE_SET_TONE, SEC_TONE_ON)); break;
                    case cDiseqc::daVoltage13: CHECK(ioctl(fd_frontend, FE_SET_VOLTAGE, SEC_VOLTAGE_13)); break;
                    case cDiseqc::daVoltage18: CHECK(ioctl(fd_frontend, FE_SET_VOLTAGE, SEC_VOLTAGE_18)); break;
                    case cDiseqc::daMiniA:     CHECK(ioctl(fd_frontend, FE_DISEQC_SEND_BURST, SEC_MINI_A)); break;
                    case cDiseqc::daMiniB:     CHECK(ioctl(fd_frontend, FE_DISEQC_SEND_BURST, SEC_MINI_B)); break;
                    case cDiseqc::daCodes: {
                         int n = 0;
                         const uchar *codes = diseqc->Codes(n);
                         if (codes) {
                            struct dvb_diseqc_master_cmd cmd;
                            cmd.msg_len = min(n, int(sizeof(cmd.msg)));
                            memcpy(cmd.msg, codes, cmd.msg_len);
                            CHECK(ioctl(fd_frontend, FE_DISEQC_SEND_MASTER_CMD, &cmd));
                            }
                         }
                         break;
                    default: esyslog("ERROR: unknown diseqc command %d", da);
                    }
                  }
              diseqcCommands = diseqc->Commands();
              }
           frequency -= diseqc->Lof();
           }
        else {
           esyslog("ERROR: no DiSEqC parameters found for channel %d", channel.Number());
           return false;
           }
        }
     else {
        int tone = SEC_TONE_OFF;
        if (frequency < (unsigned int)Setup.LnbSLOF) {
           frequency -= Setup.LnbFrequLo;
           tone = SEC_TONE_OFF;
           }
        else {
           frequency -= Setup.LnbFrequHi;
           tone = SEC_TONE_ON;
           }
        int volt = (dtp.Polarization() == 'v' || dtp.Polarization() == 'V' || dtp.Polarization() == 'r' || dtp.Polarization() == 'R') ? SEC_VOLTAGE_13 : SEC_VOLTAGE_18;
        CHECK(ioctl(fd_frontend, FE_SET_VOLTAGE, volt));
        CHECK(ioctl(fd_frontend, FE_SET_TONE, tone));
        }
     frequency = abs(frequency); // Allow for C-band, where the frequency is less than the LOF

     // DVB-S/DVB-S2 (common parts)
     SETCMD(DTV_DELIVERY_SYSTEM, dtp.System());
     SETCMD(DTV_FREQUENCY, frequency * 1000UL);
     SETCMD(DTV_MODULATION, dtp.Modulation());
     SETCMD(DTV_SYMBOL_RATE, channel.Srate() * 1000UL);
     SETCMD(DTV_INNER_FEC, dtp.CoderateH());
     SETCMD(DTV_INVERSION, dtp.Inversion());
     if (dtp.System() == SYS_DVBS2) {
        if (frontendType == SYS_DVBS2) {
           // DVB-S2
           SETCMD(DTV_PILOT, PILOT_AUTO);
           SETCMD(DTV_ROLLOFF, dtp.RollOff());
           }
        else {
           esyslog("ERROR: frontend %d/%d doesn't provide DVB-S2", adapter, frontend);
           return false;
           }
        }
     else {
        // DVB-S
        SETCMD(DTV_ROLLOFF, ROLLOFF_35); // DVB-S always has a ROLLOFF of 0.35
        }

     tuneTimeout = DVBS_TUNE_TIMEOUT;
     lockTimeout = DVBS_LOCK_TIMEOUT;
     }
  else if (frontendType == SYS_DVBC_ANNEX_AC || frontendType == SYS_DVBC_ANNEX_B) {
     // DVB-C
     SETCMD(DTV_DELIVERY_SYSTEM, frontendType);
     SETCMD(DTV_FREQUENCY, FrequencyToHz(channel.Frequency()));
     SETCMD(DTV_INVERSION, dtp.Inversion());
     SETCMD(DTV_SYMBOL_RATE, channel.Srate() * 1000UL);
     SETCMD(DTV_INNER_FEC, dtp.CoderateH());
     SETCMD(DTV_MODULATION, dtp.Modulation());

     tuneTimeout = DVBC_TUNE_TIMEOUT;
     lockTimeout = DVBC_LOCK_TIMEOUT;
     }
  else if (frontendType == SYS_DVBT) {
     // DVB-T
     SETCMD(DTV_DELIVERY_SYSTEM, frontendType);
     SETCMD(DTV_FREQUENCY, FrequencyToHz(channel.Frequency()));
     SETCMD(DTV_INVERSION, dtp.Inversion());
     SETCMD(DTV_BANDWIDTH_HZ, dtp.Bandwidth());
     SETCMD(DTV_CODE_RATE_HP, dtp.CoderateH());
     SETCMD(DTV_CODE_RATE_LP, dtp.CoderateL());
     SETCMD(DTV_MODULATION, dtp.Modulation());
     SETCMD(DTV_TRANSMISSION_MODE, dtp.Transmission());
     SETCMD(DTV_GUARD_INTERVAL, dtp.Guard());
     SETCMD(DTV_HIERARCHY, dtp.Hierarchy());

     tuneTimeout = DVBT_TUNE_TIMEOUT;
     lockTimeout = DVBT_LOCK_TIMEOUT;
     }
  else if (frontendType == SYS_ATSC) {
     // ATSC
     SETCMD(DTV_DELIVERY_SYSTEM, frontendType);
     SETCMD(DTV_FREQUENCY, FrequencyToHz(channel.Frequency()));
     SETCMD(DTV_INVERSION, dtp.Inversion());
     SETCMD(DTV_MODULATION, dtp.Modulation());

     tuneTimeout = ATSC_TUNE_TIMEOUT;
     lockTimeout = ATSC_LOCK_TIMEOUT;
     }
  else {
     esyslog("ERROR: attempt to set channel with unknown DVB frontend type");
     return false;
     }
  SETCMD(DTV_TUNE, 0);
  if (ioctl(fd_frontend, FE_SET_PROPERTY, &CmdSeq) < 0) {
     esyslog("ERROR: frontend %d/%d: %m", adapter, frontend);
     return false;
     }
  return true;
#endif
}

void cDvbTuner::Action(void)
{
  cTimeMs Timer;
  bool LostLock = false;
  fe_status_t Status = (fe_status_t)0;
  while (Running()) {
        fe_status_t NewStatus;
        if (GetFrontendStatus(NewStatus))
           Status = NewStatus;
        cMutexLock MutexLock(&mutex);
#ifdef USE_ROTOR
        if (SendDiseqc) {
           CHECK(ioctl(fd_frontend, FE_DISEQC_SEND_MASTER_CMD, &diseqc_cmd));
           SendDiseqc=false;
           }
#endif /* ROTOR */
        switch (tunerStatus) {
          case tsIdle:
               break;
          case tsSet:
               tunerStatus = SetFrontend() ? tsTuned : tsIdle;
               Timer.Set(tuneTimeout);
               continue;
          case tsTuned:
               if (Timer.TimedOut()) {
                  tunerStatus = tsSet;
                  diseqcCommands = NULL;
                  if (time(NULL) - lastTimeoutReport > 60) { // let's not get too many of these
                     isyslog("frontend %d/%d timed out while tuning to channel %d, tp %d", adapter, frontend, channel.Number(), channel.Transponder());
                     lastTimeoutReport = time(NULL);
                     }
                  continue;
                  }
          case tsLocked:
               if (Status & FE_REINIT) {
                  tunerStatus = tsSet;
                  diseqcCommands = NULL;
                  isyslog("frontend %d/%d was reinitialized", adapter, frontend);
                  lastTimeoutReport = 0;
                  continue;
                  }
               else if (Status & FE_HAS_LOCK) {
                  if (LostLock) {
                     isyslog("frontend %d/%d regained lock on channel %d, tp %d", adapter, frontend, channel.Number(), channel.Transponder());
                     LostLock = false;
                     }
                  tunerStatus = tsLocked;
                  locked.Broadcast();
                  lastTimeoutReport = 0;
                  }
               else if (tunerStatus == tsLocked) {
                  LostLock = true;
                  isyslog("frontend %d/%d lost lock on channel %d, tp %d", adapter, frontend, channel.Number(), channel.Transponder());
                  tunerStatus = tsTuned;
                  Timer.Set(lockTimeout);
                  lastTimeoutReport = 0;
                  continue;
                  }
               break;
          default: esyslog("ERROR: unknown tuner status %d", tunerStatus);
          }

        if (tunerStatus != tsTuned)
           newSet.TimedWait(mutex, 1000);
        }
}

// --- cDvbSourceParam -------------------------------------------------------

class cDvbSourceParam : public cSourceParam {
private:
  int param;
  int srate;
  cDvbTransponderParameters dtp;
public:
  cDvbSourceParam(char Source, const char *Description);
  virtual void SetData(cChannel *Channel);
  virtual void GetData(cChannel *Channel);
  virtual cOsdItem *GetOsdItem(void);
  };

cDvbSourceParam::cDvbSourceParam(char Source, const char *Description)
:cSourceParam(Source, Description)
{
  param = 0;
  srate = 0;
}

void cDvbSourceParam::SetData(cChannel *Channel)
{
  srate = Channel->Srate();
  dtp.Parse(Channel->Parameters());
  param = 0;
}

void cDvbSourceParam::GetData(cChannel *Channel)
{
  Channel->SetTransponderData(Channel->Source(), Channel->Frequency(), srate, dtp.ToString(Source()), true);
}

cOsdItem *cDvbSourceParam::GetOsdItem(void)
{
  char type = Source();
#undef ST
#define ST(s) if (strchr(s, type))
  switch (param++) {
    case  0: ST("  S ")  return new cMenuEditChrItem( tr("Polarization"), &dtp.polarization, "HVLR");             else return GetOsdItem();
    case  1: ST("  S ")  return new cMenuEditMapItem( tr("System"),       &dtp.system,       SystemValues);       else return GetOsdItem();
    case  2: ST(" CS ")  return new cMenuEditIntItem( tr("Srate"),        &srate);                                else return GetOsdItem();
    case  3: ST("ACST")  return new cMenuEditMapItem( tr("Inversion"),    &dtp.inversion,    InversionValues);    else return GetOsdItem();
    case  4: ST(" CST")  return new cMenuEditMapItem( tr("CoderateH"),    &dtp.coderateH,    CoderateValues);     else return GetOsdItem();
    case  5: ST("   T")  return new cMenuEditMapItem( tr("CoderateL"),    &dtp.coderateL,    CoderateValues);     else return GetOsdItem();
    case  6: ST("ACST")  return new cMenuEditMapItem( tr("Modulation"),   &dtp.modulation,   ModulationValues);   else return GetOsdItem();
    case  7: ST("   T")  return new cMenuEditMapItem( tr("Bandwidth"),    &dtp.bandwidth,    BandwidthValues);    else return GetOsdItem();
    case  8: ST("   T")  return new cMenuEditMapItem( tr("Transmission"), &dtp.transmission, TransmissionValues); else return GetOsdItem();
    case  9: ST("   T")  return new cMenuEditMapItem( tr("Guard"),        &dtp.guard,        GuardValues);        else return GetOsdItem();
    case 10: ST("   T")  return new cMenuEditMapItem( tr("Hierarchy"),    &dtp.hierarchy,    HierarchyValues);    else return GetOsdItem();
    case 11: ST("  S ")  return new cMenuEditMapItem( tr("Rolloff"),      &dtp.rollOff,      RollOffValues);      else return GetOsdItem();
    default: return NULL;
    }
  return NULL;
}

// --- cDvbDevice ------------------------------------------------------------

int cDvbDevice::setTransferModeForDolbyDigital = 1;

const char *DeliverySystems[] = {
  "UNDEFINED",
  "DVB-C",
  "DVB-C",
  "DVB-T",
  "DSS",
  "DVB-S",
  "DVB-S2",
  "DVB-H",
  "ISDBT",
  "ISDBS",
  "ISDBC",
  "ATSC",
  "ATSCMH",
  "DMBTH",
  "CMMB",
  "DAB",
  NULL
  };

cDvbDevice::cDvbDevice(int Adapter, int Frontend)
{
  adapter = Adapter;
  frontend = Frontend;
  ciAdapter = NULL;
  dvbTuner = NULL;
  frontendType = SYS_UNDEFINED;
  numProvidedSystems = 0;

  // Devices that are present on all card types:

  int fd_frontend = DvbOpen(DEV_DVB_FRONTEND, adapter, frontend, O_RDWR | O_NONBLOCK);

  // Common Interface:

  fd_ca = DvbOpen(DEV_DVB_CA, adapter, frontend, O_RDWR);
  if (fd_ca >= 0)
     ciAdapter = cDvbCiAdapter::CreateCiAdapter(this, fd_ca);

  // The DVR device (will be opened and closed as needed):

  fd_dvr = -1;

#ifdef USE_LNBSHARE
  lnbState = -1;
  SetLnbNrFromSetup();
  lnbSource = NULL;
#endif /* LNBSHARE */

  // We only check the devices that must be present - the others will be checked before accessing them://XXX

  if (fd_frontend >= 0) {
     if (ioctl(fd_frontend, FE_GET_INFO, &frontendInfo) >= 0) {
        switch (frontendInfo.type) {
#ifndef RBMINI
          case FE_QPSK: frontendType = (frontendInfo.caps & FE_CAN_2G_MODULATION) ? SYS_DVBS2 : SYS_DVBS; break;
#endif
          case FE_OFDM: frontendType = SYS_DVBT; break;
          case FE_QAM:  frontendType = SYS_DVBC_ANNEX_AC; break;
          case FE_ATSC: frontendType = SYS_ATSC; break;
          default: esyslog("ERROR: unknown frontend type %d on frontend %d/%d", frontendInfo.type, adapter, frontend);
          }
        }
     else
        LOG_ERROR;
     if (frontendType != SYS_UNDEFINED) {
        numProvidedSystems++;
        if (frontendType == SYS_DVBS2)
           numProvidedSystems++;
        char Modulations[64];
        char *p = Modulations;
        if (frontendInfo.caps & FE_CAN_QPSK)    { numProvidedSystems++; p += sprintf(p, ",%s", MapToUserString(QPSK, ModulationValues)); }
        if (frontendInfo.caps & FE_CAN_QAM_16)  { numProvidedSystems++; p += sprintf(p, ",%s", MapToUserString(QAM_16, ModulationValues)); }
        if (frontendInfo.caps & FE_CAN_QAM_32)  { numProvidedSystems++; p += sprintf(p, ",%s", MapToUserString(QAM_32, ModulationValues)); }
        if (frontendInfo.caps & FE_CAN_QAM_64)  { numProvidedSystems++; p += sprintf(p, ",%s", MapToUserString(QAM_64, ModulationValues)); }
        if (frontendInfo.caps & FE_CAN_QAM_128) { numProvidedSystems++; p += sprintf(p, ",%s", MapToUserString(QAM_128, ModulationValues)); }
        if (frontendInfo.caps & FE_CAN_QAM_256) { numProvidedSystems++; p += sprintf(p, ",%s", MapToUserString(QAM_256, ModulationValues)); }
        if (frontendInfo.caps & FE_CAN_8VSB)    { numProvidedSystems++; p += sprintf(p, ",%s", MapToUserString(VSB_8, ModulationValues)); }
        if (frontendInfo.caps & FE_CAN_16VSB)   { numProvidedSystems++; p += sprintf(p, ",%s", MapToUserString(VSB_16, ModulationValues)); }
        if (frontendInfo.caps & FE_CAN_TURBO_FEC){numProvidedSystems++; p += sprintf(p, ",%s", "TURBO_FEC"); }
        if (p != Modulations)
           p = Modulations + 1; // skips first ','
        else
           p = (char *)"unknown modulations";
        isyslog("frontend %d/%d provides %s with %s (\"%s\")", adapter, frontend, DeliverySystems[frontendType], p, frontendInfo.name);
        dvbTuner = new cDvbTuner(CardIndex() + 1, fd_frontend, adapter, frontend, frontendType);
        }
     }
  else
     esyslog("ERROR: can't open DVB device %d/%d", adapter, frontend);

  StartSectionHandler();
}

cDvbDevice::~cDvbDevice()
{
  StopSectionHandler();
  delete dvbTuner;
  delete ciAdapter;
  // We're not explicitly closing any device files here, since this sometimes
  // caused segfaults. Besides, the program is about to terminate anyway...
}

cString cDvbDevice::DvbName(const char *Name, int Adapter, int Frontend)
{
  return cString::sprintf("%s%d/%s%d", DEV_DVB_ADAPTER, Adapter, Name, Frontend);
}

int cDvbDevice::DvbOpen(const char *Name, int Adapter, int Frontend, int Mode, bool ReportError)
{
  cString FileName = DvbName(Name, Adapter, Frontend);
  int fd = open(FileName, Mode);
  if (fd < 0 && ReportError)
     LOG_ERROR_STR(*FileName);
  return fd;
}

bool cDvbDevice::Exists(int Adapter, int Frontend)
{
  cString FileName = DvbName(DEV_DVB_FRONTEND, Adapter, Frontend);
  if (access(FileName, F_OK) == 0) {
     int f = open(FileName, O_RDONLY);
     if (f >= 0) {
        close(f);
        return true;
        }
     else if (errno != ENODEV && errno != EINVAL)
        LOG_ERROR_STR(*FileName);
     }
  else if (errno != ENOENT)
     LOG_ERROR_STR(*FileName);
  return false;
}

bool cDvbDevice::Probe(int Adapter, int Frontend)
{
  cString FileName = DvbName(DEV_DVB_FRONTEND, Adapter, Frontend);
  dsyslog("probing %s", *FileName);
  for (cDvbDeviceProbe *dp = DvbDeviceProbes.First(); dp; dp = DvbDeviceProbes.Next(dp)) {
      if (dp->Probe(Adapter, Frontend))
         return true; // a plugin has created the actual device
      }
  dsyslog("creating cDvbDevice");
  new cDvbDevice(Adapter, Frontend); // it's a "budget" device
  return true;
}

bool cDvbDevice::Initialize(void)
{
  new cDvbSourceParam('A', "ATSC");
  new cDvbSourceParam('C', "DVB-C");
  new cDvbSourceParam('S', "DVB-S");
  new cDvbSourceParam('T', "DVB-T");
  int Checked = 0;
  int Found = 0;
  for (int Adapter = 0; ; Adapter++) {
      for (int Frontend = 0; ; Frontend++) {
          if (Exists(Adapter, Frontend)) {
             if (Checked++ < MAXDVBDEVICES) {
                if (UseDevice(NextCardIndex())) {
                   if (Probe(Adapter, Frontend))
                      Found++;
                   }
                else
                   NextCardIndex(1); // skips this one
                }
             }
          else if (Frontend == 0)
             goto LastAdapter;
          else
             goto NextAdapter;
          }
      NextAdapter: ;
      }
LastAdapter:
  NextCardIndex(MAXDVBDEVICES - Checked); // skips the rest
  if (Found > 0)
     isyslog("found %d DVB device%s", Found, Found > 1 ? "s" : "");
  else
     isyslog("no DVB device found");
  return Found > 0;
}

bool cDvbDevice::Ready(void)
{
  if (ciAdapter)
     return ciAdapter->Ready();
  return true;
}

bool cDvbDevice::HasCi(void)
{
  return ciAdapter;
}

bool cDvbDevice::SetPid(cPidHandle *Handle, int Type, bool On)
{
  if (Handle->pid) {
     dmx_pes_filter_params pesFilterParams;
     memset(&pesFilterParams, 0, sizeof(pesFilterParams));
     if (On) {
        if (Handle->handle < 0) {
           Handle->handle = DvbOpen(DEV_DVB_DEMUX, adapter, frontend, O_RDWR | O_NONBLOCK, true);
           if (Handle->handle < 0) {
              LOG_ERROR;
              return false;
              }
           }
        pesFilterParams.pid     = Handle->pid;
        pesFilterParams.input   = DMX_IN_FRONTEND;
        pesFilterParams.output  = DMX_OUT_TS_TAP;
        pesFilterParams.pes_type= DMX_PES_OTHER;
        pesFilterParams.flags   = DMX_IMMEDIATE_START;
        if (ioctl(Handle->handle, DMX_SET_PES_FILTER, &pesFilterParams) < 0) {
           LOG_ERROR;
           return false;
           }
        }
     else if (!Handle->used) {
        CHECK(ioctl(Handle->handle, DMX_STOP));
        if (Type <= ptTeletext) {
           pesFilterParams.pid     = 0x1FFF;
           pesFilterParams.input   = DMX_IN_FRONTEND;
           pesFilterParams.output  = DMX_OUT_DECODER;
           pesFilterParams.pes_type= DMX_PES_OTHER;
           pesFilterParams.flags   = DMX_IMMEDIATE_START;
           CHECK(ioctl(Handle->handle, DMX_SET_PES_FILTER, &pesFilterParams));
           }
        close(Handle->handle);
        Handle->handle = -1;
        }
     }
  return true;
}

int cDvbDevice::OpenFilter(u_short Pid, u_char Tid, u_char Mask)
{
  cString FileName = DvbName(DEV_DVB_DEMUX, adapter, frontend);
  int f = open(FileName, O_RDWR | O_NONBLOCK);
  if (f >= 0) {
     dmx_sct_filter_params sctFilterParams;
     memset(&sctFilterParams, 0, sizeof(sctFilterParams));
     sctFilterParams.pid = Pid;
     sctFilterParams.timeout = 0;
     sctFilterParams.flags = DMX_IMMEDIATE_START;
     sctFilterParams.filter.filter[0] = Tid;
     sctFilterParams.filter.mask[0] = Mask;
     if (ioctl(f, DMX_SET_FILTER, &sctFilterParams) >= 0)
        return f;
     else {
        esyslog("ERROR: can't set filter (pid=%d, tid=%02X, mask=%02X): %m", Pid, Tid, Mask);
        close(f);
        }
     }
  else
     esyslog("ERROR: can't open filter handle on '%s'", *FileName);
  return -1;
}

void cDvbDevice::CloseFilter(int Handle)
{
  close(Handle);
}

bool cDvbDevice::ProvidesSource(int Source) const
{
  int type = Source & cSource::st_Mask;
  return type == cSource::stNone
      || type == cSource::stAtsc  && (frontendType == SYS_ATSC)
      || type == cSource::stCable && (frontendType == SYS_DVBC_ANNEX_AC || frontendType == SYS_DVBC_ANNEX_B)
      || type == cSource::stSat   && (frontendType == SYS_DVBS || frontendType == SYS_DVBS2)
      || type == cSource::stTerr  && (frontendType == SYS_DVBT);
}

bool cDvbDevice::ProvidesTransponder(const cChannel *Channel) const
{
  if (!ProvidesSource(Channel->Source()))
     return false; // doesn't provide source
  cDvbTransponderParameters dtp(Channel->Parameters());
  if (dtp.System() == SYS_DVBS2 && frontendType == SYS_DVBS ||
     dtp.Modulation() == QPSK     && !(frontendInfo.caps & FE_CAN_QPSK) ||
     dtp.Modulation() == QAM_16   && !(frontendInfo.caps & FE_CAN_QAM_16) ||
     dtp.Modulation() == QAM_32   && !(frontendInfo.caps & FE_CAN_QAM_32) ||
     dtp.Modulation() == QAM_64   && !(frontendInfo.caps & FE_CAN_QAM_64) ||
     dtp.Modulation() == QAM_128  && !(frontendInfo.caps & FE_CAN_QAM_128) ||
     dtp.Modulation() == QAM_256  && !(frontendInfo.caps & FE_CAN_QAM_256) ||
     dtp.Modulation() == QAM_AUTO && !(frontendInfo.caps & FE_CAN_QAM_AUTO) ||
     dtp.Modulation() == VSB_8    && !(frontendInfo.caps & FE_CAN_8VSB) ||
     dtp.Modulation() == VSB_16   && !(frontendInfo.caps & FE_CAN_16VSB) ||
     dtp.Modulation() == PSK_8    && !(frontendInfo.caps & FE_CAN_TURBO_FEC) && dtp.System() == SYS_DVBS) // "turbo fec" is a non standard FEC used by North American broadcasters - this is a best guess to determine this condition
     return false; // requires modulation system which frontend doesn't provide
  if (!cSource::IsSat(Channel->Source()) ||
     !Setup.DiSEqC || Diseqcs.Get(CardIndex() + 1, Channel->Source(), Channel->Frequency(), dtp.Polarization()))
     return DeviceHooksProvidesTransponder(Channel);
  return false;
}

bool cDvbDevice::ProvidesChannel(const cChannel *Channel, int Priority, bool *NeedsDetachReceivers) const
{
#ifdef USE_CHANNELPROVIDE
  if (Setup.LocalChannelProvide != 1)
     return false;
#endif /* CHANNELPROVIDE */
  bool result = false;
  bool hasPriority = Priority < 0 || Priority > this->Priority();
  bool needsDetachReceivers = false;

#ifdef USE_CHANNELBIND
  if (Setup.ChannelBindingByRid && Channel->Rid()) {
    if (0 == ((unsigned) Channel->Rid() & (1<<(unsigned) CardIndex())) ) {
      #if 0
      printf("device %d doesn't provide channel %s", CardIndex(), *Channel->ToText());
      #endif
      return false;
      }
    }
#endif /* CHANNELBIND */

  if (dvbTuner && ProvidesTransponder(Channel)) {
     result = hasPriority;
     if (Priority >= 0 && Receiving(true)) {
        if (dvbTuner->IsTunedTo(Channel)) {
           if (Channel->Vpid() && !HasPid(Channel->Vpid()) || Channel->Apid(0) && !HasPid(Channel->Apid(0))) {
              if (CamSlot() && Channel->Ca() >= CA_ENCRYPTED_MIN) {
                 if (CamSlot()->CanDecrypt(Channel))
                    result = true;
                 else
                    needsDetachReceivers = true;
                 }
              else if (!IsPrimaryDevice())
                 result = true;
              else
                 result = Priority >= Setup.PrimaryLimit;
              }
           else
              result = !IsPrimaryDevice() || Priority >= Setup.PrimaryLimit;
           }
        else
           needsDetachReceivers = true;
        }
     }
#ifdef USE_LNBSHARE
  if(Priority >= 0 && result && !(Receiving(true) && dvbTuner->IsTunedTo(Channel)) && GetMaxBadPriority(Channel) >= Priority) result = false;
#endif /* LNBSHARE */
  if (NeedsDetachReceivers)
     *NeedsDetachReceivers = needsDetachReceivers;
  return result;
}

bool cDvbDevice::ProvidesEIT(void) const
{
  return dvbTuner != NULL;
}

int cDvbDevice::NumProvidedSystems(void) const
{
  return numProvidedSystems;
}

int cDvbDevice::SignalStrength(void) const
{
  return dvbTuner ? dvbTuner->GetSignalStrength() : -1;
}

int cDvbDevice::SignalQuality(void) const
{
  return dvbTuner ? dvbTuner->GetSignalQuality() : -1;
}

const cChannel *cDvbDevice::GetCurrentlyTunedTransponder(void) const
{
  return dvbTuner ? dvbTuner->GetTransponder() : NULL;
}

bool cDvbDevice::IsTunedToTransponder(const cChannel *Channel)
{
  return dvbTuner ? dvbTuner->IsTunedTo(Channel) : false;
}

bool cDvbDevice::SetChannelDevice(const cChannel *Channel, bool LiveView)
{
  if (dvbTuner)
     dvbTuner->Set(Channel);
#ifdef USE_LNBSHARE
  cDvbTransponderParameters dtp(Channel->Parameters());

  if (Channel->Frequency() >= Setup.LnbSLOF) {
     lnbState = 1;
  } else {
     lnbState = 0;
  }
  if (dtp.Polarization() == 'v' || dtp.Polarization() == 'V') lnbState += 2;
  lnbSource = (int*) Diseqcs.Get(CardIndex() + 1, Channel->Source(), Channel->Frequency(), dtp.Polarization());
#endif /* LNBSHARE */
  return true;
}

bool cDvbDevice::HasLock(int TimeoutMs)
{
  return dvbTuner ? dvbTuner->Locked(TimeoutMs) : false;
}

#ifdef USE_ROTOR
bool cDvbDevice::SendDiseqcCmd(dvb_diseqc_master_cmd cmd)
{
  return dvbTuner->SendDiseqcCmd(cmd);
}
#endif /* ROTOR */

void cDvbDevice::SetTransferModeForDolbyDigital(int Mode)
{
  setTransferModeForDolbyDigital = Mode;
}

bool cDvbDevice::OpenDvr(void)
{
  CloseDvr();
  fd_dvr = DvbOpen(DEV_DVB_DVR, adapter, frontend, O_RDONLY | O_NONBLOCK, true);
  if (fd_dvr >= 0)
     tsBuffer = new cTSBuffer(fd_dvr, MEGABYTE(2), CardIndex() + 1);
  return fd_dvr >= 0;
}

void cDvbDevice::CloseDvr(void)
{
  if (fd_dvr >= 0) {
     delete tsBuffer;
     tsBuffer = NULL;
     close(fd_dvr);
     fd_dvr = -1;
     }
}

bool cDvbDevice::GetTSPacket(uchar *&Data)
{
  if (tsBuffer) {
     Data = tsBuffer->Get();
     return true;
     }
  return false;
}

#ifdef USE_LNBSHARE
void cDvbDevice::SetLnbNrFromSetup(void)
{
  lnbNr = Setup.CardUsesLnbNr[CardIndex()];
  isyslog("LNB-sharing: setting device %d to use LNB %d", CardIndex(), lnbNr);
}

bool cDvbDevice::IsShareLnb(const cDevice *Device)
{
  return this != Device && LnbNr() == Device->LnbNr();
};


bool cDvbDevice::IsLnbConflict(const cChannel *Channel)
{
  if(!cSource::IsSat(Channel->Source())) return false;  // no conflict if the new channel is not on sat
  if(!ProvidesSource(cSource::stSat)) return false;     // no conflict if this device is not on sat
//if(MaySwitchTransponder()) return false;              // no conflict if this transponder may be switched
  cDvbTransponderParameters dtp(Channel->Parameters());
  if (Setup.DiSEqC) {
    cDiseqc *diseqc;
    diseqc = Diseqcs.Get(CardIndex() + 1, Channel->Source(), Channel->Frequency(), dtp.Polarization() );
    if (LnbSource() != (int*) diseqc) return true;
    return false;
  } else
  {
    char requiredState;
    if (Channel->Frequency() >= Setup.LnbSLOF) {
      requiredState = 1 ;
    } else {
      requiredState = 0;
    }
    if (dtp.Polarization() == 'v' || dtp.Polarization() == 'V') requiredState += 2;
    if(lnbState != requiredState) return true;
    return false;
  }
}
#endif /* LNBSHARE */

// --- cDvbDeviceProbe -------------------------------------------------------

cList<cDvbDeviceProbe> DvbDeviceProbes;

cDvbDeviceProbe::cDvbDeviceProbe(void)
{
  DvbDeviceProbes.Add(this);
}

cDvbDeviceProbe::~cDvbDeviceProbe()
{
  DvbDeviceProbes.Del(this, false);
}

uint32_t cDvbDeviceProbe::GetSubsystemId(int Adapter, int Frontend)
{
  cString FileName;
  cReadLine ReadLine;
  FILE *f = NULL;
  uint32_t SubsystemId = 0;
  FileName = cString::sprintf("/sys/class/dvb/dvb%d.frontend%d/device/subsystem_vendor", Adapter, Frontend);
  if ((f = fopen(FileName, "r")) != NULL) {
     if (char *s = ReadLine.Read(f))
        SubsystemId = strtoul(s, NULL, 0) << 16;
     fclose(f);
     }
  FileName = cString::sprintf("/sys/class/dvb/dvb%d.frontend%d/device/subsystem_device", Adapter, Frontend);
  if ((f = fopen(FileName, "r")) != NULL) {
     if (char *s = ReadLine.Read(f))
        SubsystemId |= strtoul(s, NULL, 0);
     fclose(f);
     }
  return SubsystemId;
}

