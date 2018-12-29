// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "EDUGREEN_EDITOR.h"
#include "DlgProxy.h"
#include "EDUGREEN_EDITORDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEDUGREEN_EDITORDlgAutoProxy

IMPLEMENT_DYNCREATE(CEDUGREEN_EDITORDlgAutoProxy, CCmdTarget)

CEDUGREEN_EDITORDlgAutoProxy::CEDUGREEN_EDITORDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT (AfxGetApp()->m_pMainWnd != NULL);
	ASSERT_VALID (AfxGetApp()->m_pMainWnd);
	ASSERT_KINDOF(CEDUGREEN_EDITORDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CEDUGREEN_EDITORDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CEDUGREEN_EDITORDlgAutoProxy::~CEDUGREEN_EDITORDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CEDUGREEN_EDITORDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CEDUGREEN_EDITORDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CEDUGREEN_EDITORDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CEDUGREEN_EDITORDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CEDUGREEN_EDITORDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IEDUGREEN_EDITOR to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {CF79DFAB-5A4C-41D7-B296-D08C2A6F1F0B}
static const IID IID_IEDUGREEN_EDITOR =
{ 0xcf79dfab, 0x5a4c, 0x41d7, { 0xb2, 0x96, 0xd0, 0x8c, 0x2a, 0x6f, 0x1f, 0xb } };

BEGIN_INTERFACE_MAP(CEDUGREEN_EDITORDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CEDUGREEN_EDITORDlgAutoProxy, IID_IEDUGREEN_EDITOR, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {B5092653-3848-4955-BDEF-971E2B79768F}
IMPLEMENT_OLECREATE2(CEDUGREEN_EDITORDlgAutoProxy, "EDUGREEN_EDITOR.Application", 0xb5092653, 0x3848, 0x4955, 0xbd, 0xef, 0x97, 0x1e, 0x2b, 0x79, 0x76, 0x8f)

/////////////////////////////////////////////////////////////////////////////
// CEDUGREEN_EDITORDlgAutoProxy message handlers
