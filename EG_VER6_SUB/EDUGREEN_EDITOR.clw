; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEDUGREEN_EDITORDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "EDUGREEN_EDITOR.h"
ODLFile=EDUGREEN_EDITOR.odl

ClassCount=5
Class1=egEditor
Class2=CEDUGREEN_EDITORDlg
Class3=CAboutDlg
Class4=CEDUGREEN_EDITORDlgAutoProxy

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CEditorDlg
Resource3=IDD_EDUGREEN_EDITOR_DIALOG

[CLS:egEditor]
Type=0
HeaderFile=EDUGREEN_EDITOR.h
ImplementationFile=EDUGREEN_EDITOR.cpp
Filter=N

[CLS:CEDUGREEN_EDITORDlg]
Type=0
HeaderFile=EDUGREEN_EDITORDlg.h
ImplementationFile=EDUGREEN_EDITORDlg.cpp
Filter=D
LastObject=CEDUGREEN_EDITORDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=EDUGREEN_EDITORDlg.h
ImplementationFile=EDUGREEN_EDITORDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CEDUGREEN_EDITORDlgAutoProxy]
Type=0
HeaderFile=DlgProxy.h
ImplementationFile=DlgProxy.cpp
BaseClass=CCmdTarget
Filter=N

[DLG:IDD_EDUGREEN_EDITOR_DIALOG]
Type=1
Class=CEDUGREEN_EDITORDlg
ControlCount=15
Control1=IDC_EDIT5,edit,1350631552
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_EDIT2,edit,1350631552
Control4=IDC_EDIT3,edit,1350631552
Control5=IDC_EDIT4,edit,1350631556
Control6=IDC_ADD,button,1342242816
Control7=IDC_SAVE,button,1342242816
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_EDIT6,edit,1486946436
Control14=IDC_STATIC,static,1342308352
Control15=IDC_BUTTON1,button,1476460544

[CLS:CEditorDlg]
Type=0
HeaderFile=EditorDlg.h
ImplementationFile=EditorDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

