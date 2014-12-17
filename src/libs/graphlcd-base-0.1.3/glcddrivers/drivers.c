/*
 * GraphLCD driver library
 *
 * drivers.c  -  global driver constants and functions
 *
 * This file is released under the GNU General Public License. Refer
 * to the COPYING file distributed with this package.
 *
 * (c) 2004 Andreas Regel <andreas.regel AT powarman.de>
 */

#include <string.h>

#include "drivers.h"
#include "simlcd.h"
#include "gu140x32f.h"
#include "gu256x64-372.h"
#include "gu256x64-3900.h"
#include "hd61830.h"
#include "ks0108.h"
#include "sed1330.h"
#include "sed1520.h"
#include "t6963c.h"
#include "framebuffer.h"
#include "image.h"
#include "noritake800.h"
#include "avrctl.h"
#include "serdisp.h"
#include "st7565_reel.h"
#include "reel_usbfp.h"
namespace GLCD
{

tDriver drivers[] =
{
/*
	{"simlcd",        kDriverSimLCD},
	{"gu140x32f",     kDriverGU140X32F},
	{"gu256x64-372",  kDriverGU256X64_372},
	{"gu256x64-3900", kDriverGU256X64_3900},
	{"hd61830",       kDriverHD61830},
	{"ks0108",        kDriverKS0108},
	{"sed1330",       kDriverSED1330},
	{"sed1520",       kDriverSED1520},
	{"t6963c",        kDriverT6963C},
*/
	{"framebuffer",   kDriverFramebuffer},
	{"image",         kDriverImage},
/*
	{"noritake800",   kDriverNoritake800},
	{"avrctl",        kDriverAvrCtl},
	{"serdisp",       kDriverSerDisp},
*/	
	
	{"st7565r",	  kDriverST7565R},
	{"reel_usbfp",	  kDriverReelUSBFP},
	{"",              kDriverUnknown}
};

tDriver * GetAvailableDrivers(int & count)
{
	for (count = 0; drivers[count].name.length() > 0; count++)
		;
	return drivers;
}

int GetDriverID(const std::string & driver)
{
	for (int i = 0; drivers[i].name.length() > 0; i++)
		if (drivers[i].name == driver)
			return drivers[i].id;
	return kDriverUnknown;
}

cDriver * CreateDriver(int driverID, cDriverConfig * config)
{
	switch (driverID)
	{
/*
		case kDriverSimLCD       : return new cDriverSimLCD(config);
		case kDriverGU140X32F    : return new cDriverGU140X32F(config);
		case kDriverGU256X64_372 : return new cDriverGU256X64_372(config);
		case kDriverGU256X64_3900: return new cDriverGU256X64_3900(config);
		case kDriverHD61830      : return new cDriverHD61830(config);
		case kDriverKS0108       : return new cDriverKS0108(config);
		case kDriverSED1330      : return new cDriverSED1330(config);
		case kDriverSED1520      : return new cDriverSED1520(config);
		case kDriverT6963C       : return new cDriverT6963C(config);
*/
		case kDriverFramebuffer  : return new cDriverFramebuffer(config);
		case kDriverImage        : return new cDriverImage(config);
/*
		case kDriverNoritake800  : return new cDriverNoritake800(config);
		case kDriverAvrCtl       : return new cDriverAvrCtl(config);
		case kDriverSerDisp      : return new cDriverSerDisp(config);

*/		
		case kDriverST7565R      : return new cDriverST7565R(config);		
		case kDriverReelUSBFP    : return new cDriverReelUSBFP(config);		
		case kDriverUnknown      :
	        default                  : return NULL;
	}
}

} // end of namespace
