// egEduClass.cpp : implementation file
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

#define MAX 255 // 버퍼크기 지정

/////////////////////////////////////////////////////////////////////////////
// 객체 생성 부분
CFont m_font;

/////////////////////////////////////////////////////////////////////////////
// egEduClass dialog

egEduClass::egEduClass(CWnd* pParent /*=NULL*/)
	: CDialog(egEduClass::IDD, pParent)
{
	//{{AFX_DATA_INIT(egEduClass)
	//}}AFX_DATA_INIT
}

BOOL egEduClass::OnInitDialog(){
	CDialog::OnInitDialog();

	CString strFilePath = _T(eg_RunPath+"\\"+eg_RunDirName+"\\turdata.ecf");

	UINT line_count=0;
	egCountRow(strFilePath);

	int line_all = eg_TurCnt;
	CString tmpStrCnt;
	tmpStrCnt.Format(_T("%d"),line_all);
	
	//AfxMessageBox(_T(eg_RunDirName+" 과정의 문제 수는 "+tmpStrCnt+"개 입니다."));
	
	//튜토리얼 데이터 저장을 위한 동적 배열 생성 및 할당
	eg_QData = new CString*[eg_TurCnt];
	for(int i=0; i < eg_TurCnt; i++)
		eg_QData[i] = new CString[4];
	
	eg_QAnswer = new CString[eg_TurCnt];

	FILE* m_image_fp;
	char line_tmp[1024];
	char total_data[102400];
	char line_data[1024];
	if( strFilePath != "" ){
		m_image_fp = fopen(strFilePath.GetBuffer(100),"r");
  
		if(m_image_fp == NULL){
			AfxMessageBox("파일을 여는데에 실패했습니다.\n\n프로그램을 시작할 수 없습니다.");
			CDialog::OnClose();
			return true;
		}
		total_data[0] = '\0';
		while( !feof(m_image_fp) ){
			fgets(line_tmp,1024-5,m_image_fp); //자동으로 NULL문자 삽입됨
			
			AfxExtractSubString(eg_QData[line_count][0],line_tmp,0,';');
			AfxExtractSubString(eg_QData[line_count][1],line_tmp,1,';');
			AfxExtractSubString(eg_QData[line_count][2],line_tmp,2,';');
			AfxExtractSubString(eg_QData[line_count][3],line_tmp,3,';');
			
			line_count++;
		}
	}
	
	egSetFont("맑은 고딕", 150);
	egLoadImage(eg_QData[0][1]);
	m_edtAnswer.SetWindowText("");

	//MessageBoxA(_T("현재 프로그램은 다음 경로에서 실행중입니다.\n\n"+eg_RunPath));
	//MessageBoxA(_T("현재 열려는 튜토리얼명은 다음과 같습니다.\n\n"+eg_RunDirName));
	
	return TRUE;
}

void egEduClass::OnPaint(){
	CDialog::OnPaint();
}

void egEduClass::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(egEduClass)
	DDX_Control(pDX, IDENTER, m_btnAnswer);
	DDX_Control(pDX, IDC_EDIT, m_edtAnswer);
	DDX_Control(pDX, IDC_PICMAIN, m_picMain);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(egEduClass, CDialog)
	//{{AFX_MSG_MAP(egEduClass)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDENTER, OnEnter)
	ON_WM_CLOSE()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// egEduClass message handlers

void egEduClass::egLoadImage(CString strFileName){
	HBITMAP hBmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),(eg_RunPath+"\\"+eg_RunDirName+"\\"+strFileName+".bmp"),IMAGE_BITMAP,0,0,LR_LOADFROMFILE); 
	CDC pCD;
	/*
    BITMAP bm; 
    ::GetObject(hBmp, sizeof(BITMAP), &bm); 
     
    HDC hMemDC=::CreateCompatibleDC(NULL); 
     ::SelectObject(hMemDC,hBmp); 
	
    HDC hDC=pDC->GetSafeHdc(); 
    ::BitBlt(hDC,0,0,bm.bmWidth,bm.bmHeight, hMemDC,0,0, SRCCOPY); 
	*/

	m_picMain.SetBitmap(hBmp);
}

void egEduClass::egSetFont(CString tmpFontName, int tmpFontSize){
	m_font.CreatePointFont(tmpFontSize, TEXT(tmpFontName));
	GetDlgItem(IDC_EDIT)->SetFont(&m_font);
}

void egEduClass::egCountRow(CString tmpPath){
	FILE* m_image_fp;
	char line_tmp[1024];
	eg_QusCount = 0;
	eg_QusNowNum = 0;
	eg_TurCnt = 0;
	
	if( tmpPath != "" ){
		m_image_fp = fopen(tmpPath.GetBuffer(100),"r");
  
		if(m_image_fp == NULL){
			AfxMessageBox("파일을 여는데에 실패했습니다.");
		}else{
			while( !feof(m_image_fp) ){
				fgets(line_tmp,1024-5,m_image_fp); //자동으로 NULL문자 삽입됨
				eg_TurCnt++;
			}
			eg_QusCount = eg_TurCnt-1;
		}
	}
}

HBRUSH egEduClass::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	switch(nCtlColor){
		case CTLCOLOR_DLG:
			//pDC->SetBkMode(OPAQUE);
			pDC->SetTextColor(RGB(255, 255, 255));            //text color
			pDC->SetBkColor(RGB(2, 106, 81));
			hbr = CreateSolidBrush(RGB(2, 106, 81)); 
			break;
	}

	if(pWnd->GetDlgCtrlID() == IDC_ANSID){
		//pDC->SetBkMode(OPAQUE);
		pDC->SetTextColor(RGB(255, 255, 255));            //text color
		pDC->SetBkColor(RGB(2, 106, 81));
		hbr = CreateSolidBrush(RGB(2, 106, 81));
	}else if(pWnd->GetDlgCtrlID() == IDC_EDIT){
		//pDC->SetBkMode(OPAQUE);
		pDC->SetTextColor(RGB(255, 255, 255));            //text color
		pDC->SetBkColor(RGB(2, 106, 81));
		hbr = CreateSolidBrush(RGB(2, 106, 81));
    }
    
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void egEduClass::OnEnter(){
	if(eg_QusCount<eg_QusNowNum){
		CDialog::OnOK();
	}else{
		CString tmpAnswerText;
		m_edtAnswer.GetWindowText(tmpAnswerText);
		if(tmpAnswerText!=_T("")){
			if(eg_QusCount>eg_QusNowNum){
				// 다음 문제가 있을 때
				eg_QAnswer[eg_QusNowNum] = tmpAnswerText;
				eg_QusNowNum+=1;
				egLoadImage(eg_QData[eg_QusNowNum][1]);
			}else{
				// 다음 문제가 없을 때
				eg_QAnswer[eg_QusNowNum] = tmpAnswerText;
				eg_QusNowNum+=1;
				
				m_edtAnswer.EnableWindow(false);
				GetDlgItem(IDC_EDIT)->ShowWindow(SW_HIDE);
				m_btnAnswer.SetWindowText("닫기(&X)");
				
				egEduResult dlgResult;
				dlgResult.DoModal();
			}
			m_edtAnswer.SetWindowText("");
		}
	}
}

int egEduClass::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}

BOOL egEduClass::PreTranslateMessage(MSG* pMsg){
	if(pMsg->wParam == VK_RETURN){
		OnEnter();
		return TRUE;
	}else if(pMsg->wParam == VK_ESCAPE){
		return TRUE;
	}else{
		return CDialog::PreTranslateMessage(pMsg);
	}
}
