#if !defined(AFX_EGEDURESULT_H__4B6CB002_5606_4DD5_B67D_F3450ADC91F3__INCLUDED_)
#define AFX_EGEDURESULT_H__4B6CB002_5606_4DD5_B67D_F3450ADC91F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// egEduResult.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// egEduResult dialog

class egEduResult : public CDialog
{
// Construction
public:
	egEduResult(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(egEduResult)
	enum { IDD = IDD_RESULT };
	CEdit	m_edtResult;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(egEduResult)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(egEduResult)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EGEDURESULT_H__4B6CB002_5606_4DD5_B67D_F3450ADC91F3__INCLUDED_)
