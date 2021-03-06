// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__951FA781_C048_424C_8A60_676A967521A4__INCLUDED_)
#define AFX_DLGPROXY_H__951FA781_C048_424C_8A60_676A967521A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEDUGREEN_EDITORDlg;

/////////////////////////////////////////////////////////////////////////////
// CEDUGREEN_EDITORDlgAutoProxy command target

class CEDUGREEN_EDITORDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CEDUGREEN_EDITORDlgAutoProxy)

	CEDUGREEN_EDITORDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CEDUGREEN_EDITORDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEDUGREEN_EDITORDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CEDUGREEN_EDITORDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CEDUGREEN_EDITORDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CEDUGREEN_EDITORDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CEDUGREEN_EDITORDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__951FA781_C048_424C_8A60_676A967521A4__INCLUDED_)
