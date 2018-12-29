// EDUGREEN_EDITOR.h : main header file for the EDUGREEN_EDITOR application
//

#if !defined(AFX_EDUGREEN_EDITOR_H__D0C550F0_1511_4637_A867_6305DA5AAA11__INCLUDED_)
#define AFX_EDUGREEN_EDITOR_H__D0C550F0_1511_4637_A867_6305DA5AAA11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#include "iostream"
#include "fstream"
#include "string"
#include "cstring"


/////////////////////////////////////////////////////////////////////////////
// egEditor:
// See EDUGREEN_EDITOR.cpp for the implementation of this class
//

class egEditor : public CWinApp
{
public:
	egEditor();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(egEditor)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(egEditor)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDUGREEN_EDITOR_H__D0C550F0_1511_4637_A867_6305DA5AAA11__INCLUDED_)
