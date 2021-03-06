#ifndef __VDR_DUMMY_PLAYER_H
#define __VDR_DUMMY_PLAYER_H

#include "player.h"


/**
 * This player does NOTHING
 * Just exits when kBack is got
 */

class cDummyPlayer : public cPlayer {

public:
    cDummyPlayer(ePlayMode PlayMode = pmAudioVideo);
    virtual ~cDummyPlayer();
};

class cDummyPlayerControl : public cControl {
  private:
    cDummyPlayer *player;
    
  public:
    cDummyPlayerControl(ePlayMode PlayMode = pmAudioVideo);
    virtual ~cDummyPlayerControl();
    virtual void Hide();

    virtual eOSState ProcessKey(eKeys Key);
    ///< handles kBack = end player, else does nothing
};


#endif

