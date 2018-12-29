; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAboutDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "EDUGREEN.h"
ODLFile=EDUGREEN.odl

ClassCount=6
Class1=CEGApp
Class2=CEDUGREENDlg
Class3=CAboutDlg
Class4=CEDUGREENDlgAutoProxy

ResourceCount=5
Resource1=IDD_EDU
Resource2=IDR_MAINFRAME
Resource3=IDD_MAIN
Class5=egEduClass
Resource4=IDD_ABOUTBOX
Class6=egEduResult
Resource5=IDD_RESULT

[CLS:CEGApp]
Type=0
HeaderFile=EDUGREEN.h
ImplementationFile=EDUGREEN.cpp
Filter=N

[CLS:CEDUGREENDlg]
Type=0
HeaderFile=EDUGREENDlg.h
ImplementationFile=EDUGREENDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CEDUGREENDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=EDUGREENDlg.h
ImplementationFile=EDUGREENDlg.cpp
Filter=D
LastObject=CAboutDlg
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=6
Control1=IDOK,button,1342373889
Control2=IDC_STATIC,static,1342308481
Control3=IDC_STATIC,static,1342308353
Control4=IDC_STATIC,static,1342308481
Control5=IDC_STATIC,static,1342308480
Control6=IDC_STATIC,static,1342177294

[CLS:CEDUGREENDlgAutoProxy]
Type=0
HeaderFile=DlgProxy.h
ImplementationFile=DlgProxy.cpp
BaseClass=CCmdTarget
Filter=N

[DLG:IDD_EDU]
Type=1
Class=egEduClass
ControlCount=4
Control1=IDC_EDIT,edit,1342242816
Control2=IDC_PICMAIN,static,1342177294
Control3=IDC_ANSID,static,1342308352
Control4=IDENTER,button,1342242816

[DLG:IDD_MAIN]
Type=1
Class=CEDUGREENDlg
ControlCount=5
Control1=IDCONTINUE,button,1342242816
Control2=IDC_EDULIST,combobox,1344340291
Control3=IDRELOAD,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342177294

[CLS:egEduClass]
Type=0
HeaderFile=egEduClass.h
ImplementationFile=egEduClass.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT
VirtualFilter=dWC

[DLG:IDD_RESULT]
Type=1
Class=egEduResult
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_EDIT,edit,1352730692

[CLS:egEduResult]
Type=0
HeaderFile=egEduResult.h
ImplementationFile=egEduResult.cpp
BaseClass=CDialog
Filter=D
LastObject=egEduResult
VirtualFilter=dWC

