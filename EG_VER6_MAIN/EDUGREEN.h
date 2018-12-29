// EDUGREEN.h : main header file for the EDUGREEN application
//

#if !defined(AFX_EDUGREEN_H__20C3F7C7_6F12_46D7_80DF_C156552DB0F5__INCLUDED_)
#define AFX_EDUGREEN_H__20C3F7C7_6F12_46D7_80DF_C156552DB0F5__INCLUDED_

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
// CEGApp:
// See EDUGREEN.cpp for the implementation of this class
//

class CEGApp : public CWinApp{
	public:
		CEGApp();

	// Overrides
		// ClassWizard generated virtual function overrides
		//{{AFX_VIRTUAL(CEGApp)
		public:
		virtual BOOL InitInstance();
		//}}AFX_VIRTUAL

	// Implementation

		//{{AFX_MSG(CEGApp)
			// NOTE - the ClassWizard will add and remove member functions here.
			//    DO NOT EDIT what you see in these blocks of generated code !
		//}}AFX_MSG
		DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDUGREEN_H__20C3F7C7_6F12_46D7_80DF_C156552DB0F5__INCLUDED_)
