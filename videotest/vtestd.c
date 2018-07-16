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

testd()
{
	int i,a,b;

/* Draw the spiral pattern						*/

	verase(FULL_SCREEN);

	a = 40;
	b = 20;

	vmove(1,1);
	for (i=0; i<9; i++)
	{
		vline(HORIZONTAL,a);
		a--;
		vline(VERTICAL,b);
		b--;
		vline(HORIZONTAL,-a);
		a++;
		vline(VERTICAL,-b);
		b--;
	}
	vmove(23,0);
	vprint("Press a key to continue...");
	vgetc();

/* Draw the test grid and the wavy line pattern										*/

	verase(FULL_SCREEN);
	vmove(0,0);
	vprint("Test of line drawing abilities");

	for (i=0; i<40; i+=4)
	{
		vmove(2,i);
		vline(VERTICAL,18);
	}

	for (i=2; i<20; i++)
	{
		vmove(i,0);
		vline(HORIZONTAL,37);
	}

	vmove(10,36);
	vline(HORIZONTAL,2);
	vline(VERTICAL,-5);

	for (i=0; i<20; i++)
	{
		vline(HORIZONTAL,2);
		vline(VERTICAL,10);
		vline(HORIZONTAL,2);
		vline(VERTICAL,-10);
	}

	vline(HORIZONTAL,2);
	vline(VERTICAL,5);
	vline(HORIZONTAL,-42);

	vmove(23,0);
	vprint("Press a key to continue...");
	vgetc();


/* Draw the test form													*/

	verase(FULL_SCREEN);

	vmove(0,0);
	vprint("Here's a test form.");

	vmove(1,0);							/* Upper left corner				*/
	vline(HORIZONTAL,60);						/* Top line					*/
	vline(VERTICAL,21);						/* right side					*/
	vline(HORIZONTAL,-60);						/* BOTTOM line					*/
	vline(VERTICAL,-21);						/* left side					*/

	vmove(5,10);
	vline(VERTICAL,17);						/* First collumn				*/

	vmove(5,45);
	vline(VERTICAL,17);						/* Last collumn					*/

	vmove(2,1);
	vprint("INVOICE NUMBER 00987.");
	vmove(2,29);
	vprint("Int'l Digital Scientific Inc.");
	vmove(3,29);
	vprint("25050 Avenue Kearn, Suite 203");
	vmove(4,29);
	vprint("Valencia, CA 91355");

	vmove(5,0);
	vline(HORIZONTAL,60);						/* line 2					*/
	vmove(7,0);
	vline(HORIZONTAL,60);						/* line 3					*/
	vmove(19,0);
	vline(HORIZONTAL,60);						/* line 4					*/

	vmove(6,1);
	vprint("Quantity");
	vmove(6,22);
	vprint("Description");
	vmove(6,50);
	vprint("Price");

	vmove(8,3);
	vprint("1");
	vmove(8,12);
	vprint("VIDEO Development system");
	vmove(9,12);
	vprint("Object license");
	vmove(8,48);
	vprint("$5,000.00");

	vmove(20,3);
	vprint("1");
	vmove(20,22);
	vprint("Totals");
	vmove(20,48);
	vprint("$5,000.00");


	vmove(23,0);
	vprint("Press a key to continue...");
	vgetc();


	vstate(0);
	verase(FULL_SCREEN);
	vgrid(10,10,10,40,1,2);
	vmove(22,0);
	vprint("Depress any key to continue...");
	vgetc();
	verase(FULL_SCREEN);
	vgrid(5,5,10,10,2,2);
	vmove(22,0);
	vprint("Depress any key to continue...");
	vgetc();
	verase(FULL_SCREEN);
	vgrid(10,10,10,40,0,0);
	vmove(22,0);
	vprint("Depress any key to continue...");
	vgetc();
	verase(FULL_SCREEN);
	vgrid(0,0,24,80,1,1);
	vmove(22,0);
	vprint("Depress any key to continue...");
	vgetc();
}
