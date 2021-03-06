/*
 * webbrowser.c: A plugin for the Video Disk Recorder
 *
 * See the README file for copyright information and how to reach the author.
 *
 * $Id$
 */

#include <vdr/plugin.h>

static const char *VERSION = "0.0.3";
static const char *DESCRIPTION = "A plugin that can start various webbrowsers";

#define MODE_INVALID  -1
#define MODE_FIREFOX  0
#define MODE_X11      1
#define MODE_LINKS    2
#define MODE_SNES     3
#define MODE_CHROME   4
#define MODE_LAST     5

class cPluginWebbrowser:public cPlugin
{
  private:
    // Add any member variables or functions you may need here.
  public:
    cPluginWebbrowser(void);
      virtual ~ cPluginWebbrowser();
    virtual const char *Version(void)
    {
        return VERSION;
    }
    virtual const char *Description(void)
    {
        return DESCRIPTION;
    }
    virtual const char *CommandLineHelp(void);
    virtual bool ProcessArgs(int argc, char *argv[]);
    virtual bool Initialize(void);
    virtual bool Start(void);
    virtual void Stop(void);
    virtual void Housekeeping(void);
    virtual void MainThreadHook(void);
    virtual cString Active(void);
    virtual const char *MainMenuEntry(void);
    virtual cOsdObject *MainMenuAction(void);
    virtual cMenuSetupPage *SetupMenu(void);
    virtual bool SetupParse(const char *Name, const char *Value);
    virtual bool Service(const char *Id, void *Data = NULL);
    virtual const char **SVDRPHelpPages(void);
    virtual cString SVDRPCommand(const char *Command, const char *Option, int &ReplyCode);
    virtual const char *MenuSetupPluginEntry(void);
};
