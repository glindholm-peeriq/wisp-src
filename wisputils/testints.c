/*
******************************************************************************
** Copyright (c) 1994-2003, NeoMedia Technologies, Inc. All Rights Reserved.
**
** WISP - Wang Interchange Source Processor
**
**
**
** NOTICE:
** Confidential, unpublished property of NeoMedia Technologies, Inc.
** Use and distribution limited solely to authorized personnel.
** 
** The use, disclosure, reproduction, modification, transfer, or
** transmittal of this work for any purpose in any form or by
** any means without the written permission of NeoMedia 
** Technologies, Inc. is strictly prohibited.
** 
** CVS
**
**
**
**
******************************************************************************
*/


#include <stdio.h>


int main()
{
	printf("size(char)  =%lu\n", (unsigned long)sizeof(char));
	printf("size(short) =%lu\n", (unsigned long)sizeof(short));
	printf("size(int)   =%lu\n", (unsigned long)sizeof(int));
	printf("size(long)  =%lu\n", (unsigned long)sizeof(long));
	printf("size(long long)  =%lu\n", (unsigned long)sizeof(long long));
	printf("size(void*)  =%lu\n", (unsigned long)sizeof(void*));
	return 0;
}
