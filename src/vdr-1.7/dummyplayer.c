#include "dummyplayer.h"



//------------- cDummyPlayer ---------------------

/* player does nothing 
 * useful when tuners need to be free
 */
cDummyPlayer::cDummyPlayer(ePlayMode PlayMode) : cPlayer(PlayMode) {
  printf("%s:%d\n", __PRETTY_FUNCTION__, __LINE__);
}

cDummyPlayer::~cDummyPlayer() {
  printf("%s:%d\n", __PRETTY_FUNCTION__, __LINE__);
}




//--------------------cDummyPlayerControl -------------
cDummyPlayerControl::cDummyPlayerControl(ePlayMode PlayMode) 
  : cControl(player=new cDummyPlayer (PlayMode)) {
    printf("%s:%d\n", __PRETTY_FUNCTION__, __LINE__);
}


cDummyPlayerControl::~cDummyPlayerControl() {
    printf("%s:%d\n", __PRETTY_FUNCTION__, __LINE__);
    printf("----------------   ~cDummyPlayerControl()   --------------------\n");
}


void cDummyPlayerControl::Hide() {
}


/* handles just kBack = end player
 **/
eOSState cDummyPlayerControl::ProcessKey(eKeys key) {
  
  eOSState state = osContinue;
  
  switch(key){
    
    case kBack:
	state = osEnd;
	break;
	
    default:
      break;
  } // switch
  
  return state;
}


