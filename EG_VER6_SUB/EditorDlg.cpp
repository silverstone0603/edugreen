// EditorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EDUGREEN_EDITOR.h"
#include "EDUGREEN_EDITORDlg.h"
#include "EditorDlg.h"
#include "DlgProxy.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditorDlg dialog


CEditorDlg::CEditorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditorDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEditorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditorDlg)
	DDX_Control(pDX, IDC_EDIT1, m_txtMain);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditorDlg, CDialog)
	//{{AFX_MSG_MAP(CEditorDlg)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditorDlg message handlers

void CEditorDlg::OnChangeEdit1() 
{

}

BOOL CEditorDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	char tmp_total[102400]="";
	char tmp_data2[1024];
	int i,j;
	for(i=0; i<100;i++){
		if(egQArray[i][0] != ""){
		for(j=0;j<4;j++){
			sprintf(tmp_data2,"%s;",egQArray[i][j]);
			strcat(tmp_total,tmp_data2);
		} 
		strcat(tmp_total,_T("\r\n"));
		}
	}	
		//MessageBox(tmp_total);
		m_txtMain.SetWindowText(tmp_total);
	//	SetDlgItemText(IDC_EDIT1,egQArray[0][0]);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEditorDlg::OnSave() 
{
	char tmp_total[102400]="";
	char tmp_data2[1024];
	int i,j;
	for(i=0; i<100;i++){
		if(egQArray[i][0] != ""){
		for(j=0;j<4;j++){
			sprintf(tmp_data2,"%s;",egQArray[i][j]);
			strcat(tmp_total,tmp_data2);
		} 
		strcat(tmp_total,_T("\r\n"));
		}
	}	
	FILE *fp;
    fp = fopen("info.txt","w");
 
    fprintf(fp,"%s",tmp_total);
    fclose(fp);
}
