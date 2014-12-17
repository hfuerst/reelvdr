/*
 * GraphLCD driver library
 *
 * drivers.h  -  global driver constants and functions
 *
 * This file is released under the GNU General Public License. Refer
 * to the COPYING file distributed with this package.
 *
 * (c) 2004 Andreas Regel <andreas.regel AT powarman.de>
 */

#ifndef _GLCDDRIVERS_DRIVERS_H_
#define _GLCDDRIVERS_DRIVERS_H_

#include <string>


namespace GLCD
{

class cDriverConfig;
class cDriver;

enum eDriver
{
	kDriverUnknown       = 0,
	kDriverSimLCD        = 1,
	kDriverGU140X32F     = 2,
	kDriverGU256X64_372  = 3,
	kDriverGU256X64_3900 = 4,
	kDriverHD61830       = 5,
	kDriverKS0108        = 6,
	kDriverSED1330       = 7,
	kDriverSED1520       = 8,
	kDriverT6963C        = 9,
	kDriverFramebuffer   = 10,
	kDriverImage         = 11,
	kDriverNoritake800   = 12,
	kDriverAvrCtl        = 13,
	kDriverST7565R	     = 14,
	kDriverReelUSBFP    = 15,
	kDriverSerDisp       = 100
};

struct tDriver
{
	std::string name;
	eDriver id;
};

tDriver * GetAvailableDrivers(int & count);
int GetDriverID(const std::string & driver);
cDriver * CreateDriver(int driverID, cDriverConfig * config);

} // end of namespace

#endif
