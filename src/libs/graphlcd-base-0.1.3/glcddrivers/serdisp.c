/*
 * GraphLCD driver library
 *
 * serdisp.h  -  include support for displays supported by serdisplib (if library is installed)
 *               http://serdisplib.sourceforge.net
 *
 * This file is released under the GNU General Public License. Refer
 * to the COPYING file distributed with this package.
 *
 * (c) 2003-2005 Wolfgang Astleitner <mrwastl AT users.sourceforge.net>
 */

#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <dlfcn.h>

#include "common.h"
#include "config.h"
#include "serdisp.h"

#define SERDISP_VERSION(a,b) ((long)(((a) << 8) + (b)))
#define SERDISP_VERSION_GET_MAJOR(_c)  ((int)( (_c) >> 8 ))
#define SERDISP_VERSION_GET_MINOR(_c)  ((int)( (_c) & 0xFF ))

// taken from serdisp_control.h
#define FEATURE_CONTRAST  0x01
#define FEATURE_REVERSE   0x02
#define FEATURE_BACKLIGHT 0x03
#define FEATURE_ROTATE    0x04

#define SD_COL_BLACK      0xFF000000

namespace GLCD
{

cDriverSerDisp::cDriverSerDisp(cDriverConfig * config)
: config(config)
{
  oldConfig = new cDriverConfig(*config);

  dd = (void *) NULL;
}

cDriverSerDisp::~cDriverSerDisp(void)
{
  delete oldConfig;
}

int cDriverSerDisp::Init(void)
{
  char* errmsg; // error message returned by dlerror()

  std::string controller;
  std::string optionstring = "";
  std::string wiringstring;


  // dynamically load serdisplib using dlopen() & co.

  sdhnd = dlopen("libserdisp.so", RTLD_LAZY);
  if(!sdhnd) {  // try /usr/local/lib
    sdhnd = dlopen("/usr/local/lib/libserdisp.so", RTLD_LAZY);
  }

  if(!sdhnd) { // serdisplib seems not to be installed
    syslog(LOG_ERR, "%s: error: unable to dynamically load library '%s'. Err: %s (cDriver::Init)\n",
      config->name.c_str(), "libserdisp.so", "not found");
    return -1;
  }
    
  dlerror(); // clear error code

  /* pre-init some flags, function pointers, ... */
  supports_options = 0;
  fg_colour = 1;

  // get serdisp version
  fp_serdisp_getversioncode = (long int (*)()) dlsym(sdhnd, "serdisp_getversioncode");

  if (dlerror()) { // no serdisp_getversioncode() -> version of serdisplib is < 1.95
    syslog(LOG_DEBUG, "%s: INFO: symbol serdisp_getversioncode unknown: autodetecting pre 1.95 serdisplib version (cDriver::Init)\n", 
      config->name.c_str());

    fp_SDCONN_open = (void*(*)(const char*)) dlsym(sdhnd, "SDCONN_open");
    if (dlerror()) { // no SDCONN_open() -> version of serdisplib is < 1.93
      serdisp_version = SERDISP_VERSION(1,92);
      syslog(LOG_DEBUG, "%s: INFO: detected serdisplib version <= 1.92 (cDriver::Init)\n", config->name.c_str());

      fp_PP_open = (void*(*)(const char*))dlsym(sdhnd, "PP_open");
      if ( (errmsg = dlerror()) != NULL  ) { // should not happen
        syslog(LOG_ERR, "%s: error: cannot load symbol %s. Err:%s (cDriver::Init)\n",
          config->name.c_str(), "PP_open", errmsg);
        return -1;
      }
      fp_PP_close = (void*(*)(void*))dlsym(sdhnd, "PP_close");
      if ( (errmsg = dlerror()) != NULL  ) { // should not happen
        syslog(LOG_ERR, "%s: error: cannot load symbol %s. Err:%s (cDriver::Init)\n",
          config->name.c_str(), "PP_close", errmsg);
        return -1;
      }
      fp_serdisp_close = (void (*)(void*))dlsym(sdhnd, "serdisp_close");
      if ( (errmsg = dlerror()) != NULL  ) { // should not happen
        syslog(LOG_ERR, "%s: error: cannot load symbol %s. Err:%s (cDriver::Init)\n",
          config->name.c_str(), "serdisp_close", errmsg);
        return -1;
      }
    } else {
      serdisp_version = SERDISP_VERSION(1,94);  // no serdisp_getversioncode, but SDCONN_open: 1.93 or 1.94
      syslog(LOG_DEBUG, "%s: INFO: detected serdisplib version 1.93 or 1.94 (cDriver::Init)\n", config->name.c_str());

      fp_serdisp_quit = (void (*)(void*)) dlsym(sdhnd, "serdisp_quit");
      if ( (errmsg = dlerror()) != NULL  ) { // should not happen
        syslog(LOG_ERR, "%s: error: cannot load symbol %s. Err:%s (cDriver::Init)\n",
          config->name.c_str(), "serdisp_quit", errmsg);
        return -1;
      }
    }

    fp_serdisp_setpixcol = (void (*)(void*, int, int, long int)) dlsym(sdhnd, "serdisp_setpixel");
    if ( (errmsg = dlerror()) != NULL  ) { // should not happen
      syslog(LOG_ERR, "%s: error: cannot load symbol %s. Err:%s (cDriver::Init)\n",
        config->name.c_str(), "serdisp_setpixel", errmsg);
      return -1;
    }
    fg_colour = 1; /* set foreground to 'pixel on' */

  } else {  // serdisp version >= 1.95
    serdisp_version = fp_serdisp_getversioncode();
    syslog(LOG_DEBUG, "%s: INFO: detected serdisplib version %d.%d (cDriver::Init)\n", 
      config->name.c_str(), SERDISP_VERSION_GET_MAJOR(serdisp_version), SERDISP_VERSION_GET_MINOR(serdisp_version));


    fp_SDCONN_open = (void*(*)(const char*)) dlsym(sdhnd, "SDCONN_open");
    if ( (errmsg = dlerror()) != NULL  ) { // should not happen
      syslog(LOG_ERR, "%s: error: cannot load symbol %s. Err:%s (cDriver::Init)\n",
        config->name.c_str(), "SDCONN_open", errmsg);
      return -1;
    }
    fp_serdisp_quit = (void (*)(void*)) dlsym(sdhnd, "serdisp_quit");
    if ( (errmsg = dlerror()) != NULL  ) { // should not happen
      syslog(LOG_ERR, "%s: error: cannot load symbol %s. Err:%s (cDriver::Init)\n",
        config->name.c_str(), "serdisp_quit", errmsg);
      return -1;
    }
    fp_serdisp_setpixcol = (void (*)(void*, int, int, long int)) dlsym(sdhnd, "serdisp_setcolour");
    if ( (errmsg = dlerror()) != NULL  ) { // should not happen
      syslog(LOG_ERR, "%s: error: cannot load symbol %s. Err:%s (cDriver::Init)\n",
        config->name.c_str(), "serdisp_setcolour", errmsg);
      return -1;
    }
    fg_colour = SD_COL_BLACK; /* set foreground colour to black */

    if (serdisp_version >= SERDISP_VERSION(1,96) ) {
      supports_options = 1;

      fp_serdisp_isoption = (int (*)(void*, const char*)) dlsym(sdhnd, "serdisp_isoption");
      if ( (errmsg = dlerror()) != NULL  ) { // should not happen
        syslog(LOG_ERR, "%s: error: cannot load symbol %s. Err:%s (cDriver::Init)\n",
          config->name.c_str(), "serdisp_isoption", errmsg);
        return -1;
      }
      fp_serdisp_setoption = (void (*)(void*, const char*, long int)) dlsym(sdhnd, "serdisp_setoption");
      if ( (errmsg = dlerror()) != NULL  ) { // should not happen
        syslog(LOG_ERR, "%s: error: cannot load symbol %s. Err:%s (cDriver::Init)\n",
          config->name.c_str(), "serdisp_setoption", errmsg);
        return -1;
      }
    } /* >= 1.96 */
  }

  // load other symbols that will be required
  fp_serdisp_init = (void*(*)(void*, const char*, const char*)) dlsym(sdhnd, "serdisp_init");
  if ( (errmsg = dlerror()) != NULL  ) { // should not happen
    syslog(LOG_ERR, "%s: error: cannot load symbol %s. Err:%s (cDriver::Init)\n",
      config->name.c_str(), "serdisp_init", errmsg);
    return -1;
  }

  fp_serdisp_rewrite = (void (*)(void*)) dlsym(sdhnd, "serdisp_rewrite");
  if ( (errmsg = dlerror()) != NULL  ) { // should not happen
    syslog(LOG_ERR, "%s: error: cannot load symbol %s. Err:%s (cDriver::Init)\n",
      config->name.c_str(), "serdisp_rewrite", errmsg);
    return -1;
  }

  fp_serdisp_update = (void (*)(void*)) dlsym(sdhnd, "serdisp_update");
  if ( (errmsg = dlerror()) != NULL  ) { // should not happen
    syslog(LOG_ERR, "%s: error: cannot load symbol %s. Err:%s (cDriver::Init)\n",
      config->name.c_str(), "serdisp_update", errmsg);
    return -1;
  }

  fp_serdisp_clearbuffer = (void (*)(void*)) dlsym(sdhnd, "serdisp_clearbuffer");
  if ( (errmsg = dlerror()) != NULL  ) { // should not happen
    syslog(LOG_ERR, "%s: error: cannot load symbol %s. Err:%s (cDriver::Init)\n",
      config->name.c_str(), "serdisp_clearbuffer", errmsg);
    return -1;
  }

  fp_serdisp_feature = (int (*)(void*, int, int)) dlsym(sdhnd, "serdisp_feature");
  if ( (errmsg = dlerror()) != NULL  ) { // should not happen
    syslog(LOG_ERR, "%s: error: cannot load symbol %s. Err:%s (cDriver::Init)\n",
      config->name.c_str(), "serdisp_feature", errmsg);
    return -1;
  }

  fp_serdisp_getwidth = (int (*)(void*)) dlsym(sdhnd, "serdisp_getwidth");
  if ( (errmsg = dlerror()) != NULL  ) { // should not happen
    syslog(LOG_ERR, "%s: error: cannot load symbol %s. Err:%s (cDriver::Init)\n",
      config->name.c_str(), "serdisp_getwidth", errmsg);
    return -1;
  }

  fp_serdisp_getheight = (int (*)(void*)) dlsym(sdhnd, "serdisp_getheight");
  if ( (errmsg = dlerror()) != NULL  ) { // should not happen
    syslog(LOG_ERR, "%s: error: cannot load symbol %s. Err:%s (cDriver::Init)\n",
      config->name.c_str(), "serdisp_getheight", errmsg);
    return -1;
  }

  // done loading all required symbols


  // setting up the display 
  width = 0;
  height = 0;

  for (unsigned int i = 0; i < config->options.size(); i++)
  {
    if (config->options[i].name == "Controller") {
      controller = config->options[i].value;
    } else if (config->options[i].name == "Options") {
      optionstring = config->options[i].value;
    } else if (config->options[i].name == "Wiring") {
      wiringstring = config->options[i].value;
    }
  }

  if (wiringstring.length()) {
    optionstring = "WIRING=" + wiringstring + ((optionstring != "") ? ";" + optionstring : "");
  }

  if (controller == "")
  {
    syslog(LOG_ERR, "%s error: no controller given!\n", config->name.c_str());
    return -1;
  }


  if (config->device == "")
  {
    // use DirectIO

    // neither device nor port is set
    if (config->port == 0)
      return -1;

    char temp[10];
    snprintf(temp, 8, "0x%x", config->port);

    if (serdisp_version < SERDISP_VERSION(1,93) ) {
      sdcd = fp_PP_open(temp);
    } else {
      sdcd = fp_SDCONN_open(temp);
    }

    if (sdcd == 0)
      return -1;

    uSleep(10);
  }
  else
  {
    // use ppdev
    if (serdisp_version < SERDISP_VERSION(1,93) ) {
      sdcd = fp_PP_open(config->device.c_str());
    } else {
      sdcd = fp_SDCONN_open(config->device.c_str());
    }

    if (sdcd == 0)
      return -1;
  }

  if (serdisp_version < SERDISP_VERSION(1,95) )
    dd = fp_serdisp_init(sdcd, controller.c_str(), "");
  else
    dd = fp_serdisp_init(sdcd, controller.c_str(), optionstring.c_str());

  if (!dd)
  {
    syslog(LOG_ERR, "%s: error: cannot open display %s. Err:%s (cDriver::Init)\n",
        config->name.c_str(), controller.c_str(), "no handle");
    return -1;
  }

  width = config->width;
  if (width <= 0)
    width = fp_serdisp_getwidth(dd);
  height = config->height;
  if (height <= 0)
    height = fp_serdisp_getheight(dd);

  if (serdisp_version < SERDISP_VERSION(1,96) ) {
    fp_serdisp_feature(dd, FEATURE_ROTATE, config->upsideDown);
    fp_serdisp_feature(dd, FEATURE_CONTRAST, config->contrast);
    fp_serdisp_feature(dd, FEATURE_BACKLIGHT, config->backlight);
    fp_serdisp_feature(dd, FEATURE_REVERSE, config->invert);
  } else {
    /* standard options */
    fp_serdisp_setoption(dd, "ROTATE", config->upsideDown);
    fp_serdisp_setoption(dd, "CONTRAST", config->contrast);
    fp_serdisp_setoption(dd, "BACKLIGHT", config->backlight);
    fp_serdisp_setoption(dd, "INVERT", config->invert);

    /* driver dependend options */
    for (unsigned int i = 0; i < config->options.size(); i++) {
      std::string optionname = config->options[i].name;
      if (optionname != "UpsideDown" && optionname != "Contrast" && 
          optionname != "Backlight" && optionname != "Invert") {

        if ( fp_serdisp_isoption(dd, optionname.c_str()) == 1 )  /* if == 1: option is existing AND r/w */
          fp_serdisp_setoption(dd, optionname.c_str(), strtol(config->options[i].value.c_str(), NULL, 0));
      }
    }

  }

  *oldConfig = *config;

  // clear display
  Clear();
  
  syslog(LOG_INFO, "%s: SerDisp with %s initialized.\n", config->name.c_str(), controller.c_str());
  return 0;
}

int cDriverSerDisp::DeInit(void)
{
  if (serdisp_version < SERDISP_VERSION(1,93) ) {
    fp_serdisp_close(dd);
    fp_PP_close(sdcd);
    sdcd = NULL;
  } else {
    fp_serdisp_quit(dd);
  }
  (int) dlclose(sdhnd);
  sdhnd = NULL;

  return 0;
}

int cDriverSerDisp::CheckSetup()
{
  bool update = false;

  if (config->device != oldConfig->device ||
      config->port != oldConfig->port ||
      config->width != oldConfig->width ||
      config->height != oldConfig->height)
  {
    DeInit();
    Init();
    return 0;
  }

  if (config->contrast != oldConfig->contrast)
  {
    fp_serdisp_feature(dd, FEATURE_CONTRAST, config->contrast);
    oldConfig->contrast = config->contrast;
    update = true;
  }
  if (config->backlight != oldConfig->backlight)
  {
    fp_serdisp_feature(dd, FEATURE_BACKLIGHT, config->backlight);
    oldConfig->backlight = config->backlight;
    update = true;
  }
  if (config->upsideDown != oldConfig->upsideDown)
  {
    fp_serdisp_feature(dd, FEATURE_ROTATE, config->upsideDown);
    oldConfig->upsideDown = config->upsideDown;
    update = true;
  }
  if (config->invert != oldConfig->invert)
  {
    fp_serdisp_feature(dd, FEATURE_REVERSE, config->invert);
    oldConfig->invert = config->invert;
    update = true;
  }

  /* driver dependend options */
   for (unsigned int i = 0; i < config->options.size(); i++) {
     std::string optionname = config->options[i].name;
     if (optionname != "UpsideDown" && optionname != "Contrast" && 
         optionname != "Backlight" && optionname != "Invert") {

       if ( fp_serdisp_isoption(dd, optionname.c_str()) == 1 )  /* if == 1: option is existing AND r/w */
         fp_serdisp_setoption(dd, optionname.c_str(), strtol(config->options[i].value.c_str(), NULL, 0));
         oldConfig->options[i] = config->options[i];
         update = true;
     }
   }


  if (update)
    return 1;
  return 0;
}

void cDriverSerDisp::Clear(void)
{
  fp_serdisp_clearbuffer(dd);
}

void cDriverSerDisp::Set8Pixels(int x, int y, unsigned char data) {
  int i, start;

  data = ReverseBits(data);

  start = (x >> 3) << 3;

  for (i = 0; i < 8; i++) {
    if (data & (1 << i))
      fp_serdisp_setpixcol(dd, start + i, y, fg_colour);   /* >= 1.95: serdisp_setcolour(), < 1.95: serdisp_setpixel() */
  }
}

void cDriverSerDisp::Refresh(bool refreshAll)
{
  if (CheckSetup() == 1)
    refreshAll = true;

  if (refreshAll)
    fp_serdisp_rewrite(dd);
  else
    fp_serdisp_update(dd);
}

} // end of namespace
