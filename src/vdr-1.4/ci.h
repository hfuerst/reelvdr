/*
 * ci.h: Common Interface
 *
 * See the main source file 'vdr.c' for copyright information and
 * how to reach the author.
 *
 * $Id: ci.h 1.22 2006/08/12 09:43:31 kls Exp $
 */

#ifndef __CI_H
#define __CI_H

#include <stdint.h>
#include <stdio.h>
#include "thread.h"
#include "tools.h"
#include "channels.h"

class cCiMMI;

class cCiMenu {
  friend class cCiHandler;
  friend class cCiMMI;
private:
  enum { MAX_CIMENU_ENTRIES = 64 }; ///< XXX is there a specified maximum?
  cCiMMI *mmi;
  cMutex *mutex;
  bool selectable;
  char *titleText;
  char *subTitleText;
  char *bottomText;
  char *entries[MAX_CIMENU_ENTRIES];
  int numEntries;
  bool AddEntry(char *s);
  cCiMenu(cCiMMI *MMI, bool Selectable);
public:
  ~cCiMenu();
  const char *TitleText(void) { return titleText; }
  const char *SubTitleText(void) { return subTitleText; }
  const char *BottomText(void) { return bottomText; }
  const char *Entry(int n) { return n < numEntries ? entries[n] : NULL; }
  int NumEntries(void) { return numEntries; }
  bool Selectable(void) { return selectable; }
  bool Select(int Index);
  bool Cancel(void);
  bool Abort(void);
  bool HasUpdate(void);
  };

class cCiEnquiry {
  friend class cCiHandler;
  friend class cCiMMI;
private:
  cCiMMI *mmi;
  cMutex *mutex;
  char *text;
  bool blind;
  int expectedLength;
  cCiEnquiry(cCiMMI *MMI);
public:
  ~cCiEnquiry();
  const char *Text(void) { return text; }
  bool Blind(void) { return blind; }
  int ExpectedLength(void) { return expectedLength; }
  bool Reply(const char *s);
  bool Cancel(void);
  bool Abort(void);
  };

#define MAX_CI_SESSION  16 //XXX
#ifdef RBLITE
#define MAX_CI_SLOT     4
#else
#define MAX_CI_SLOT     16
#endif

class cCiCaPidData : public cListObject {
public:
  bool active;
  int pid;
  int streamType;
  cCiCaPidData(int Pid, int StreamType)
  {
    active = false;
    pid = Pid;
    streamType = StreamType;
  }
  };

class cCiCaProgramData : public cListObject {
public:
  int programNumber;
#ifndef RBLITE
  bool modified;
#endif
  cList<cCiCaPidData> pidList;
  cCiCaProgramData(int ProgramNumber)
  {
    programNumber = ProgramNumber;
#ifndef RBLITE
    modified = true;
#endif
  }
  };

class cCiSession;
class cCiTransportLayer;
class cCiTransportConnection;

class cCiHandler {
private:
  cMutex mutex;
  int fd;
  int numSlots;
  bool newCaSupport;
  bool hasUserIO;
  cCiSession *sessions[MAX_CI_SESSION];
  cCiTransportLayer *tpl;
  cCiTransportConnection *tc;
#if defined(RBLITE) || defined(CAM_NEW)
  int source[MAX_CI_SLOT];
  int transponder[MAX_CI_SLOT];
  cChannel *channel[MAX_CI_SLOT];
  cList<cCiCaProgramData> caProgramList[MAX_CI_SLOT];
#else
  int source;
  int transponder;
  cList<cCiCaProgramData> caProgramList;
#endif
  uint32_t ResourceIdToInt(const uint8_t *Data);
  bool Send(uint8_t Tag, uint16_t SessionId, uint32_t ResourceId = 0, int Status = -1);
#if !defined(RBLITE) && !defined(CAM_NEW)
  const unsigned short *GetCaSystemIds(int Slot);
#endif
  cCiSession *GetSessionBySessionId(uint16_t SessionId);
  cCiSession *CreateSession(uint32_t ResourceId);
  bool OpenSession(int Length, const uint8_t *Data);
  bool CloseSession(uint16_t SessionId);
#if !defined(RBLITE) && !defined(CAM_NEW)
  int CloseAllSessions(int Slot);
#endif
  cCiHandler(int Fd, int NumSlots);
  void SendCaPmt(void);
public:
  cCiHandler();
  ~cCiHandler();
  static cCiHandler *CreateCiHandler(int fd_ca);
  static cCiHandler *CreateCiHandler(const char *FileName);
  cCiSession *GetSessionByResourceId(uint32_t ResourceId, int Slot);
  bool moduleReady[MAX_CI_SLOT];

       ///< Creates a new cCiHandler for the given CA device.
  int NumSlots(void) { return numSlots; }
       ///< Returns the number of CAM slots provided by this CA device.
  int NumCams(void);
       ///< Returns the number of actual CAMs inserted into this CA device.
  bool Ready(void);
       ///< Returns true if all CAMs in this CA device are ready.
  bool Process(int Slot = -1);
       ///< Processes the given Slot. If Slot is -1, all slots are processed.
       ///< Returns false in case of an error.
  bool HasUserIO(void) { return hasUserIO; }
       ///< Returns true if there is a pending user interaction, which shall
       ///< be retrieved via GetMenu() or GetEnquiry().
  bool EnterMenu(int Slot);
       ///< Requests the CAM in the given Slot to start its menu.
  cCiMenu *GetMenu(void);
       ///< Gets a pending menu, or NULL if there is no menu.
  cCiEnquiry *GetEnquiry(void);
       ///< Gets a pending enquiry, or NULL if there is no enquiry.
  const char *GetCamName(int Slot);
       ///< Returns the name of the CAM in the given Slot, or NULL if there
       ///< is no CAM in that slot.
#if defined(RBLITE) || defined(CAM_NEW)
  const unsigned short *GetCaSystemIds(int Slot);
#endif
  bool ProvidesCa(const unsigned short *CaSystemIds); //XXX Slot???
       ///< Returns true if any of the CAMs can provide one of the given
       ///< CaSystemIds. This doesn't necessarily mean that it will be
       ///< possible to actually decrypt such a programme, since CAMs
       ///< usually advertise several CA system ids, while the actual
       ///< decryption is controlled by the smart card inserted into
       ///< the CAM.
#if defined(RBLITE) || defined(CAM_NEW)
  void SetSource(int Source, int Transponder, int Slot, const cChannel *chan);
#endif
  void SetSource(int Source, int Transponder);
       ///< Sets the Source and Transponder of the device this cCiHandler is
       ///< currently tuned to. If Source or Transponder are different than
       ///< what was given in a previous call to SetSource(), any previously
       ///< added PIDs will be cleared.
#if defined(RBLITE) || defined(CAM_NEW)
  void AddPid(int ProgramNumber, int Pid, int StreamType, int Slot);
#else
  void AddPid(int ProgramNumber, int Pid, int StreamType);
#endif
       ///< Adds the given PID information to the list of PIDs. A later call
       ///< to SetPid() will (de)activate one of these entries.
#if defined(RBLITE) || defined(CAM_NEW)
  void SetPid(int Pid, bool Active, int Slot);
#else
  void SetPid(int Pid, bool Active);
#endif
       ///< Sets the given Pid (which has previously been added through a
       ///< call to AddPid()) to Active. A later call to StartDecrypting() will
       ///< send the full list of currently active CA_PMT entries to the CAM.
  bool CanDecrypt(int ProgramNumber);
       ///< XXX
       ///< Returns true if there is a CAM in this CA device that is able
       ///< to decrypt the programme with the given ProgramNumber. The PIDs
       ///< for this ProgramNumber must have been set through previous calls
       ///< to SetPid().
  void StartDecrypting(void);
       ///< Triggers sending all currently active CA_PMT entries to the CAM,
       ///< so that it will start decrypting.
  bool Reset(int Slot);
#if defined(RBLITE) || defined(CAM_NEW)
  int CloseAllSessions(int Slot);
  int GetCaFd(void);
#endif
  };

#endif //__CI_H
