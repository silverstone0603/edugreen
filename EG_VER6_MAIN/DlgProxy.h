// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__2AC5315E_BF70_4081_BFC1_15ECAA2CA227__INCLUDED_)
#define AFX_DLGPROXY_H__2AC5315E_BF70_4081_BFC1_15ECAA2CA227__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEDUGREENDlg;

/////////////////////////////////////////////////////////////////////////////
// CEDUGREENDlgAutoProxy command target

class CEDUGREENDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CEDUGREENDlgAutoProxy)

	CEDUGREENDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CEDUGREENDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEDUGREENDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CEDUGREENDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CEDUGREENDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CEDUGREENDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CEDUGREENDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__2AC5315E_BF70_4081_BFC1_15ECAA2CA227__INCLUDED_)
