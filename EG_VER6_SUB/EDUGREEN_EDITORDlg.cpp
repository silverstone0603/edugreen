// EDUGREEN_EDITORDlg.cpp : implementation file
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
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
   CAboutDlg();

// Dialog Data
   //{{AFX_DATA(CAboutDlg)
   enum { IDD = IDD_ABOUTBOX };
   //}}AFX_DATA

   // ClassWizard generated virtual function overrides
   //{{AFX_VIRTUAL(CAboutDlg)
   protected:
   virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
   //}}AFX_VIRTUAL

// Implementation
protected:
   //{{AFX_MSG(CAboutDlg)
   //}}AFX_MSG
   DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
   //{{AFX_DATA_INIT(CAboutDlg)
   //}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
   CDialog::DoDataExchange(pDX);
   //{{AFX_DATA_MAP(CAboutDlg)
   //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
   //{{AFX_MSG_MAP(CAboutDlg)
      // No message handlers
   //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEDUGREEN_EDITORDlg dialog

IMPLEMENT_DYNAMIC(CEDUGREEN_EDITORDlg, CDialog);


//############# 추가 버튼
CEDUGREEN_EDITORDlg::CEDUGREEN_EDITORDlg(CWnd* pParent /*=NULL*/)
   : CDialog(CEDUGREEN_EDITORDlg::IDD, pParent)
{
   //{{AFX_DATA_INIT(CEDUGREEN_EDITORDlg)
	//}}AFX_DATA_INIT
   // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
   m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
   m_pAutoProxy = NULL;
}

CEDUGREEN_EDITORDlg::~CEDUGREEN_EDITORDlg()
{
   // If there is an automation proxy for this dialog, set
   //  its back pointer to this dialog to NULL, so it knows
   //  the dialog has been deleted.
   if (m_pAutoProxy != NULL)
      m_pAutoProxy->m_pDialog = NULL;
}

void CEDUGREEN_EDITORDlg::DoDataExchange(CDataExchange* pDX)
{
   CDialog::DoDataExchange(pDX);
   //{{AFX_DATA_MAP(CEDUGREEN_EDITORDlg)
	DDX_Control(pDX, IDC_EDIT6, m_text);
   DDX_Control(pDX, IDC_ADD, m_Add);
   DDX_Control(pDX, IDC_EDIT5, m_qDirName);
   DDX_Control(pDX, IDC_EDIT4, m_qDesc);
   DDX_Control(pDX, IDC_EDIT3, m_qAnswer);
   DDX_Control(pDX, IDC_EDIT2, m_qImgSrc);
   DDX_Control(pDX, IDC_EDIT1, m_qType);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEDUGREEN_EDITORDlg, CDialog)
   //{{AFX_MSG_MAP(CEDUGREEN_EDITORDlg)
   ON_WM_SYSCOMMAND()
   ON_WM_PAINT()
   ON_WM_QUERYDRAGICON()
   ON_WM_CLOSE()
   ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_EN_CHANGE(IDC_EDIT6, OnChangeEdit6)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEDUGREEN_EDITORDlg message handlers

BOOL CEDUGREEN_EDITORDlg::OnInitDialog()
{
   CDialog::OnInitDialog();

   // Add "About..." menu item to system menu.

   // IDM_ABOUTBOX must be in the system command range.
   ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
   ASSERT(IDM_ABOUTBOX < 0xF000);

   CMenu* pSysMenu = GetSystemMenu(FALSE);
   if (pSysMenu != NULL)
   {
      CString strAboutMenu;
      strAboutMenu.LoadString(IDS_ABOUTBOX);
      if (!strAboutMenu.IsEmpty())
      {
         pSysMenu->AppendMenu(MF_SEPARATOR);
         pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
      }
   }

   // Set the icon for this dialog.  The framework does this automatically
   //  when the application's main window is not a dialog
   SetIcon(m_hIcon, TRUE);         // Set big icon
   SetIcon(m_hIcon, FALSE);      // Set small icon
   
   // TODO: Add extra initialization here

   TCHAR path[_MAX_PATH];

   GetModuleFileName(NULL, path, sizeof path);
   CString strPath = path;

   int i = strPath.ReverseFind('\\');//실행 파일 이름을 지우기 위해서 왼쪽에 있는 '/'를 찾는다.

   egRunPath = strPath.Left(i); //뒤에 있는 현재 실행 파일 이름을 지우고 전역 변수에 경로를 저장

   return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEDUGREEN_EDITORDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
   if ((nID & 0xFFF0) == IDM_ABOUTBOX)
   {
      CAboutDlg dlgAbout;
      dlgAbout.DoModal();
   }
   else
   {
      CDialog::OnSysCommand(nID, lParam);
   }
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEDUGREEN_EDITORDlg::OnPaint() 
{
   if (IsIconic())
   {
      CPaintDC dc(this); // device context for painting

      SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

      // Center icon in client rectangle
      int cxIcon = GetSystemMetrics(SM_CXICON);
      int cyIcon = GetSystemMetrics(SM_CYICON);
      CRect rect;
      GetClientRect(&rect);
      int x = (rect.Width() - cxIcon + 1) / 2;
      int y = (rect.Height() - cyIcon + 1) / 2;

      // Draw the icon
      dc.DrawIcon(x, y, m_hIcon);
   }
   else
   {
      CDialog::OnPaint();
   }
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEDUGREEN_EDITORDlg::OnQueryDragIcon()
{
   return (HCURSOR) m_hIcon;
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void CEDUGREEN_EDITORDlg::OnClose() 
{
   if (CanExit())
      CDialog::OnClose();
}

void CEDUGREEN_EDITORDlg::OnOK() 
{
   if (CanExit())
      CDialog::OnOK();
}

void CEDUGREEN_EDITORDlg::OnCancel() 
{
   if (CanExit())
      CDialog::OnCancel();
}

BOOL CEDUGREEN_EDITORDlg::CanExit()
{
   // If the proxy object is still around, then the automation
   //  controller is still holding on to this application.  Leave
   //  the dialog around, but hide its UI.
   if (m_pAutoProxy != NULL)
   {
      ShowWindow(SW_HIDE);
      return FALSE;
   }

   return TRUE;
}

void CEDUGREEN_EDITORDlg::OnAdd() 
{
   CString tmpStrDirName;
   CString tmpStr;
   CString tmpStr1;
   CString tmpStr2;
   CString tmpStr3;

   int tmpDirChk;

   m_qDirName.GetWindowText(tmpStrDirName); //폴더    이름 변수에 임시 저장
   tmpDirChk = DirCheck(egRunPath+"\\"+tmpStrDirName); // 폴더 여부 확인 ?
   
   if (tmpDirChk==1){ //폴더 존재 여부 확인
      m_qType.GetWindowText(tmpStr); 
      if (tmpStr!="" && (tmpStr=="chk" || tmpStr=="inp" || tmpStr=="line")){ //문제 타입 확인 
         m_qImgSrc.GetWindowText(tmpStr); // tmpStr 에다 m_qImgSrc멤버가 지정된 text값을 넣어준다

         tmpDirChk = DirCheck(egRunPath+"\\"+tmpStrDirName+"\\"+tmpStr+".bmp");  //이미지 파일 확인 
         m_qAnswer.GetWindowText(tmpStr2); // tmpStr2 에다 m_qAnswer멤버가 지정된 text값을 넣어준다
         m_qDesc.GetWindowText(tmpStr3); // tmpStr3 에다 m_qDesc멤버가 지정된 text값을 넣어준다
         if (tmpDirChk==1){
            if (tmpStr2 != "" && tmpStr3 != ""){
               MessageBoxA(_T("Okay Next.")); // 위의 조건문을 충족시키면 메시지박스를 띄운다
				m_qType.GetWindowText(tmpStr); // tmpStr 에다 m_qType멤버가 지정된 text값을 넣어준다
				m_qImgSrc.GetWindowText(tmpStr1); // tmpStr1 에다 m_qImgSrc멤버가 지정된 text값을 넣어준다
				egQArray[egCnt][0] = tmpStr; // 2차원배열 두번째 줄부터 입력받은 값을 넣어준다.
				egQArray[egCnt][1] = tmpStr1;
				egQArray[egCnt][2] = tmpStr2;
				egQArray[egCnt][3] = tmpStr3;
               //char str[100];
               //sprintf(str,"%d",egCnt++);
				egCnt++;
               //추가하고 나서 text 리셋 
               m_qDirName.SetReadOnly(TRUE); // 처음 추가를 누르게되면 폴더명 과정 만든이의 텍스트 박스를 수정 불가능상태로 변경
               m_qType.SetWindowText(""); // 추가를 누르게되면 빈값으로 바꿔준다.
               m_qImgSrc.SetWindowText("");
               m_qAnswer.SetWindowText("");
               m_qDesc.SetWindowText("");
            }else{
               MessageBoxA(_T("정답 또는 해설이 비어있습니다. 다시 확인 해주십시오."));
            }
         }else{
            MessageBoxA(_T("해당 이름으로 된 이미지 파일이 폴더안에 없습니다."));
         }
      }else{
         MessageBoxA(_T("문제 타입이 다릅니다. 다시 입력해주세요."));
      }
   }else{
      MessageBoxA(_T("디렉토리가 프로그램 실행 폴더에 없습니다."));
   }


}

int CEDUGREEN_EDITORDlg::DirCheck(CString strDir) {
   CFileFind file;
   //CString strFile = "\\*.*";
   if(file.FindFile(strDir)>0){
      return 1; //있을때
   }else{
      return 2; //없을때
   }
}

void CEDUGREEN_EDITORDlg::OnSave() 
{
	MessageBox("Save Success");
	CString tmpStrDirName;
   m_qDirName.GetWindowText(tmpStrDirName);
   CString str = _T(egRunPath+"\\"+tmpStrDirName+"\\turdata.ecf");

	char tmp_total[102400]="";
	char tmp_data2[1024];
	int i,j;
	for(i=0; i<100;i++){ // 2차원배열 안에 저장된 데이터를 tmp_total에 넣는 과정 구분은 세미콜론으로 짓는다
		if(egQArray[i][0] != ""){
		for(j=0;j<4;j++){
			sprintf(tmp_data2,"%s;",egQArray[i][j]);
			strcat(tmp_total,tmp_data2);
		} 
		strcat(tmp_total,_T("\r\n"));
		}
	}

	CString strValue = tmp_total; // strValue에 tmp_total 값을 넣어준다
	SetDlgItemText(IDC_EDIT6,strValue); // strValue에 저장된 값을 IDC_EDIT6에 보여준다

	FILE *fp; // 파일 입출력 부분
    fp = fopen(str,"w");
 
    fprintf(fp,"%s",tmp_total);
    fclose(fp);

}

void CEDUGREEN_EDITORDlg::OnChangeEdit6() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CEDUGREEN_EDITORDlg::OnButton1() 
{
	MessageBoxA(_T("개발중에 있습니다"));
	
}
