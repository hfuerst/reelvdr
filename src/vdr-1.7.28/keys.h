/*
 * keys.h: Remote control Key handling
 *
 * See the main source file 'vdr.c' for copyright information and
 * how to reach the author.
 *
 * $Id: keys.h 2.1 2010/04/05 10:06:04 kls Exp $
 */

#ifndef __KEYS_H
#define __KEYS_H

#include "config.h"
#include "tools.h"

enum eKeys { // "Up" and "Down" must be the first two keys!
             kUp,
             kDown,
             kMenu,
             kOk,
             kBack,
             kLeft,
             kRight,
             kRed,
             kGreen,
             kYellow,
             kBlue,   //10
             k0, k1, k2, k3, k4, k5, k6, k7, k8, k9,
             kInfo,   // 21
             kPlay,
             kPause,
             kStop,
             kRecord,
             kFastFwd,
             kFastRew,
             kNext,
             kPrev,
             kPower, //30
             kChanUp,
             kChanDn,
             kChanPrev,
             kVolUp,
             kVolDn,
             kMute,
             kAudio,
             kSubtitles,
             kSchedule,
             kChannels,  //40
             kTimers,
             kRecordings,
             kSetup,
             kCommands,
#ifdef REELVDR
             kGreater, kLess, k2digit,
             kDVD, kDVB, kPVR, kReel, //51
             kTT, kPiP,
             kHelp, kEject, kAspect, kSearch, //57
             kSearchtimers, kInternet, kGuide, kMultimedia, kRadio, // 63
             kHeart,
             kFavourites, //65
             kAddFavorite,
#endif /* REELVDR */
             kUser0, kUser1, kUser2, kUser3, kUser4, kUser5, kUser6, kUser7, kUser8, kUser9,
             kNone,
             kKbd,   //77
             // The following codes are used internally:
             k_Plugin,
             k_Setup,
             // The following flags are OR'd with the above codes:
             k_Repeat  = 0x8000,
             k_Release = 0x4000,
             k_Flags   = k_Repeat | k_Release,
           };

// This is in preparation for having more key codes:
#define kMarkToggle      k0
#define kMarkMoveBack    k4
#define kMarkMoveForward k6
#define kMarkJumpBack    k7
#define kMarkJumpForward k9
#define kEditCut         k2
#define kEditTest        k8

#define RAWKEY(k)        (eKeys((k) & ~k_Flags))
#define ISRAWKEY(k)      ((k) != kNone && ((k) & k_Flags) == 0)
#define NORMALKEY(k)     (eKeys((k) & ~k_Repeat))
#define ISMODELESSKEY(k) (RAWKEY(k) > k9)
#define ISREALKEY(k)     (k != kNone && k != k_Plugin)

#define BASICKEY(k)      (eKeys((k) & 0xFFFF))
#define KBDKEY(k)        (eKeys(((k) << 16) | kKbd))
#define KEYKBD(k)        (((k) >> 16) & 0xFFFF)

struct tKey {
  eKeys type;
  const char *name;
  };

class cKey : public cListObject {
private:
  char *remote;
  char *code;
  eKeys key;
public:
  cKey(void);
  cKey(const char *Remote, const char *Code, eKeys Key);
  ~cKey();
  const char *Remote(void) { return remote; }
  const char *Code(void) { return code; }
  eKeys Key(void) { return key; }
  bool Parse(char *s);
  bool Save(FILE *f);
  static eKeys FromString(const char *Name);
  static const char *ToString(eKeys Key, bool Translate = false);
  };

class cKeys : public cConfig<cKey> {
public:
  bool KnowsRemote(const char *Remote);
  eKeys Get(const char *Remote, const char *Code);
  const char *GetSetup(const char *Remote);
  void PutSetup(const char *Remote, const char *Setup);
  };

extern cKeys Keys;

#define MAXKEYSINMACRO 16

class cKeyMacro : public cListObject {
private:
  eKeys macro[MAXKEYSINMACRO];
  int numKeys;
  char *plugin;
#ifdef REELVDR
  char *command;
#endif
public:
  cKeyMacro(void);
  ~cKeyMacro();
  bool Parse(char *s);
  int NumKeys(void) const { return numKeys; }
      ///< Returns the number of keys in this macro. The first key (with
      ///< index 0) is the macro code. The actual macro expansion codes
      ///< start at index 1 and go to NumKeys() - 1.
  const eKeys *Macro(void) const { return macro; }
  const char *Plugin(void) const { return plugin; }
#ifdef REELVDR
  const char *Command(void) const { return command; }
#endif
  };

class cKeyMacros : public cConfig<cKeyMacro> {
public:
  const cKeyMacro *Get(eKeys Key);
  };

extern cKeyMacros KeyMacros;

#endif //__KEYS_H
