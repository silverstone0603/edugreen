// egEduResult.cpp : implementation file
//

#include "stdafx.h"
#include "EDUGREEN.h"
#include "EDUGREENDlg.h"
#include "egEduClass.h"
#include "egEduResult.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// egEduResult dialog


egEduResult::egEduResult(CWnd* pParent /*=NULL*/)
	: CDialog(egEduResult::IDD, pParent)
{
	//{{AFX_DATA_INIT(egEduResult)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void egEduResult::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(egEduResult)
	DDX_Control(pDX, IDC_EDIT, m_edtResult);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(egEduResult, CDialog)
	//{{AFX_MSG_MAP(egEduResult)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// egEduResult message handlers

void egEduResult::OnOK() 
{
	// TODO: Add extra validation here
	CDialog::OnOK();
}

BOOL egEduResult::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_edtResult.SetWindowText("");
	
	char total_data[102400];
	char line_data[1024];

	CString tmpString;
	for(int i=0; i<(eg_QusCount+1); i++){
		sprintf(line_data,"%d번 문제\r\n[정답 : %s]\r\n[입력 : %s]\r\n[해설 : %s]\r\n\r\n",i+1,eg_QData[i][2],eg_QAnswer[i],eg_QData[i][3]);    //line번호+line 데이터를 합친다
		strcat(total_data,line_data); //전체 데이터를 합친다.(누적된다)
	}
	m_edtResult.SetWindowText(total_data);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
