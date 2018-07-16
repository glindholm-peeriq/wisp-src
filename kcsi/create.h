/* 
	Copyright (c) 1996 DevTech Migrations, All rights reserved.
	$Id:$
*/

/*
**	File:		create.h
**
**	Project:	KCSI
**
**	RCS:		$Source:$
**
**	Purpose:	Generic prototype header
**
*/

#ifndef create_H
#define create_H
/*
**	Includes
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef WIN32
#include <io.h>
#endif

#include "intdef.h"

/*
**	Structures and Defines
*/

/*
**	Function Prototypes
*/
void kcsi_create_main(void);

void cr_io(char *io);
void cr_name_and_type_help(void);
void cr_primary_key_help(void);
void cr_split_help(void);
void cr_alt_keys_help(void);
int cr_get_output_spec(char *vers, char *platform);
void cr_get_blocks(void);
void cr_create_file(void);
int cr_eoj(void);
void cr_print_the_spec(void);
void cr_file_field_help(void);
void cr_save_in_file(void);
void cr_free_blks(void);
int cr_get_file_field(void);

char *create_version(void);
char *create_platform(void);

/*
**	WISPLIB
*/

#include "wfname.h"
#include "wisplib.h"

void WL_wswap(void *lword);			/* swap the order of the words in a longword item (for WANG routines to use)	*/
void GETPARM();
void SCRATCH();
void WL_wpload(void);
void WFCLOSE(const char* fname);								/* This routine is called after COBOL*/
int  WL_link_display(const char *file_name);
void SET();
void WISPSORT(char *sortparms, char *filetype, int4 *recsize, int4 *sortcode, int4 *returncode);

#endif /* create_H */

/*
**	History:
**	$Log: create.h,v $
**	Revision 1.4.2.3  2003/02/06 18:12:41  gsl
**	fix prototype mismatch warnings for EXTRACT and FIND
**	
**	Revision 1.4.2.2  2002/11/13 22:48:55  gsl
**	Remove protos of static functions
**	
**	Revision 1.4.2.1  2002/11/12 15:56:20  gsl
**	Sync with $HEAD Combined KCSI 4.0.00
**	
**	Revision 1.13  2002/10/23 21:07:28  gsl
**	make global name unique
**	
**	Revision 1.12  2002/10/17 21:22:40  gsl
**	cleanup
**	
**	Revision 1.11  2002/07/30 19:12:43  gsl
**	SETRETCODE
**	
**	Revision 1.10  2002/07/29 21:13:29  gsl
**	
**	Revision 1.9  2002/07/26 18:19:19  gsl
**	wscreen -> WSCREEN
**	
**	Revision 1.8  2002/07/23 20:49:51  gsl
**	globals
**	
**	Revision 1.7  2002/07/23 02:57:52  gsl
**	wfclose -> WFCLOSE
**	
**	Revision 1.6  2002/07/12 17:17:00  gsl
**	Global unique WL_ changes
**	
**	Revision 1.5  2002/07/10 21:06:24  gsl
**	Fix globals WL_ to make unique
**	
**	Revision 1.4  1997/10/30 20:52:01  scass
**	Corrected type
**	
**	Revision 1.3  1997-10-23 13:59:20-04  gsl
**	change to use link_display()
**
**	Revision 1.2  1996-10-02 18:09:35-04  gsl
**	remove squeeze() prototype - made local
**
**	Revision 1.1  1996-10-02 09:13:11-07  gsl
**	Initial revision
**
**
**
**
*/
