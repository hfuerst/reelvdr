/**
 *  GraphLCD plugin for the Video Disk Recorder 
 *
 *  bmp.h  -  bmp logo class
 *
 *  (C) 2004 Andreas Brachold <vdr04 AT deltab de>
 *  (C) 2001-2004 Carsten Siebholz <c.siebholz AT t-online de>
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

#ifndef _BMP_H_
#define _BMP_H_

#include "glcd.h"

class cBMP : public cGraphLCDLogoExt 
{
public:
  cBMP();
  virtual ~cBMP();
  cBMP(const cGraphLCDLogoExt& x);
  virtual bool Load(const char * fileName, bool bInvert);
  virtual bool Save(const char * fileName);
  virtual bool CanMergeImage() const { return false; }
};

#endif
