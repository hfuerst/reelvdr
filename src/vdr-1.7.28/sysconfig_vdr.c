#ifdef REELVDR
/****************************************************************************
 * DESCRIPTION:
 *             Handles sysconfig File
 *
 * $Id: sysconfig.cpp,v 1.4 2005/10/03 14:05:20 ralf Exp $
 *
 * Contact:    ranga@teddycats.de
 *
 * Copyright (C) 2004 by Ralf Dotzert
 ****************************************************************************/

#include <map>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "config.h"
#include "debug.h"
//#include "plugin.h"
#include "sysconfig_vdr.h"
//#include "util.h"

using std::pair;
using std::map;
using std::string;
using std::vector;

#if VDRVERSNUM >= 10716
cSysConfig_vdr* cSysConfig_vdr::instance_ = NULL;
#endif

#define MAXLENGTH 256

// ----- class cSysConfig_vdr ------------------------------------------------------

cSysConfig_vdr::cSysConfig_vdr()
{
}

cSysConfig_vdr &cSysConfig_vdr::GetInstance()
{
    if (!instance_) {
        Create();
        
        // load the sysconfig file
        instance_->Reload();
    }
    return *instance_;
}

void cSysConfig_vdr::Create()
{
    if (!instance_)
        instance_ = new cSysConfig_vdr;
}

void cSysConfig_vdr::Destroy()
{
    if (instance_)
    delete instance_;
    instance_ = NULL;
}

const char * cSysConfig_vdr::FileName() const
{
    return fileName_.c_str();
}

void cSysConfig_vdr::AddVariable(const char *key, char *value)
{
    if (key)
       sysMap_.insert(std::map < std::string, char *>::value_type(key, value));
}

void cSysConfig_vdr::SetVariable(const char *key, const char *value)
{
    //dsyslog(DBG_PREFIX " cSysConfig_vdr::SetVariable@%s: %s ",key ,value);
    if (!key) return;
    
    if (sysMap_[key]) 
    {
       free (sysMap_[key]);
       sysMap_[key] = NULL;
    }
    
    if (value)
        sysMap_[key] = strdup(value);
}

const char *cSysConfig_vdr::GetVariable(const char *key) const
{
    if (!key) return NULL;
    
    mapConstIter_t iter = sysMap_.find(key);

    if (iter != sysMap_.end())
        return iter->second;

    //printf (" cSysConfig_vdr::GetVariable(%s) not found. \n", key);
    return NULL;
}


cSysConfig_vdr::~cSysConfig_vdr()
{
    for (mapConstIter_t iter = sysMap_.begin(); iter != sysMap_.end(); ++iter)
    {
        if (iter->second) free(iter->second);
    }
}

bool cSysConfig_vdr::Reload()
{
    return Load(SYSCONFIGFNAME);
}


/**
 * @brief cSysConfig_vdr::SetVariable
 * @param key
 * @param value : New value for 
 * @param changed : increment 'changed' if sysconfig was modified
 *
 *---------------------------------------------------
 *  prev. Value      Given Value          changed?
 *---------------------------------------------------
 *      NULL           NULL                 0
 *      NULL           "..."                1
 *      "..."           NULL                1
 *      "..."          "..."              strcmp to find if they are the same
 */
void cSysConfig_vdr::SetVariable(const char *key, const char *value, int& changed)
{
    if(!key)
        return;
    
    // previous value for 'key'
    char* prevValue = sysMap_[key];
    
    /// No change to sysconfig ?
    // given and prev. 'values' both are NULL OR both are the same non-NULL string
    if ( (!prevValue && !value) 
         || (prevValue && value && strcmp(prevValue, value) == 0) )
        return;

    // discard old value for 'key'    
    if (prevValue) 
    {
        free(prevValue);
        sysMap_[key] = NULL;
    } // if
    
    // new 'value' for 'key'
    if (value)
        sysMap_[key] = strdup(value);
    // else sysMap_[key] remains NULL
    
    //sysconfig has changed
    changed++;
}


bool
cSysConfig_vdr::Load(const char *fname)
{
    if (!fname) {
        esyslog("(%s:%d) sysconfig filename cannot be null", __FILE__, __LINE__);
        return false;
    }
    
    int count = 0;
    const char *line;

    int fp = open(fname, O_RDONLY);

    // discard the old values in sysMap_ and load the new values from
    // given file.
    // AddLine() uses std::map::insert() which when a key is already available
    // does *NOT* change the corresponding value. So, first discard map
    // to get the latest key,value pairs from the given file
    sysMap_.clear();

    if (fp)
    {
        while ((line = ReadLine(fp)) != NULL)
        {
            AddLine(line);
            delete[]line;
            count++;
        }
        close(fp);
        
        fileName_ = fname;
    } 
    else 
    {
        esyslog("(%s:%d) cannot open sysconfig file '%s'", __FILE__, __LINE__, fname);
        return false;
    }
    
    return true;
}


/**
 * Save cSysConfig_vdr file
 * @return true on success
 */
bool
cSysConfig_vdr::Save()
{
    FILE *fp = fopen(fileName_.c_str(), "w");
    if (!fp)
    {
        DLOG("%s: Could not write file: %s, errno=%d\n", ERR,
             fileName_.c_str(), errno);
        return false;
    }

    fprintf(fp, "#\n"
            "# Generated by Setup-Plugin, \n"
            "# (c) 2005 by Ralf Dotzert and MiniVDR.de\n"
            "# (c) 2006-2012 by Reel-Multimedia http://www.reel-multimedia.com\n" "#\n\n");

    for (mapConstIter_t iter = sysMap_.begin(); iter != sysMap_.end(); ++iter)
    {
        if (!iter->first.empty() && iter->second != NULL)
        fprintf(fp, "%s=\"%s\"\n", iter->first.c_str(), iter->second);
    }
    fclose(fp);

    CopyToTftpRoot(fileName_.c_str());

    return true;
}

/**
 * read one line from opened file
 * @param fp opened filepointer
 * @return null if EOF or allocated character String holding one line
 */
const char *cSysConfig_vdr::ReadLine(int fd)
{
    char c;
    char buf[1024];
    int i = 0;
    int maxLen = static_cast < int >(sizeof(buf)) - 1;
    char *line = NULL;
    while (read(fd, &c, 1))
    {
        if (c == '\n' || i == maxLen)
        {
            line = new char[i + 1];
            strncpy(line, buf, i);
            line[i] = '\0';
            //dsyslog (DBG " cSysConfig_vdr readline %s ",line);
            return line;
        }
        else
            buf[i++] = c;
    }
    return line;
}

/**
 * Add the given line from sysconfig file an split it in Name an Variable
 * @param line allocated buffer holding one line
 */

void
cSysConfig_vdr::AddLine(const char *line)
{
    //dsyslog(DBG  "   AddLine   %s", line);
    vector < char >v(strlen(line) + 1);
    char *l = &v[0];
    strcpy(l, line);
    char *key = NULL;
    char *val = new char[MAXLENGTH];    //XXX!

    if (strlen(l) > 0 && l[0] != '#')   // comment line
    {
        char *tmp = NULL;
        char *strtok_next;
        if ((key = strtok_r(l, "=", &strtok_next)) != NULL &&
            (tmp = strtok_r(NULL, "\"", &strtok_next)) != NULL)
        {
            strncpy(val, tmp, MAXLENGTH - 1);   //XXX!
            //dsyslog(DBG " SysConf Insert key \"%s\"-> \"%s\" ",key, val);
            sysMap_.insert(map < string, char *>::value_type(key, val));
        }
    }
}
#endif /*REELVDR*/
