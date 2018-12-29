#if !defined(AFX_EDITORDLG_H__7187E593_37E8_45B9_AB3C_EBEFA872986A__INCLUDED_)
#define AFX_EDITORDLG_H__7187E593_37E8_45B9_AB3C_EBEFA872986A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditorDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditorDlg dialog

class CEditorDlg : public CDialog
{
// Construction
public:
	CEditorDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditorDlg)
	enum { IDD = IDD_EDITOR };
	CEdit	m_txtMain;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditorDlg)
	afx_msg void OnChangeEdit1();
	virtual BOOL OnInitDialog();
	afx_msg void OnSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITORDLG_H__7187E593_37E8_45B9_AB3C_EBEFA872986A__INCLUDED_)
