// EDUGREEN_EDITORDlg.h : header file
//

#if !defined(AFX_EDUGREEN_EDITORDLG_H__A578D238_EDA1_4739_BFAD_BC917746DD0F__INCLUDED_)
#define AFX_EDUGREEN_EDITORDLG_H__A578D238_EDA1_4739_BFAD_BC917746DD0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEDUGREEN_EDITORDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CEDUGREEN_EDITORDlg dialog

class CEDUGREEN_EDITORDlg : public CDialog
{
	DECLARE_DYNAMIC(CEDUGREEN_EDITORDlg);
	friend class CEDUGREEN_EDITORDlgAutoProxy;

// Construction
public:
	CEDUGREEN_EDITORDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CEDUGREEN_EDITORDlg();
	
	int DirCheck(CString strDir);
// Dialog Data
	//{{AFX_DATA(CEDUGREEN_EDITORDlg)
	enum { IDD = IDD_EDUGREEN_EDITOR_DIALOG };
	CEdit	m_text;
	CButton	m_View;
	CButton	m_Add;
	CEdit	m_qDirName;
	CEdit	m_qDesc;
	CEdit	m_qAnswer;
	CEdit	m_qImgSrc;
	CEdit	m_qType;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEDUGREEN_EDITORDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CEDUGREEN_EDITORDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CEDUGREEN_EDITORDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnAdd();
	afx_msg void OnSave();
	afx_msg void OnChangeEdit6();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDUGREEN_EDITORDLG_H__A578D238_EDA1_4739_BFAD_BC917746DD0F__INCLUDED_)
