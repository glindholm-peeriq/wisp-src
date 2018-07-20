@echo off
rem
rem	File:		setupqa.bat
rem
rem	Usage:		$ setupqa.bat
rem
rem	Function:	To setup env variables needed to QA WISP
rem			using ACUCOBOL 
rem
@echo on

set WISPDIR=\\ZOOMSTAR\QA\WISP
set WISPCONFIG=\\ZOOMSTAR\TESTACU\CONFIG
set WISPDEBUG=FULL
set WISPSHAREDIR=\\ZOOMSTAR\TESTACU\message
set WISPTMPDIR=\\ZOOMSTAR\TESTACU\temp
set WISPLINKPATH=\\ZOOMSTAR\QA\WISP\bin;\\ZOOMSTAR\QA\WISP\acu;\\ZOOMSTAR\TESTACU;\\ZOOMSTAR\TESTACU\VOLRUN\ONPATH;\\ZOOMSTAR\QA\KCSIACU
set PATH=%WISPDIR%\bin;%PATH%
rem set VCOLORS=0A0CA0ACEAECBABCA0C00ACAAECEABCB
wproc qastart