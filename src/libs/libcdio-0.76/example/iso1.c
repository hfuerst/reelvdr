/*
  $Id: iso1.c,v 1.4 2005/02/03 07:32:32 rocky Exp $

  Copyright (C) 2004, 2005 Rocky Bernstein <rocky@panix.com>
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/* Simple program to show using libiso9660 to list files in a directory of
   an ISO-9660 image.
 */

/* This is the ISO 9660 image. */
#define ISO9660_IMAGE_PATH "../"
#define ISO9660_IMAGE ISO9660_IMAGE_PATH "test/copying.iso"

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif
#include <sys/types.h>
#include <cdio/cdio.h>
#include <cdio/iso9660.h>

#include <stdio.h>

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#ifdef HAVE_STRING_H
#include <string.h>
#endif
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif


int
main(int argc, const char *argv[])
{
  CdioList_t *entlist;
  CdioListNode_t *entnode;
  char const *psz_fname;
  iso9660_t *p_iso;

  if (argc > 1) 
    psz_fname = argv[1];
  else 
    psz_fname = ISO9660_IMAGE;

  p_iso = iso9660_open (psz_fname);
  
  if (NULL == p_iso) {
    fprintf(stderr, "Sorry, couldn't open %s as an ISO-9660 image\n", 
	    psz_fname);
    return 1;
  }

  entlist = iso9660_ifs_readdir (p_iso, "/");
    
  /* Iterate over the list of nodes that iso9660_ifs_readdir gives  */
  
  if (entlist) {
    _CDIO_LIST_FOREACH (entnode, entlist)
    {
      char filename[4096];
      iso9660_stat_t *p_statbuf = 
	(iso9660_stat_t *) _cdio_list_node_data (entnode);
      iso9660_name_translate(p_statbuf->filename, filename);
      printf ("/%s\n", filename);
      free(p_statbuf);
    }
    
    _cdio_list_free (entlist, true);
  }
  

  iso9660_close(p_iso);
  return 0;
}

