/**
 *  GraphLCD plugin for the Video Disk Recorder 
 *
 *  st7565_reel.h - Plugin for ST7565 display on Reelbox
 *                  driven by an AVR on the front panel
 *
 *  (c) 2004 Georg Acher, BayCom GmbH, http://www.baycom.de
 *      based on simlcd by Carsten Siebholz
 **/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program;                                              *
 *   if not, write to the Free Software Foundation, Inc.,                  *
 *   59 Temple Place, Suite 330, Boston, MA  02111-1307  USA               *
 *                                                                         *
 ***************************************************************************/

#ifndef _LIBGRAPHLCD_ST7565_H_
#define _LIBGRAPHLCD_ST7565_H_

#include "driver.h"
#include "unistd.h"

namespace GLCD
{
class cDriverConfig;

class cDriverST7565R : public cDriver
{
private:
	int fd;
	unsigned char ** LCD;

	cDriverConfig * config;
        cDriverConfig * oldConfig;

	int CheckSetup(void);
	void display_cmd(unsigned char cmd);
	void display_data(unsigned char *data, int l);
	void set_displaymode(int m);
	void set_clock(void);
	void clear_display(void);
	
public:
	cDriverST7565R(cDriverConfig * setup);
	virtual ~cDriverST7565R();
	
	virtual int Init();
	virtual int DeInit();
	
	virtual void Clear();
	virtual void SetPixel(int x, int y);
	virtual void Set8Pixels(int x, int y, unsigned char data);
	virtual void Refresh(bool refreshAll = false);
	virtual void SetBrightness(unsigned int percent);
	virtual void SetContrast(unsigned int percent);
	
	
};

}

#endif

