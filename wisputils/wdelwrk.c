			/************************************************************************/
			/*									*/
			/*	        WISP - Wang Interchange Source Pre-processor		*/
			/*		       Copyright (c) 1988, 1989, 1990, 1991		*/
			/*	 An unpublished work of International Digital Scientific Inc.	*/
			/*			    All rights reserved.			*/
			/*									*/
			/************************************************************************/

/** 
 ** program: wdelwrk
 **
 ** ident: "@(#)wdelwrk.c        1.0      ULTRIX/SYS5/AIX  3/27/90"
 ** 
 ** purpose: clean out wisp work files
 **
 ** Copyright 1990  International Digital Scientific, Inc.
 **
 **/
static char *_copyright = "(c)1990 Int'l Digital Scientific, Inc.";

#include <stdio.h>

#define EXT_FILEXT
#include "filext.h"
#include "wcommon.h"
#include "wperson.h"

#ifdef VMS
#include <descrip.h>
#endif

char *wfname();

main()
{
	char fullpath[100],tempfile[8],cmd[100];					/* work buffers */
	char *end_ptr;
	long mode;
#ifdef VMS
	char command[200];
$DESCRIPTOR(icom,command);								/* For DCL commands.			*/
#endif
	
	initglbs("WDELWRK ");
	wpload();									/* load the personality */

	mode = IS_LIB;									/* Generate LIB name */
	end_ptr = wfname(&mode,defaults.workvol,defaults.worklib,tempfile, fullpath);
	*end_ptr = '\0';
	end_ptr--;
	if ( *end_ptr == '/' ) *end_ptr = '\0';

#ifdef unix
	sprintf(cmd,"rm -fr %s",fullpath);						/* build a command line */
	system(cmd);									/* do it  */
#endif

#ifdef VMS
	sprintf(command,"del %s*.*;*",fullpath);					/* Build a command line.		*/
	lib$do_command(&icom);
#endif
}	

#ifdef unix
#include "wutils.h"
#endif

