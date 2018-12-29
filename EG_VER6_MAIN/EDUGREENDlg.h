// EDUGREENDlg.h : header file
//

#if !defined(AFX_EDUGREENDLG_H__23B7ECB3_55A7_4575_9D81_3ED3BD1B9B91__INCLUDED_)
#define AFX_EDUGREENDLG_H__23B7ECB3_55A7_4575_9D81_3ED3BD1B9B91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEDUGREENDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CEDUGREENDlg dialog

class CEDUGREENDlg : public CDialog
{
	DECLARE_DYNAMIC(CEDUGREENDlg);
	friend class CEDUGREENDlgAutoProxy;

// Construction
public:
	CEDUGREENDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CEDUGREENDlg();

// Dialog Data
	//{{AFX_DATA(CEDUGREENDlg)
	enum { IDD = IDD_MAIN };
	CComboBox	m_EduList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEDUGREENDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CEDUGREENDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CEDUGREENDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnContinue();
	afx_msg void OnReload();
	afx_msg void OnEditchangeEdulist();
	afx_msg void OnSelchangeEdulist();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPaint();
	afx_msg void OnClose();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.


#endif // !defined(AFX_EDUGREENDLG_H__23B7ECB3_55A7_4575_9D81_3ED3BD1B9B91__INCLUDED_)
