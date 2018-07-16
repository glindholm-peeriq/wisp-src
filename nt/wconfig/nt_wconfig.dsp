# Microsoft Developer Studio Project File - Name="nt_wconfig" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=nt_wconfig - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "nt_wconfig.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "nt_wconfig.mak" CFG="nt_wconfig - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "nt_wconfig - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "nt_wconfig - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "nt_wconfig - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Release"
# PROP BASE Intermediate_Dir ".\Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\Release"
# PROP Intermediate_Dir ".\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /GX /O2 /I "..\rControls" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib mpr.lib ctl3d32s.lib /nologo /subsystem:windows /pdb:none /machine:I386 /out:"wconfig.exe"
# SUBTRACT LINK32 /verbose

!ELSEIF  "$(CFG)" == "nt_wconfig - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\nt_wconfig_"
# PROP BASE Intermediate_Dir ".\nt_wconfig_"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\Debug"
# PROP Intermediate_Dir ".\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "..\rControls" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib comctl32.lib mpr.lib ctl3d32s.lib /nologo /subsystem:windows /pdb:none /debug /machine:I386 /out:"wconfig_d.exe"
# SUBTRACT LINK32 /verbose

!ENDIF 

# Begin Target

# Name "nt_wconfig - Win32 Release"
# Name "nt_wconfig - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\_ConfigUtil.cpp
# End Source File
# Begin Source File

SOURCE=.\_ConfigUtil.rc
# End Source File
# Begin Source File

SOURCE=.\_Validate.cpp
# End Source File
# Begin Source File

SOURCE=.\_WndProcs.cpp
# End Source File
# Begin Source File

SOURCE=.\cACP.cpp
# End Source File
# Begin Source File

SOURCE=.\cApplication.cpp
# End Source File
# Begin Source File

SOURCE=.\cDISPLAY.cpp
# End Source File
# Begin Source File

SOURCE=.\cEXTRACT.cpp
# End Source File
# Begin Source File

SOURCE=.\cGeneral.cpp
# End Source File
# Begin Source File

SOURCE=.\cLicense.cpp
# End Source File
# Begin Source File

SOURCE=.\cMainDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\cMessage.cpp
# End Source File
# Begin Source File

SOURCE=.\cScratch.cpp
# End Source File
# Begin Source File

SOURCE=.\cVideocap.cpp
# End Source File
# Begin Source File

SOURCE=.\cWISPBin.cpp
# End Source File
# Begin Source File

SOURCE=.\cWProc.cpp
# End Source File
# Begin Source File

SOURCE=..\rControls\rControls.cpp
# End Source File
# Begin Source File

SOURCE=..\rControls\rDialogs.cpp
# End Source File
# Begin Source File

SOURCE=..\rControls\rDlgProcs.cpp
# End Source File
# Begin Source File

SOURCE=..\rControls\rStatusBar.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=".\#Classes.h"
# End Source File
# Begin Source File

SOURCE=".\#Defines.h"
# End Source File
# Begin Source File

SOURCE=".\#Externs.h"
# End Source File
# Begin Source File

SOURCE=".\#Prototypes.h"
# End Source File
# Begin Source File

SOURCE=..\rControls\Ctl3d.h
# End Source File
# Begin Source File

SOURCE=..\rControls\rControls.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=..\rControls\rPrototypes.h
# End Source File
# Begin Source File

SOURCE=..\rControls\rResources.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\wconfig.ico
# End Source File
# End Group
# End Target
# End Project
