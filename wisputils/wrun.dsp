# Microsoft Developer Studio Project File - Name="wrun" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=wrun - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "wrun.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "wrun.mak" CFG="wrun - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "wrun - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "wrun - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "wrun - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Release"
# PROP BASE Intermediate_Dir ".\Release"
# PROP BASE Target_Dir "."
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\Release"
# PROP Intermediate_Dir ".\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir "."
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "..\wispcommon" /I "..\videolib" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "WINNT" /D "MSFS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386 /out:"..\bin\wrun.exe"
# SUBTRACT LINK32 /incremental:yes

!ELSEIF  "$(CFG)" == "wrun - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\wrun___W"
# PROP BASE Intermediate_Dir ".\wrun___W"
# PROP BASE Target_Dir "."
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\debug"
# PROP Intermediate_Dir ".\debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir "."
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\wispcommon" /I "..\videolib" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "WINNT" /D "MSFS" /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"..\bin\wrun.exe"

!ENDIF 

# Begin Target

# Name "wrun - Win32 Release"
# Name "wrun - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=..\wisplib\acustubs.c
# End Source File
# Begin Source File

SOURCE=..\wisplib\backgrnd.c
# End Source File
# Begin Source File

SOURCE=..\wisplib\fexists.c
# End Source File
# Begin Source File

SOURCE=..\wisplib\idsisubs.c
# End Source File
# Begin Source File

SOURCE=..\wisplib\linksubs.c
# End Source File
# Begin Source File

SOURCE=..\wisplib\makepath.c
# End Source File
# Begin Source File

SOURCE=..\wisplib\mfstubs.c
# End Source File
# Begin Source File

SOURCE=..\wisplib\platsubs.c
# End Source File
# Begin Source File

SOURCE=..\wisplib\setenvst.c
# End Source File
# Begin Source File

SOURCE=..\wisplib\wanguid.c
# End Source File
# Begin Source File

SOURCE=..\wisplib\wassert.c
# End Source File
# Begin Source File

SOURCE=..\wisplib\werrlog.c
# End Source File
# Begin Source File

SOURCE=..\wisplib\werrpath.c
# End Source File
# Begin Source File

SOURCE=..\wisplib\wgetpgrp.c
# End Source File
# Begin Source File

SOURCE=..\wisplib\wglobals.c
# End Source File
# Begin Source File

SOURCE=..\wisputils\win32wrn.c
# End Source File
# Begin Source File

SOURCE=..\wisplib\winnt.c
# End Source File
# Begin Source File

SOURCE=..\wisplib\wispcfg.c
# End Source File
# Begin Source File

SOURCE=..\wisplib\wispvers.c
# End Source File
# Begin Source File

SOURCE=..\wisplib\wmalloc.c
# End Source File
# Begin Source File

SOURCE=..\wisplib\wperson.c
# End Source File
# Begin Source File

SOURCE=..\wisputils\wrun.c
# End Source File
# Begin Source File

SOURCE=.\wrun.rc
# End Source File
# Begin Source File

SOURCE=..\wisplib\wrunconf.c
# End Source File
# Begin Source File

SOURCE=..\wisplib\wswap.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\wrun.ico
# End Source File
# End Group
# End Target
# End Project