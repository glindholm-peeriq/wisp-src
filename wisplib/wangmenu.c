static char copyright[]="Copyright (c) 1995 DevTech Migrations, All rights reserved.";
static char rcsid[]="$Id:$";
/* MENU  interface for WANG vs programs to the VAX menu system									*/

#include "idsistd.h"
#include "menu.h"

void menu(char *name,	/* The name of the menu file			*/
	  char *rval)	/* The return value				*/
{
	int i;
	char lname[16],lval[6];

	for (i=0; i<8; i++)
	{
		if ((lname[i] = name[i]) == ' ') break;				/* copy the name into a local buffer		*/
	}
	lname[i++] = '.';
	lname[i++] = 'M';
	lname[i++] = 'E';
	lname[i++] = 'N';
	lname[i++] = 'U';
	lname[i++] = '\0';

	menu_go(lname,lval);

	rval[0] = lval[0];							/* copy the return value			*/
	rval[1] = lval[1];
}
/*
**	History:
**	$Log: wangmenu.c,v $
**	Revision 1.9  1996/08/19 22:33:07  gsl
**	drcs update
**	
**
**
*/
