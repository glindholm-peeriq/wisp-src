static char copyright[]="Copyright (c) 1995-1998 NeoMedia Technologies, All rights reserved.";
static char rcsid[]="$Id:$";

/*	
**	linksubs.c
*/

/*	LINKSUBS	Subroutines for Wang USERSUB LINK	*/

#include <stdio.h>
#include <errno.h>

#ifdef unix
#include <ctype.h>
#include <signal.h>
#endif

#ifdef VMS
#include <ssdef.h>
#include <libdef.h>
#include <rmsdef.h>
#endif

#ifdef _MSC_VER
#include <direct.h>
#include <io.h>
#include <process.h>
#endif

#include "idsistd.h"
#include "idsisubs.h"
#include "link.h"
#include "wglobals.h"
#include "wdefines.h"
#include "movebin.h"
#include "wisplib.h"
#include "osddefs.h"
#include "paths.h"
#include "wexit.h"
#include "wperson.h"

#include "werrlog.h"
#define ROUTINE		28000

#if defined(VMS) || defined(MSDOS) 
#define TEMPVMSLINK "SYS$SCRATCH:"
#define	A(x)	(parm_list->parm[x])
#define	P0	A(0),  A(1),  A(2),  A(3),  A(4),  A(5),  A(6),  A(7)
#define	P1	A(8),  A(9),  A(10), A(11), A(12), A(13), A(14), A(15)
#define	P2	A(16), A(17), A(18), A(19), A(20), A(21), A(22), A(23)
#define	P3	A(24), A(25), A(26), A(27), A(28), A(29), A(30), A(31)
#endif /* VMS || MSDOS */

/*
	The following should be OK even though they are global 
	because only used for true dynamic linking so reenterant
	code is not required. (unix and VMS/DLINK)

	They are global because used in vmspargs.c.
*/

char	g_link_pfiller[8];							/* Filler to test bug */
char	g_link_parmfile[COB_FILEPATH_LEN + 1];					/* The key to the temp file name.		*/
char	g_link_pname[80];							/* The PROGNAME to link to.			*/
int4	g_link_parmcnt = 0;							/* The number of arguments passed (0-32)	*/
char	*g_link_parmptr[MAX_LINK_PARMS];					/* The passed arguments				*/
int4	g_link_parmlen[MAX_LINK_PARMS];						/* The lengths of the passed arguments		*/

#if defined(unix) || defined(WIN32)

/*
	DYNAMIC LINKING WITH PARAMETERS
	===============================

	Program "A" does a call "LINK" to link to "B", parameters are pass thru tempfile "X".

	From program "A" LINK will call "writeunixlink" to create "X" then fork and exec "B".
	Program "B" will call "ACUGARGS" to read then delete file "X".
	Program "B" runs normally then at exit calls "ACUPARGS" to re-create "X" with updated values, then "B" exits.
	LINK calls "readunixlink" to read then delete file "X" and update program "A"s data area.
	LINK finishes and program "A" continues.

*/

/*
**	ROUTINE:	writeunixlink()
**
**	FUNCTION:	Write the temp link parm file (used by unix and WIN32)
**
**	DESCRIPTION:	{Full detailed description}...
**
**	ARGUMENTS:
**	pname		Program to link to (fullpath)
**	parmcnt		Number of parameters
**	parm_list	The parameters
**	len_lisst	The parameter lengths
**	linkkey		The returned "key" to the temp parm file
**
**	GLOBALS:	?
**
**	RETURN:		?
**
**	WARNINGS:	?
**
*/
void writeunixlink(const char *pname, int parmcnt, struct str_parm *parm_list, struct str_len *len_list, char *linkkey)
{
	int	pid;
	const char *predir = wisplinkdir(NULL);
	FILE	*fp;
	int4	size, i;

	pid = getpid();

	if ( !fexists(predir) )
	{
		if (mkdir ( predir, 0777))
		{
			werrlog(ERRORCODE(10),predir, errno,0,0,0,0,0,0);
			wexit(ERRORCODE(10));
		}
		chmod ( predir,0777);
	}

	sprintf(linkkey,"%s%sLINK%06d", predir, DIR_SEPARATOR_STR, pid);		/* Open the parm file			*/
	fp = fopen(linkkey,FOPEN_WRITE_BINARY);
	if ( !fp )
	{
		werrlog(ERRORCODE(12),linkkey,errno,"writeunixlink",0,0,0,0,0);
		wexit(ERRORCODE(12));
	}

	size = strlen( pname );								/* Write the program to exec		*/
	fwrite( &size, 4, 1, fp );
	fwrite( pname, size, 1, fp );

	fwrite( &parmcnt, 4, 1, fp );							/* Write the parm count			*/

	for ( i=0; i < parmcnt; i++ )							/* Write the parms			*/
	{
		size = len_list->len[i];
		fwrite( &size, 4, 1, fp );
		fwrite( parm_list->parm[i],size,1,fp);
	}

	size = -1;
	fwrite( &size,		4, 1, fp );						/* Write the compcode			*/
	fwrite( &size, 		4, 1, fp );						/* Write the returncode			*/
	fwrite( &CANEXITFLAG,	4, 1, fp );						/* Write the Cancel-Exit flag		*/
	fwrite( &size,		4, 1, fp );						/* Write the LOGOFF flag		*/

	fflush(fp);
	fclose(fp);

	wtrace("LINK","PARMFILE","Created PARMFILE [%s] pname=[%s] parmcnt=[%d]",
	       linkkey, pname, parmcnt);
}

/*
**	ROUTINE:	readunixlink()
**
**	FUNCTION:	Read and delete the temp link parm file (used by unix and WIN32)
**
**	DESCRIPTION:	
**			This routine is called after the LINK has completed
**			to read the tmp parm file back into the parms from
**			the calling program.
**
**			- if file is unchanged then program "B" doesn't understand this protocol.
**			- if file is missing then program "B" terminated abnormally.
**			- if file is changed then program "B" terminated normally.
**
**	ARGUMENTS:
**	parmcnt		Number of parameters
**	parm_list	The parameters
**	len_lisst	The parameter lengths
**	linkkey		The "key" to the temp parm file
**	compcode	Returned completion code
**				16  = Temp file not found - linked to program aborted
**				-1  = Temp file unchanged - linked to program doesn't understand protocol
**	returncode	Returned return code
**
**	GLOBALS:	?
**
**	RETURN:		?
**
**	WARNINGS:	?
**
*/
void readunixlink(int parmcnt, struct str_parm *parm_list, struct str_len *len_list, const char *linkkey, 
		  int4 *compcode, int4 *returncode)
{
	FILE	*fp;
	int4	size,i;
	char	tempstr[80];

	fp = fopen(linkkey,FOPEN_READ_BINARY);						/* Open the Parm file			*/
	if ( !fp )
	{
		wtrace("LINK","PARMFILE","Remove: Unable to open PARMFILE [%s] for reading [errno=%d]", linkkey, errno);
		
		*compcode = 16;								/* File missing, program aborted.	*/
		*returncode = 0;
		LOGOFFFLAG = 0;
		return;
	}

	fread( &size, 4, 1, fp );							/* Read the program path		*/
	fread( tempstr, size, 1, fp );

	fread( &size, 4, 1, fp );							/* Read the parmcnt			*/

	for ( i=0; i < parmcnt; i++ )							/* Read the parms			*/
	{
		fread( &size, 4, 1, fp );
		fread( parm_list->parm[i],size,1,fp);
	}

	fread( compcode,    4, 1, fp );							/* Read the comp code			*/
	fread( returncode,  4, 1, fp );							/* Read the return code			*/
	fread( tempstr,     4, 1, fp );							/* Read the Cancel-Exit flag		*/
	fread( &LOGOFFFLAG, 4, 1, fp );							/* Read the LOGOFF flag		*/

	fclose(fp);

	unlink(linkkey);								/* delete the tmp file			*/

	wtrace("LINK","PARMFILE","Removed PARMFILE [%s] compcode=[%d] retcode=[%d]",
	       linkkey, *compcode, *returncode);

	if ( *compcode == -1 ) 								/* Program didn't understand protocol.	*/
	{
		*compcode = -1;
		*returncode = -1;
		LOGOFFFLAG = 0;
	}
}

/*
	LINKGARG

		This routine is call on the way into a LINK. It reads the tmp parameter file and loads the parameters into the
		parameters and deletes the file. 
		A pcount=-1 means that no parameter file was found.
*/

void LINKGARG(pname,pcount,p1, p2, p3, p4, p5, p6, p7, p8, p9, p10,p11,p12,p13,p14,p15,p16,
		      p17,p18,p19,p20,p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,p31,p32)

char	*pname;									/* Program to call				*/
int2	*pcount;								/* Number of parms.				*/
char	*p1,*p2,*p3,*p4,*p5,*p6,*p7,*p8,*p9,*p10,*p11,*p12,*p13,*p14,*p15,*p16; /* Parms					*/
char	*p17,*p18,*p19,*p20,*p21,*p22,*p23,*p24,*p25,*p26,*p27,*p28,*p29,*p30,*p31,*p32;
{
	char	linkkey[COB_FILEPATH_LEN];					/* Link parm area key				*/
	const char *ptr;

	ptr = getenv(WISP_LINK_ENV);
	if ( NULL == ptr )							/* If no linkkey then not coming from a link	*/
	{
		*pcount = 0;
		*pname  = '\0';
		return;
	}
	cstr2cobx(linkkey,ptr,COB_FILEPATH_LEN);

	ACUGARGS(linkkey,pname, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10,p11,p12,p13,p14,p15,p16,
				p17,p18,p19,p20,p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,p31,p32);

	*pcount = (short) g_link_parmcnt;
}

void ISRUNUSING(void)
{
	LINKPARM = 0;								/* Were coming from a RUN USING not a LINK 	*/
}

void LINKPARG(void)
{
	ACUPARGS();
}

void LINKNARG( int2* argcount )
{
	ACUNARGS( argcount );
}

/*
	The original ACUCOBOL versions
*/

void ACUGARGS(linkkey,pname, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10,p11,p12,p13,p14,p15,p16,
			p17,p18,p19,p20,p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,p31,p32)
										/* This routine is call on the way into a LINK	*/
										/* from ACULINK. It reads the tmp parameter	*/
										/* file and loads the parameters into the	*/
										/* parameters from ACULINK. ACULINK then CALLs	*/
										/* the LINKed to program.			*/

char	*linkkey;								/* Link parm area key				*/
char	*pname;									/* Program to call				*/
char	*p1,*p2,*p3,*p4,*p5,*p6,*p7,*p8,*p9,*p10,*p11,*p12,*p13,*p14,*p15,*p16; /* Parms					*/
char	*p17,*p18,*p19,*p20,*p21,*p22,*p23,*p24,*p25,*p26,*p27,*p28,*p29,*p30,*p31,*p32;
{
	FILE	*fp;
	int4	size,i;
	char	tempstr[COB_FILEPATH_LEN];

	LINKPARM = 1;									/* We are inside an ACU link		*/

	g_link_parmptr[0] = p1;								/* Save all the ptrs into ACU_COBOL	*/
	g_link_parmptr[1] = p2;
	g_link_parmptr[2] = p3;
	g_link_parmptr[3] = p4;
	g_link_parmptr[4] = p5;
	g_link_parmptr[5] = p6;
	g_link_parmptr[6] = p7;
	g_link_parmptr[7] = p8;
	g_link_parmptr[8] = p9;
	g_link_parmptr[9] = p10;
	g_link_parmptr[10] = p11;
	g_link_parmptr[11] = p12;
	g_link_parmptr[12] = p13;
	g_link_parmptr[13] = p14;
	g_link_parmptr[14] = p15;
	g_link_parmptr[15] = p16;
	g_link_parmptr[16] = p17;
	g_link_parmptr[17] = p18;
	g_link_parmptr[18] = p19;
	g_link_parmptr[19] = p20;
	g_link_parmptr[20] = p21;
	g_link_parmptr[21] = p22;
	g_link_parmptr[22] = p23;
	g_link_parmptr[23] = p24;
	g_link_parmptr[24] = p25;
	g_link_parmptr[25] = p26;
	g_link_parmptr[26] = p27;
	g_link_parmptr[27] = p28;
	g_link_parmptr[28] = p29;
	g_link_parmptr[29] = p30;
	g_link_parmptr[30] = p31;
	g_link_parmptr[31] = p32;

	cobx2cstr(g_link_parmfile, linkkey, COB_FILEPATH_LEN);

	fp = fopen(g_link_parmfile,FOPEN_READ_BINARY);					/* Open the Parm file			*/
	if ( !fp )
	{
		werrlog(ERRORCODE(12),g_link_parmfile,errno,"LINKGARG",0,0,0,0,0);
		wexit(ERRORCODE(12));
	}

	memset ( pname,' ',80);
	fread( &size, 4, 1, fp );							/* Read the program path		*/
	fread( pname, size, 1, fp );

	memcpy(g_link_pname, pname, size );
	g_link_pname[size] = '\0';

	fread( &g_link_parmcnt, 4, 1, fp );						/* Read the parmcnt			*/

	for ( i=0; i < g_link_parmcnt; i++ )						/* Read the parms			*/
	{
		fread( &g_link_parmlen[i], 4, 1, fp );
		fread( g_link_parmptr[i],g_link_parmlen[i],1,fp);
	}

	fread( &size,	4, 1, fp );							/* Read the comp code			*/
	fread( &size,	4, 1, fp );							/* Read the return code			*/
	fread( &CANEXITFLAG, 4, 1, fp );						/* Read the CANCEL-EXIT flag		*/
	fread( tempstr,      4, 1, fp );						/* Read the LOGOFF flag			*/

	fclose(fp);

	unlink(g_link_parmfile);							/* Delete the temp file			*/

	wtrace("LINK","PARMFILE","Consumed PARMFILE [%s] pname=[%s] parmcnt=[%d]",
	       g_link_parmfile, g_link_pname, g_link_parmcnt);
}

void ACUPARGS()								/* This routine is call on the way back from a LINK 	*/
									/* with ACU_COBOL. It writes the LINKAGE parameters	*/
									/* from the linked program to the tmp file.		*/
{
	FILE	*fp;
	int4	size,i;
	static	int	first=1;

	if (!LINKPARM) return;

	if (!first) return;
	first = 0;

	fp = fopen(g_link_parmfile,FOPEN_WRITE_BINARY);					/* Open the Parm file			*/
	if ( !fp )
	{
		werrlog(ERRORCODE(12),g_link_parmfile,errno,"LINKPARG",0,0,0,0,0);
		wexit(ERRORCODE(12));
	}

	size = strlen(g_link_pname);
	fwrite( &size, 4, 1, fp );							/* Write the program path		*/
	fwrite( g_link_pname, size, 1, fp );

	fwrite( &g_link_parmcnt, 4, 1, fp );						/* Write the parmcnt			*/

	for ( i=0; i < g_link_parmcnt; i++ )						/* Write the parms			*/
	{
		fwrite( &g_link_parmlen[i], 4, 1, fp );
		fwrite( g_link_parmptr[i],g_link_parmlen[i],1,fp);
	}

	size = -1;
	fwrite( &LINKCOMPCODE, 4, 1, fp );						/* Write the comp code			*/
	fwrite( &LINKRETCODE,  4, 1, fp );						/* Write the return code		*/
	fwrite( &size,		4, 1, fp );						/* Write the CANCEL EXIT flag		*/
	fwrite( &LOGOFFFLAG,   4, 1, fp );						/* Write the LOGOFF flag		*/

	fclose(fp);

	wtrace("LINK","PARMFILE","Restored PARMFILE [%s] pname=[%s] parmcnt=[%d] compcode=[%d] retcode=[%d]",
	       g_link_parmfile, g_link_pname, g_link_parmcnt, LINKCOMPCODE, LINKRETCODE);
}


void ACUNARGS( short* argcount )							/* Return the number of ARGs passed	*/
{
	short i;

	i = g_link_parmcnt;
	*argcount = i;
}
#endif /* unix || WIN32 */

/************************************************************************/

#ifdef VMS
writevmslink ( pname, parmcnt, parm_list, len_list, vmskey)/* This routine takes the parameters collected by LINK	*/
								/* and writes them out to a tmp parm file.		*/
char	*pname;								/* Program to link to (fullpath)		*/
int	parmcnt;							/* Number of parameters.			*/
struct str_parm *parm_list;						/* Parms					*/
struct str_len   *len_list;						/* Parm lengths					*/
char	*vmskey;							/* key to parm area				*/
{
	int	pid;
	char	*predir;
	FILE	*fp;
	int4	size, i;

	pid = getpid();
	predir = TEMPVMSLINK;							/* TEMPVMSLINK = "SYS$SCRATCH:"		*/

					/*  acu_cobol version of this routine calls
					*  "access" to see if "predir" is accessable. 
					*  VMS can not do this on "SYS$SCRATCH:"
					*  so the "access" test was removed.
					*/

	sprintf( vmskey, "%sLINK%06d.TMP;1", predir, pid ) ;			/* Make the parm file name		*/

	if ( fexists(vmskey) )							/* If it already exists;		*/
	{
		delete ( vmskey ) ;						/* Delete it before opening		*/
	}

	fp = fopen(vmskey,FOPEN_WRITE_BINARY);					/* open the parm file.			*/
	if ( !fp )
	{
		werrlog(ERRORCODE(12),vmskey,errno,"writevmslink",0,0,0,0,0);
		wexit(ERRORCODE(12));
	}

	size = strlen( pname );							/* Write the program to exec		*/
	fwrite( &size, 4, 1, fp );
	fwrite( pname, size, 1, fp );

	fwrite( &parmcnt, 4, 1, fp );						/* Write the parm count			*/

	for ( i=0; i < parmcnt; i++ )						/* Write the parms			*/
	{
		size = len_list->len[i];
		fwrite( &size, 4, 1, fp );
		fwrite( parm_list->parm[i],size,1,fp);
	}

	size = -1;
	fwrite( &size,		4, 1, fp );						/* Write the compcode			*/
	fwrite( &size, 		4, 1, fp );						/* Write the returncode			*/
	fwrite( &CANEXITFLAG,	4, 1, fp );						/* Write the Cancel-Exit flag		*/
	fwrite( &size,		4, 1, fp );						/* Write the LOGOFF flag		*/

	fclose(fp);
}

readvmslink ( pname, parmcnt, parm_list, len_list, vmskey, compcode, returncode)
									/* This routine is called after the LINK has completed 	*/
									/* to read the tmp parm file back into the parms from 	*/
									/* the calling program.					*/
char	*pname;								/* Program to link to (fullpath)		*/
int	parmcnt;							/* Number of parameters.			*/
struct str_parm *parm_list;						/* Parms					*/
struct str_len   *len_list;						/* Parm lengths					*/
char	*vmskey;							/* key to parm area				*/
int4	*compcode;
int4	*returncode;
{
	FILE	*fp;
	int4	size,i;
	char	tempstr[80];

	fp = fopen(vmskey,FOPEN_READ_BINARY);					/* Open the Parm file			*/
	if ( !fp )
	{
		werrlog(ERRORCODE(12),vmskey,errno,"readvmslink",0,0,0,0,0);
		wexit(ERRORCODE(12));
	}

	fread( &size, 4, 1, fp );						/* Read the program path		*/
	fread( tempstr, size, 1, fp );

	fread( &size, 4, 1, fp );						/* Read the parmcnt			*/

	for ( i=0; i < parmcnt; i++ )						/* Read the parms			*/
	{
		fread( &size, 4, 1, fp );
		fread( parm_list->parm[i],size,1,fp);
	}

	fread( compcode,    4, 1, fp );						/* Read the comp code			*/
	fread( returncode,  4, 1, fp );						/* Read the return code			*/
	fread( tempstr,     4, 1, fp );						/* Write the Cancel-Exit flag		*/
	fread( &LOGOFFFLAG, 4, 1, fp );						/* Write the LOGOFF flag		*/

	fclose(fp);

	unlink(vmskey);								/* delete the tmp file			*/

	if ( *compcode == -1 ) 							/* Program didn't understand protocol.	*/
	{
		*compcode = 16;							/* Linked prg exited abnormaly		*/
		*returncode = 0;
		LOGOFFFLAG = 0;
	}
}


VMSGARGS(vmskey,argcount,p1, p2, p3, p4, p5, p6, p7, p8, p9, p10,p11,p12,p13,p14,p15,p16,
					p17,p18,p19,p20,p21,p22,p23,p24,p25,p26,p27,p28,p29,p30,p31,p32)
										/* This routine is call on the way into a LINK	*/
										/* from VMSLINK. It reads the tmp parameter	*/
										/* file and loads the parameters into the	*/
										/* parameters from VMSLINK. VMSLINK then CALLs	*/
										/* the LINKed to program.			*/

char	*vmskey;								/* Link parm area key				*/
short	*argcount;								/* Number of parameters to pass to subroutine	*/
char	*p1,*p2,*p3,*p4,*p5,*p6,*p7,*p8,*p9,*p10 ;				/* Parameters					*/
char	*p11,*p12,*p13,*p14,*p15,*p16,*p17,*p18,*p19,*p20;
char	*p21,*p22,*p23,*p24,*p25,*p26,*p27,*p28,*p29,*p30,*p31,*p32;
{
	FILE	*fp;
	int4	size,i;
	char	tempstr[80];

	LINKPARM = 1;								/* We are inside an VMS link		*/

	g_link_parmptr[0] = p1;							/* Save all the ptrs into VMSCOBOL	*/
	g_link_parmptr[1] = p2;
	g_link_parmptr[2] = p3;
	g_link_parmptr[3] = p4;
	g_link_parmptr[4] = p5;
	g_link_parmptr[5] = p6;
	g_link_parmptr[6] = p7;
	g_link_parmptr[7] = p8;
	g_link_parmptr[8] = p9;
	g_link_parmptr[9] = p10;
	g_link_parmptr[10] = p11;
	g_link_parmptr[11] = p12;
	g_link_parmptr[12] = p13;
	g_link_parmptr[13] = p14;
	g_link_parmptr[14] = p15;
	g_link_parmptr[15] = p16;

	if ( MAX_LINK_PARMS > 16 )
	{
		g_link_parmptr[16] = p17;
		g_link_parmptr[17] = p18;
		g_link_parmptr[18] = p19;
		g_link_parmptr[19] = p20;
		g_link_parmptr[20] = p21;
		g_link_parmptr[21] = p22;
		g_link_parmptr[22] = p23;
		g_link_parmptr[23] = p24;
		g_link_parmptr[24] = p25;
		g_link_parmptr[25] = p26;
		g_link_parmptr[26] = p27;
		g_link_parmptr[27] = p28;
		g_link_parmptr[28] = p29;
		g_link_parmptr[29] = p30;
		g_link_parmptr[30] = p31;
		g_link_parmptr[31] = p32;
	}

	for(i=0;i<80-1;i++)
	{
		if ( vmskey[i] == '\0' || vmskey[i] == ' ' ) 
		{
			g_link_parmfile[i] = '\0';
			break;
		}
		g_link_parmfile[i] = vmskey[i];
	}

	fp = fopen(g_link_parmfile,FOPEN_READ_BINARY);					/* Open the Parm file			*/
	if ( !fp )
	{
		werrlog(ERRORCODE(12),g_link_parmfile,errno,"VMSGARGS",0,0,0,0,0);
		wexit(ERRORCODE(12));
	}

	memset( g_link_pname,' ',80);
	fread( &size, 4, 1, fp );							/* Read the program path		*/
	fread( g_link_pname, size, 1, fp );
	g_link_pname[size] = '\0';

	fread( &g_link_parmcnt, 4, 1, fp );						/* Read the parmcnt			*/

	if ( g_link_parmcnt > MAX_LINK_PARMS )
	{
		g_link_parmcnt = MAX_LINK_PARMS ;
	}

	for ( i=0; i < g_link_parmcnt; i++ )						/* Read the parms			*/
	{
		fread( &g_link_parmlen[i], 4, 1, fp );
		fread( g_link_parmptr[i],g_link_parmlen[i],1,fp);
	}

	fread( &size,	4, 1, fp );							/* Read the comp code			*/
	fread( &size,	4, 1, fp );							/* Read the return code			*/
	fread( &CANEXITFLAG, 4, 1, fp );						/* Read the CANCEL-EXIT flag		*/
	fread( tempstr,      4, 1, fp );						/* Read the LOGOFF flag			*/

	fclose(fp);

	delete ( g_link_parmfile ) ;							/* We got it, delete it!		*/

	*argcount = g_link_parmcnt;
}


VMSNARGS( argcount )									/* Return the number of ARGs passed	*/
short *argcount;
{
	*argcount = (short) g_link_parmcnt ;
}

#endif /* VMS */

#ifdef DMF
#define WCLINK
#endif
#ifdef VMS
#define WCLINK
#endif

#ifdef WCLINK
wclink ( progname, parm_list, retval )
char	*progname ;
struct str_parm *parm_list;								/* Parms				*/
int4	*retval ;
{
	lnk_depth++ ;									/* increment the depth.			*/

											/* multiple parameters are referenced	*/
											/* by defines to simplify the code.	*/
											/* P0 to P3 represent 8 parms each	*/
											/* for a max of 32 params P0,P1,P2,P3	*/
											/* currently, the wclinkX cobol modules	*/
											/* (VMS/MSDOS only) supports 32 parms.	*/
											/* P0 = parm_list->parm[0]  to [7]	*/
											/* P1 = parm_list->parm[8]  to [15]	*/
											/* P2 = parm_list->parm[16] to [23]	*/
											/* P3 = parm_list->parm[24] to [31]	*/
	switch ( lnk_depth )
	{
		case 1:
		{
			wclink1 ( progname, P0, P1, P2, P3, retval ) ;			/* Call the COBOL link.			*/
			break;
		}
		case 2:
		{
			wclink2 ( progname, P0, P1, P2, P3, retval ) ;			/* Call the COBOL link.			*/
			break;
		}
		case 3:
		{
			wclink3 ( progname, P0, P1, P2, P3, retval ) ;			/* Call the COBOL link.			*/
			break;
		}
		case 4:
		{
			wclink4 ( progname, P0, P1, P2, P3, retval ) ;			/* Call the COBOL link.			*/
			break;
		}
		case 5:
		{
			wclink5 ( progname, P0, P1, P2, P3, retval ) ;			/* Call the COBOL link.			*/
			break;
		}
		case 6:
		{
			wclink6 ( progname, P0, P1, P2, P3, retval ) ;			/* Call the COBOL link.			*/
			break;
		}
		case 7:
		{
			wclink7 ( progname, P0, P1, P2, P3, retval ) ;			/* Call the COBOL link.			*/
			break;
		}
		case 8:
		{
			wclink8 ( progname, P0, P1, P2, P3, retval ) ;			/* Call the COBOL link.			*/
			break;
		}
		case 9:
		{
			wclink9 ( progname, P0, P1, P2, P3, retval ) ;			/* Call the COBOL link.			*/
			break;
		}
		case 10:
		{
			wclink10 ( progname, P0, P1, P2, P3, retval ) ;			/* Call the COBOL link.			*/
			break;
		}
		case 11:
		{
			wclink11 ( progname, P0, P1, P2, P3, retval ) ;			/* Call the COBOL link.			*/
			break;
		}
		case 12:
		{
			wclink12 ( progname, P0, P1, P2, P3, retval ) ;			/* Call the COBOL link.			*/
			break;
		}
		case 13:
		{
			wclink13 ( progname, P0, P1, P2, P3, retval ) ;			/* Call the COBOL link.			*/
			break;
		}
		case 14:
		{
			wclink14 ( progname, P0, P1, P2, P3, retval ) ;			/* Call the COBOL link.			*/
			break;
		}
		case 15:
		{
			wclink15 ( progname, P0, P1, P2, P3, retval ) ;			/* Call the COBOL link.			*/
			break;
		}
		case 16:
		{
			wclink16 ( progname, P0, P1, P2, P3, retval ) ;			/* Call the COBOL link.			*/
			break;
		}
	}

	lnk_depth-- ;									/* reset the depth.			*/
}
#endif /* WCLINK */

#ifdef VMS
int4	vms_to_wang_codes ( vms_code )					/* Convert VMS return code to WANG LINK return code	*/
int4	vms_code ;							/* VMS return code.					*/
{
	int4	wang_retcod ;						/* Wang version of VMS return code.			*/

	switch ( vms_code )
	{
		case RMS$_NORMAL:					/* Normal file system exit code.			*/
		case SS$_NORMAL:					/* Normal system exit code.				*/
		{
			wang_retcod = 0 ;				/* Normal wang return code.				*/
			break ;
		}
		case RMS$_DNR:						/* Device Not Ready.					*/
		case RMS$_DPE:						/* Device Positioning Error.				*/
		{
			wang_retcod = 4 ;				/* Volume is not mounted.				*/
			break ;
		}
		case RMS$_WLK:						/* Device currently Write Locked during write attempt.	*/
		{
			wang_retcod = 8 ;				/* Volume in exclusive use by another user.		*/
			break ;
		}
		case RMS$_DNF:						/* Directory Not Found.					*/
		case RMS$_DEV:						/* Device Error.					*/
		{
			wang_retcod = 16 ;				/* Directory not found.					*/
			break ;
		}
		case RMS$_FNF:						/* File Not Found.					*/
		{
			wang_retcod = 20 ;				/* File Not Found.					*/
			break ;
		}
		case RMS$_PRV:						/* Insufficient privilege or file protected.		*/
		{
			wang_retcod = 28 ;				/* Access to program's file-protection class denied.	*/
			break ;
		}
		case LIB$_INVARG:					/* Invalid Arguments.					*/
		{
			wang_retcod = 40 ;				/* Invalid param passed to READFDR (incl NL vol type).	*/
			break ;
		}
		case RMS$_SPL:						/* Submit cmd file option to a close service failed.	*/
		{
			wang_retcod = 44 ;				/* I/O error on VTOC.					*/
			break ;
		}
		case RMS$_FLK:						/* File currently locked by another user.		*/
		{
			wang_retcod = 56 ;				/* File open for other than shared read-only access.	*/
			break ;
		}
		case SS$_ACCVIO:					/* Access violation.					*/
		{
			wang_retcod = 60 ;				/* Insufficient address space for code section.		*/
			break ;
		}
		default:
		{
			wang_retcod = 50 ;				/* Unable to complete static area formation.		*/
		}
	}

	return ( wang_retcod ) ;					/* This code will need to be wswaped in caller.		*/
}

#endif /* VMS */

#ifdef DACU
#endif /* DACU */

									/* This routine sets a WISP variable to a int4 value.	*/
									/* although this could be used throughout the WISP.	*/
									/* system, it is currently only used in the LINK.	*/
									/* subsystem.  It should eventually be given a name.	*/
									/* starting with a "w" and used from the WISP Library.	*/
void swap_put ( int4* destination, int4 new_value )
{
	int4	use_value ;						/* temporary holder for the value needing WANGing.	*/

	use_value = new_value ;						/* This will preserve the original value in new_value.	*/
	wswap ( &use_value ) ;						/* swap the bits as needed for this machine to WANG.	*/
	PUTBIN ( destination, &use_value, sizeof ( use_value ) ) ;	/* move the new value bit by bit to destination.	*/
}


/*	End of	link.c	*/
/*
**	History:
**	$Log: linksubs.c,v $
**	Revision 1.20  1998-12-09 10:55:57-05  gsl
**	Add tracing and renamed globals
**
**	Revision 1.19  1998-10-09 15:04:25-04  gsl
**	In LINKGARGS() fixed parameter to ACUGARGS which was too small.
**
**	Revision 1.18  1998-08-03 16:52:00-04  jlima
**	Support Logical Volume Translation to long file names containing eventual embedded blanks
**
**	Revision 1.17  1996-09-10 11:44:22-04  gsl
**	Remove redefine of mkdir() - now in win32std.h from idsistd.h
**
**	Revision 1.16  1996-08-28 17:55:34-07  gsl
**	Document some routines
**
**	Revision 1.15  1996-08-23 14:01:21-07  gsl
**	Changed to use wisplinkdir()
**
**	Revision 1.14  1996-08-19 15:32:26-07  gsl
**	drcs update
**
**
**
*/
