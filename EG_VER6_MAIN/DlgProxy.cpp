// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "EDUGREEN.h"
#include "DlgProxy.h"
#include "EDUGREENDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEDUGREENDlgAutoProxy

IMPLEMENT_DYNCREATE(CEDUGREENDlgAutoProxy, CCmdTarget)

CEDUGREENDlgAutoProxy::CEDUGREENDlgAutoProxy()
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
	ASSERT_KINDOF(CEDUGREENDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CEDUGREENDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CEDUGREENDlgAutoProxy::~CEDUGREENDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CEDUGREENDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CEDUGREENDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CEDUGREENDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CEDUGREENDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CEDUGREENDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IEDUGREEN to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {51A3A545-EE92-4420-AD98-5A50D1083BD9}
static const IID IID_IEDUGREEN =
{ 0x51a3a545, 0xee92, 0x4420, { 0xad, 0x98, 0x5a, 0x50, 0xd1, 0x8, 0x3b, 0xd9 } };

BEGIN_INTERFACE_MAP(CEDUGREENDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CEDUGREENDlgAutoProxy, IID_IEDUGREEN, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {999C926D-D965-4CBC-8A23-DC50176E1B05}
IMPLEMENT_OLECREATE2(CEDUGREENDlgAutoProxy, "EDUGREEN.Application", 0x999c926d, 0xd965, 0x4cbc, 0x8a, 0x23, 0xdc, 0x50, 0x17, 0x6e, 0x1b, 0x5)

/////////////////////////////////////////////////////////////////////////////
// CEDUGREENDlgAutoProxy message handlers
