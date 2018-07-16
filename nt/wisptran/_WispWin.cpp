/*
** Copyright (c) 1994-2003, NeoMedia Technologies, Inc. All Rights Reserved.
**
** WISP - Wang Interchange Source Processor
**
** $Id:$
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
** $Source:$
** $Author: gsl $
** $Date:$
** $Revision:$
*/

#include "#Defines.h"
#include "#Classes.h"
#include "#Prototypes.h"
#include "resource.h"

//	Global (application wide) variables
cApplication		cApp;
cWindows				cWnd;
struct _GlbFlags {
	BOOL isTranslating,
		isCompiling;
}GlbFlags;
//	WinMain - Entry Point
int WINAPI WinMain ( HINSTANCE hInst, HINSTANCE hInstPrev, LPSTR lpCmdLine, int i_nCmdShow )
{
    HINSTANCE hLibrary;

	Ctl3dRegister ( hInst );
	Ctl3dAutoSubclass( hInst );
	hLibrary = LoadLibrary("RichEd32.DLL");

	cApp.Env->CurAppStatus = cas_StartUp;										//	Set flag 
	cApp.Env->hInstGlb = CustCtrl.hInst = hInst;								//	Set member in class to hInst
	CustCtrl.hInst = hInst;
	cApp.AppInit ( hInst );

	CustCtrl.StatusBar.UpdateMsg ( "Ready" );
	cApp.Env->CurAppStatus = cas_Running;

	cApp.MsgLoop ( );																	//	Run the message loop

	Ctl3dUnregister ( hInst );
    FreeLibrary(hLibrary);

	return 0;
}


/*
**	History:
**	$Log: _WispWin.cpp,v $
**	Revision 1.5  2003/06/18 16:43:07  gsl
**	Add CVS header and history
**	
**
*/