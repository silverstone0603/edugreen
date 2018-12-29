#if !defined(AFX_EGEDUCLASS_H__AB344624_2C78_408B_8367_FE89A3B6A6BE__INCLUDED_)
#define AFX_EGEDUCLASS_H__AB344624_2C78_408B_8367_FE89A3B6A6BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// egEduClass.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// egEduClass dialog

class egEduClass : public CDialog
{
// Construction
public:
	egEduClass(CWnd* pParent = NULL);   // standard constructor

	void egSetFont(CString tmpFontName, int tmpFontSize);
	void egCountRow(CString tmpPath);
	void egLoadImage(CString strFileName);
// Dialog Data
	//{{AFX_DATA(egEduClass)
	enum { IDD = IDD_EDU };
	CButton	m_btnAnswer;
	CEdit	m_edtAnswer;
	CStatic	m_picMain;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(egEduClass)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(egEduClass)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnEnter();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EGEDUCLASS_H__AB344624_2C78_408B_8367_FE89A3B6A6BE__INCLUDED_)
