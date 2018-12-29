# Microsoft Developer Studio Project File - Name="EDUGREEN" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=EDUGREEN - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "EDUGREEN.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "EDUGREEN.mak" CFG="EDUGREEN - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "EDUGREEN - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe
# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release\ofiles"
# PROP Intermediate_Dir "Release\ifiles"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x412 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x412 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
# Begin Target

# Name "EDUGREEN - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\DlgProxy.cpp
# End Source File
# Begin Source File

SOURCE=.\EDUGREEN.cpp
# End Source File
# Begin Source File

SOURCE=.\EDUGREEN.odl
# End Source File
# Begin Source File

SOURCE=.\EDUGREEN.rc
# End Source File
# Begin Source File

SOURCE=.\EDUGREENDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\egDyArray.cpp
# End Source File
# Begin Source File

SOURCE=.\egEduClass.cpp
# End Source File
# Begin Source File

SOURCE=.\egEduResult.cpp
# End Source File
# Begin Source File

SOURCE=.\egMainFnc.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\DlgProxy.h
# End Source File
# Begin Source File

SOURCE=.\EDUGREEN.h
# End Source File
# Begin Source File

SOURCE=.\EDUGREENDlg.h
# End Source File
# Begin Source File

SOURCE=.\egDyArray.h
# End Source File
# Begin Source File

SOURCE=.\egEduClass.h
# End Source File
# Begin Source File

SOURCE=.\egEduResult.h
# End Source File
# Begin Source File

SOURCE=.\egMainFnc.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=".\res\1 ป็บป.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\default1.bin
# End Source File
# Begin Source File

SOURCE=.\res\EDUGREEN.ico
# End Source File
# Begin Source File

SOURCE=.\res\EDUGREEN.rc2
# End Source File
# Begin Source File

SOURCE=.\res\eg_about.bmp
# End Source File
# Begin Source File

SOURCE=.\res\eg_default.bmp
# End Source File
# Begin Source File

SOURCE=.\res\eg_logo.bmp
# End Source File
# Begin Source File

SOURCE=.\res\MSGBOX04.ICO
# End Source File
# End Group
# Begin Source File

SOURCE=.\EDUGREEN.reg
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
