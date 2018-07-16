//////////////////////////////////////////////////////////////////////////
//
//	This file contains the member function definitions for the 
//		cDialogs::_ACP class
//
#include "#Defines.h"
#include "#Classes.h"
#include "#Externs.h"
#include "#Prototypes.h"
#include "resource.h"

//////////////////////////////////////////////////////////////////////////
//
//	cDialogs::_WISPBin::Initialize
//		Initializes the WISPBin dialog
//
cDialogs::_WISPBin::Initialize ( )
{
	HKEY hKey;
	HWND hDlg = Dialogs.WISPBin.hWISPBin;
	DWORD BufSize = _MAX_PATH, Disp;
	UCHAR sRegValue[_MAX_PATH];
	//	If unable to open key
	if ( RegCreateKeyEx (
		HKEY_LOCAL_MACHINE,
		"Software\\NeoMedia\\WISP\\WISPBin",
		0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS,
		NULL, &hKey, &Disp ) == ERROR_SUCCESS ) {
		//	Get value for WISP field
		BufSize = _MAX_PATH;
		if ( RegQueryValueEx (
			hKey, "WISP", 0, NULL, sRegValue,
			&BufSize ) == ERROR_SUCCESS ) {
			sRegValue[BufSize] = '\0';
			SetDlgItemText (
				Dialogs.WISPBin.hWISPBin,
				S07_WISP, (char *) sRegValue );
		}
		else {
			char sDefVal[_MAX_PATH];
			sprintf ( sDefVal, "%s\\bin\\wisp.exe",
				cApp.Env.sWISPDir );
			SetDlgItemText (
				Dialogs.WISPBin.hWISPBin,
				S07_WISP, sDefVal );
		}
		//	Get value for WEDITOR field
		BufSize = _MAX_PATH;
		if ( RegQueryValueEx (
			hKey, "WEDITOR", 0, NULL, sRegValue,
			&BufSize ) == ERROR_SUCCESS ) {
			sRegValue[BufSize] = '\0';
			SetDlgItemText (
				Dialogs.WISPBin.hWISPBin,
				S07_WEDITOR, (char *) sRegValue );
		}
		else {
			char sDefVal[_MAX_PATH];
			sprintf ( sDefVal, "%s\\bin\\vsedit.exe",
				cApp.Env.sWISPDir );
			SetDlgItemText (
				Dialogs.WISPBin.hWISPBin,
				S07_WEDITOR, sDefVal );
		}
		//	Get value for DISPLAY field
		BufSize = _MAX_PATH;
		if ( RegQueryValueEx (
			hKey, "DISPLAY", 0, NULL, sRegValue,
			&BufSize ) == ERROR_SUCCESS ) {
			sRegValue[BufSize] = '\0';
			SetDlgItemText (
				Dialogs.WISPBin.hWISPBin,
				S07_DISPLAY, (char *) sRegValue );
		}
		else {
			char sDefVal[_MAX_PATH];
			sprintf ( sDefVal, "%s\\bin\\display.exe",
				cApp.Env.sWISPDir );
			SetDlgItemText (
				Dialogs.WISPBin.hWISPBin,
				S07_DISPLAY, sDefVal );
		}
		RegCloseKey ( hKey );
	}

	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	//	***** CHANGED *****
	//	Removed HDC assignments
	HWND hCtl = GetDlgItem ( hWISPBin, S07_WISP );
//	HDC hDC = GetDC ( hCtl );
	ChkInvalid ( hCtl );

	hCtl = GetDlgItem ( hWISPBin, S07_WEDITOR );
//	hDC = GetDC ( hCtl );
	ChkInvalid ( hCtl );

	hCtl = GetDlgItem ( hWISPBin, S07_DISPLAY );
//	hDC = GetDC ( hCtl );
	ChkInvalid ( hCtl );
	//	***** END CHANGED *****

	return 0;
}

//////////////////////////////////////////////////////////////////////////
//
//	cDialogs::_WISPBin::Save
//		Saves the data from the WISPBin dialog to the registry
//
cDialogs::_WISPBin::Save ( )
{
	HWND hDlg;
	HKEY hKey;
	UCHAR sRegVal[_MAX_PATH];

	hDlg = Dialogs.WISPBin.hWISPBin;
	RegOpenKeyEx (
		HKEY_LOCAL_MACHINE,
		"Software\\NeoMedia\\WISP\\WISPBin",
		0, KEY_ALL_ACCESS, &hKey );

	GetDlgItemText (
		hDlg, S07_WISP, (char *) sRegVal, _MAX_PATH );
	RegSetValueEx (
		hKey, "WISP", 0, REG_SZ, sRegVal,
		strlen ((char *) sRegVal )+1);

	GetDlgItemText (
		hDlg, S07_WEDITOR, (char *) sRegVal, _MAX_PATH );
	RegSetValueEx (
		hKey, "WEDITOR", 0, REG_SZ, sRegVal,
		strlen ((char *) sRegVal )+1);

	GetDlgItemText (
		hDlg, S07_DISPLAY, (char *) sRegVal, _MAX_PATH );
	RegSetValueEx (
		hKey, "DISPLAY", 0, REG_SZ, sRegVal,
		strlen ((char *) sRegVal )+1);

	RegFlushKey ( hKey );
	RegCloseKey ( hKey );
	return 0;
}

//////////////////////////////////////////////////////////////////////////
//
//	cDialogs::_WISPBin::ChkInvalid
//		Validates required fields and if the field contains an
//		invalid entry then it sets the 'iv' flag to false so
//		that the background will be painted yellow
//
void cDialogs::_WISPBin::ChkInvalid ( HWND hCtl )
{
	WIN32_FIND_DATA ValFile;
	char sTemp[_MAX_PATH];
	ZeroMemory ( sTemp, sizeof ( sTemp ));
	ZeroMemory ( &ValFile, sizeof ( ValFile ));

	GetWindowText ( hCtl, sTemp, _MAX_PATH );
	if ( hCtl == GetDlgItem 
		( Dialogs.WISPBin.hWISPBin, S07_WISP )) {
		if ( FindFirstFile (
			sTemp, &ValFile ) == INVALID_HANDLE_VALUE ) {
			ivWispExe = FALSE;
		}
		else ivWispExe = TRUE;
	}
	if ( hCtl == GetDlgItem 
		( Dialogs.WISPBin.hWISPBin, S07_WEDITOR )) {
		if ( FindFirstFile (
			sTemp, &ValFile ) == INVALID_HANDLE_VALUE ) {
			ivWEditorExe = FALSE;
		}
		else ivWEditorExe = TRUE;
	}
	if ( hCtl == GetDlgItem 
		( Dialogs.WISPBin.hWISPBin, S07_DISPLAY )) {
		if ( FindFirstFile ( 
			sTemp, &ValFile ) == INVALID_HANDLE_VALUE ) {
			ivDisplayExe = FALSE;
		}
		else ivDisplayExe = TRUE;
	}
	InvalidateRect ( hCtl, NULL, FALSE );
	return;
}
