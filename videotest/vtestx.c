/************************************************************************/
/*									*/
/*	     VIDEO - Video Interactive Development Environment		*/
/*									*/
/*			    Copyright (c) 1987				*/
/*									*/
/*	An unpublished work by Greg L. Adams.  All rights reserved.	*/
/*									*/
/************************************************************************/

#include <v/video.h>
#include <v/vlocal.h>
#include <v/vcap.h>
#include <v/vdata.h>

testx()
{
	char vgetcto();									/* Internal get character function.	*/
	char vcheck();									/* Internal check for char function.	*/
	char c, da_string[48];								/* String for primary DA.		*/
	char da1, da2;									/* Working character storage.		*/
	register int i;									/* Working register.			*/
	int count;									/* Working counter.			*/

	while ((c = vcheck()) != 0);							/* Flush all type ahead.		*/
	verase(FULL_SCREEN);
	vmove(0,0);
	vdefer(RESTORE);								/* Cannot defer now.			*/
	count = 0;

again:	vcontrol(chterm_esc);								/* What type of terminal are you?	*/
	vcontrol(DUMP_OUTPUT);

	for (i = 0; (i < 48) && ((da_string[i] = vgetcto(1)) != 'c') && (da_string[i] != 0); i++);

	if (da_string[i] == 0) vprint("\nInput timed out, unable to give response string.");
	else for (i = 0; (i < 48) && (da_string[i] != 'c'); i++)
	{
		if (da_string[i] < 040)
		{
			vprint("\nResponse string character %d = %o (octal).",i,da_string[i]);
		}
		else vprint("\nResponse string character %d = %c = %o.",i,da_string[i],da_string[i]);
	}


	vprint("\nDepress any key to continue, 2 returns to continue to meta character decoding.");

	c = vgetc();
	if (c == '\015') count++;
	else count = 0;
	
	if ((c != '\015') || (count < 2)) goto again;

	verase(FULL_SCREEN);
	vmove(0,0);
	vprint("Depress any key and the metacharacter will be output.\n\n");
	count = 0;
more:	i = vgetm();
	vprint("Metacharacter value = %d decimal, %o octal.\n",i,i);
	if (i == 220) count++;
	else count = 0;
	if ((i != 220) || (count < 2)) goto more;
	return(i);									/* No, then assume it is a VT100.	*/
}
