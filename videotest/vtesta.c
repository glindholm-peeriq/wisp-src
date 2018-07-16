/************************************************************************/
/*           VIDEO - Video Interactive Development Environment          */
/*                          Copyright (c) 1987                          */
/*      An unpublished work by Greg L. Adams.  All rights reserved.     */
/************************************************************************/

#include <stdio.h>
#include <v/video.h>
#include <v/vlocal.h>
#include <v/vdata.h>
#include <v/vintdef.h>
#include <v/vmenu.h>

#define CANCEL_CODE -1
#define CLOCK_CODE 13
#define NOTE_CODE 11
#define CALC_CODE 12
#define CALEND_CODE 14
#define PUZZLE_CODE 15

testa()
{
	register int i,j;
	struct video_menu goodies;

	verase(FULL_SCREEN);
	vmenumode(STATIC_MENU);

	vmenuinit(&goodies, POP_UP_MENU, REVERSE, 10, 10, 0);
	vmenuitem(&goodies, "Clock", CLOCK_CODE, NULL);
	vmenuitem(&goodies, "Calculator", CALC_CODE, NULL);
	vmenuitem(&goodies, "Calendar", CALEND_CODE, NULL);
	vmenuitem(&goodies, "Notepad", NOTE_CODE, NULL);
	vmenuitem(&goodies, "Puzzle", PUZZLE_CODE, NULL);
	vmenuitem(&goodies, "", 0, NULL);        
	vmenuitem(&goodies, "Cancel", CANCEL_CODE, NULL);

	while ((i = vmenugo(&goodies)) != CANCEL_CODE)
	{
		switch(i)
		{
			case CALC_CODE:   {gcalc();    break;}
			case CLOCK_CODE:  {gclock();   break;}
			case CALEND_CODE: {gcalend();  break;}
			case NOTE_CODE:   {gnotepad(); break;}
			case PUZZLE_CODE: {gpuzzle();  break;}

		}
	}
}
