// EDUGREENDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EDUGREEN.h"
#include "EDUGREENDlg.h"
#include "egEduClass.h"
#include "egEduResult.h"
#include "DlgProxy.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// 전역 변수
CString strPath; // 프로그램 실행 경로
CString strAllPath;
CFileFind ffMain; //검색 클래스
BOOL bWorking; //CfileFind는 파일, 디렉터리가 존재하면 True 반환

CString strFileName;
CString strDirName;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog{
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
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
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

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEDUGREENDlg dialog

IMPLEMENT_DYNAMIC(CEDUGREENDlg, CDialog);

CEDUGREENDlg::CEDUGREENDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEDUGREENDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEDUGREENDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CEDUGREENDlg::~CEDUGREENDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void CEDUGREENDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEDUGREENDlg)
	DDX_Control(pDX, IDC_EDULIST, m_EduList);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEDUGREENDlg, CDialog)
	//{{AFX_MSG_MAP(CEDUGREENDlg)
	ON_BN_CLICKED(IDCONTINUE, OnContinue)
	ON_BN_CLICKED(IDRELOAD, OnReload)
	ON_CBN_EDITCHANGE(IDC_EDULIST, OnEditchangeEdulist)
	ON_CBN_SELCHANGE(IDC_EDULIST, OnSelchangeEdulist)
	ON_WM_SYSCOMMAND()
	ON_WM_QUERYDRAGICON()
	ON_WM_PAINT()
	ON_WM_CLOSE()
	ON_WM_CREATE()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEDUGREENDlg message handlers

BOOL CEDUGREENDlg::OnInitDialog(){
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.
	
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL){
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty()){
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, TRUE);			// Set small icon
	
	// 현재 프로그램이 실행중인 디렉토리 경로 불러옴
	TCHAR path[_MAX_PATH];
	GetModuleFileName(NULL, path, sizeof path);
	strPath = path;

	int i = strPath.ReverseFind('\\');//실행 파일 이름을 지우기 위해서 왼쪽에 있는 '/'를 찾는다.
	strPath = strPath.Left(i);// 뒤에 있는 현재 실행 파일 이름을 지운다.

	eg_RunPath = _T(strPath); // 현재 실행중인 프로그램 경로 추가

	//AfxMessageBox & MessageBoxA (strPath);
	
	// 튜토리얼 폴더 확인 후 리스트에 추가하기
	strAllPath = _T(strPath) + _T("\\*.*");
	CEDUGREENDlg::OnReload();
	m_EduList.SetCurSel(0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEDUGREENDlg::OnSysCommand(UINT nID, LPARAM lParam){
	if ((nID & 0xFFF0) == IDM_ABOUTBOX){
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}else{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEDUGREENDlg::OnPaint(){
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
HCURSOR CEDUGREENDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void CEDUGREENDlg::OnClose(){
	if (CanExit())
		CDialog::OnClose();
}

BOOL CEDUGREENDlg::CanExit(){
	// If the proxy object is still around, then the automation
	//  controller is still holding on to this application.  Leave
	//  the dialog around, but hide its UI.
	if (m_pAutoProxy != NULL){
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}

void CEDUGREENDlg::OnContinue(){

	CString tmpStrDirName;
	m_EduList.GetLBText(m_EduList.GetCurSel(),tmpStrDirName);

	CString tmpStrFilePath = _T(strPath+"\\"+tmpStrDirName+"\\turdata.ecf");
	CFileStatus status;
	
	if(CFile::GetStatus(tmpStrFilePath, status)){
		// 존재할 경우
		if (CanExit()){
			eg_RunDirName = _T(tmpStrDirName);
			egEduClass dlgEdu;
			dlgEdu.DoModal();
			//dlgEdu.Create(IDD_EDU);
			//dlgEdu.ShowWindow(SW_SHOW);
		}
	}else{
		// 존재하지 않을 경우
		AfxMessageBox(_T("튜토리얼 로딩에 필요한 ECF 파일이 없습니다.\n확인 후 다시 시도 해주십시오."));
	}
	
	/*
	// 파일 정보 띄우기
	CString strFileName;
	CFileDialog fDlg(TRUE, NULL, NULL, OFN_READONLY,"Edugreen Contents File (*.ecf)|*.ecf||");
	
	int iRet = fDlg.DoModal();
	strFileName = fDlg.GetPathName();
	if(iRet != IDOK){
		AfxMessageBox("파일 지정 취소!");	
		return;
	}else{
		AfxMessageBox(strFileName);
		return;
	}
	*/
}


/////////////////////////////////////////////////////////////////////////////
// Class Fnc.

/*
void CEDUGREENDlg::GetFileList(CComboBox* cbListBox, CString strFolder){   
	CFileFind file;
	BOOL b = file.FindFile(strFolder + _T("\\*.*"));		// 모든 확장자를 다 사용.
//	CString strMusicFilter = ".MP3.OGG.WMA.WAV";			// 필터링 하고 싶으면 이렇게 쓰면 됨
	CString strFolderItem, strFileExt, strTempString;  

	while(b)  
	{  
		b = file.FindNextFile();  
		if(file.IsDirectory() && !file.IsDots())			// 디렉토리 발견시 
		{  
			strFolderItem = file.GetFilePath();  
			CEDUGREENDlg::GetFileList(cbListBox, strFolderItem);	// 하위폴더를 검색하기 위해 재귀호출 발생  
		} 
		strFolderItem = file.GetFilePath();  
		strFileExt = strFolderItem.Mid(strFolderItem.ReverseFind('.'));		// 확장자만 추출한다. 

		if (!file.IsDots())									// 파일 탐색 필터 정의에따라 해당 StringList에 추가
		{  
			strFileExt.MakeUpper();							// strFileExt 에는 확장자 (.EXE 형태) 가 들어옴. 비교위해 대문자화 함
			if( file.IsDirectory() ) continue;				// 폴더만 남는 경우는 넣으면 안됨 
			//cbListBox.AddString(strFolderItem); 
		} 
	}
}
*/

void CEDUGREENDlg::OnReload(){
    CString tmpFindPath, tmpReadPath, tmpDirName, tmpFileName;
    BOOL bContinue;
 
    tmpFindPath = strAllPath;                // 탐색할 폴더의 경로
 
    CFileFind filefind;
    bContinue = filefind.FindFile(tmpFindPath);        // 첫번째 파일 가져오기
	
	m_EduList.ResetContent();

    if(!bContinue){         // 파일이 없으면 종료
        filefind.Close();
        return;
    }
	
    while(bContinue){        // 파일 있을때 까지 루프
        bContinue = filefind.FindNextFile();            // 다음 파일 이름 가져오기
        tmpReadPath = filefind.GetFileName();
 
        if(filefind.IsDirectory()){                             // 폴더일경우
            if(tmpReadPath != "." && tmpReadPath != ".."){          
                tmpDirName = tmpReadPath;                // 이후에 폴더에 대한 처리를 해주시길...
				m_EduList.AddString(tmpDirName);
			}
        }else{                                                       // 파일일경우
            tmpReadPath = filefind.GetFileName();
            tmpFileName = tmpReadPath;                    // 이후에 파일에 대한 처리를 해주시고요.
			//m_EduList.AddString(tmpFileName);
        }
    }
	m_EduList.SetCurSel(0);
    filefind.Close();
}

void CEDUGREENDlg::OnEditchangeEdulist(){
	
}

void CEDUGREENDlg::OnSelchangeEdulist() {
	/*
	// 선택된 항목 메시지 띄우기
	CString tmpStrData;
	m_EduList.GetLBText(m_EduList.GetCurSel(),tmpStrData);
	MessageBoxA( _T(tmpStrData), _T("텍스트"));
	*/
}

int CEDUGREENDlg::OnCreate(LPCREATESTRUCT lpCreateStruct){
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}

HBRUSH CEDUGREENDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

	if(pWnd->GetDlgCtrlID() == IDC_STATIC){
		//pDC->SetBkMode(OPAQUE);
		pDC->SetTextColor(RGB(255, 255, 255));            //text color
		pDC->SetBkColor(RGB(2, 106, 81));
		hbr = CreateSolidBrush(RGB(2, 106, 81));
    }

	// TODO: Return a different brush if the default is not desired
	return hbr;
}

HBRUSH CAboutDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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
		case CTLCOLOR_STATIC:
			//pDC->SetBkMode(OPAQUE);
			pDC->SetTextColor(RGB(255, 255, 255));            //text color
			pDC->SetBkColor(RGB(2, 106, 81));
			hbr = CreateSolidBrush(RGB(2, 106, 81)); 
			break;
	}

	if(pWnd->GetDlgCtrlID() == IDC_STATIC){
		//pDC->SetBkMode(OPAQUE);
		pDC->SetTextColor(RGB(255, 255, 255));            //text color
		pDC->SetBkColor(RGB(2, 106, 81));
		hbr = CreateSolidBrush(RGB(2, 106, 81));
    }

	// TODO: Return a different brush if the default is not desired
	return hbr;
}
