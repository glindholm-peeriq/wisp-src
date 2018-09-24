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

set WISPSERVER=BLACKSTAR
set WISPDIR=\\BLACKSTAR\QA\WISP
set WISPCONFIG=\\BLACKSTAR\TESTACU\CONFIG
set WISPDEBUG=FULL
set WISPSHAREDIR=\\BLACKSTAR\TESTACU\message
set WISPTMPDIR=\\BLACKSTAR\TESTACU\temp
set WISPLINKPATH=\\BLACKSTAR\QA\WISP\bin;\\BLACKSTAR\QA\WISP\acu;\\BLACKSTAR\TESTACU;\\BLACKSTAR\TESTACU\VOLRUN\ONPATH;\\BLACKSTAR\QA\KCSIACU
set PATH=%WISPDIR%\bin;%PATH%
rem set VCOLORS=0A0CA0ACEAECBABCA0C00ACAAECEABCB