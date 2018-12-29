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
// ���� ����
CString strPath; // ���α׷� ���� ���
CString strAllPath;
CFileFind ffMain; //�˻� Ŭ����
BOOL bWorking; //CfileFind�� ����, ���͸��� �����ϸ� True ��ȯ

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
	
	// ���� ���α׷��� �������� ���丮 ��� �ҷ���
	TCHAR path[_MAX_PATH];
	GetModuleFileName(NULL, path, sizeof path);
	strPath = path;

	int i = strPath.ReverseFind('\\');//���� ���� �̸��� ����� ���ؼ� ���ʿ� �ִ� '/'�� ã�´�.
	strPath = strPath.Left(i);// �ڿ� �ִ� ���� ���� ���� �̸��� �����.

	eg_RunPath = _T(strPath); // ���� �������� ���α׷� ��� �߰�

	//AfxMessageBox & MessageBoxA (strPath);
	
	// Ʃ�丮�� ���� Ȯ�� �� ����Ʈ�� �߰��ϱ�
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
		// ������ ���
		if (CanExit()){
			eg_RunDirName = _T(tmpStrDirName);
			egEduClass dlgEdu;
			dlgEdu.DoModal();
			//dlgEdu.Create(IDD_EDU);
			//dlgEdu.ShowWindow(SW_SHOW);
		}
	}else{
		// �������� ���� ���
		AfxMessageBox(_T("Ʃ�丮�� �ε��� �ʿ��� ECF ������ �����ϴ�.\nȮ�� �� �ٽ� �õ� ���ֽʽÿ�."));
	}
	
	/*
	// ���� ���� ����
	CString strFileName;
	CFileDialog fDlg(TRUE, NULL, NULL, OFN_READONLY,"Edugreen Contents File (*.ecf)|*.ecf||");
	
	int iRet = fDlg.DoModal();
	strFileName = fDlg.GetPathName();
	if(iRet != IDOK){
		AfxMessageBox("���� ���� ���!");	
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
	BOOL b = file.FindFile(strFolder + _T("\\*.*"));		// ��� Ȯ���ڸ� �� ���.
//	CString strMusicFilter = ".MP3.OGG.WMA.WAV";			// ���͸� �ϰ� ������ �̷��� ���� ��
	CString strFolderItem, strFileExt, strTempString;  

	while(b)  
	{  
		b = file.FindNextFile();  
		if(file.IsDirectory() && !file.IsDots())			// ���丮 �߽߰� 
		{  
			strFolderItem = file.GetFilePath();  
			CEDUGREENDlg::GetFileList(cbListBox, strFolderItem);	// ���������� �˻��ϱ� ���� ���ȣ�� �߻�  
		} 
		strFolderItem = file.GetFilePath();  
		strFileExt = strFolderItem.Mid(strFolderItem.ReverseFind('.'));		// Ȯ���ڸ� �����Ѵ�. 

		if (!file.IsDots())									// ���� Ž�� ���� ���ǿ����� �ش� StringList�� �߰�
		{  
			strFileExt.MakeUpper();							// strFileExt ���� Ȯ���� (.EXE ����) �� ����. ������ �빮��ȭ ��
			if( file.IsDirectory() ) continue;				// ������ ���� ���� ������ �ȵ� 
			//cbListBox.AddString(strFolderItem); 
		} 
	}
}
*/

void CEDUGREENDlg::OnReload(){
    CString tmpFindPath, tmpReadPath, tmpDirName, tmpFileName;
    BOOL bContinue;
 
    tmpFindPath = strAllPath;                // Ž���� ������ ���
 
    CFileFind filefind;
    bContinue = filefind.FindFile(tmpFindPath);        // ù��° ���� ��������
	
	m_EduList.ResetContent();

    if(!bContinue){         // ������ ������ ����
        filefind.Close();
        return;
    }
	
    while(bContinue){        // ���� ������ ���� ����
        bContinue = filefind.FindNextFile();            // ���� ���� �̸� ��������
        tmpReadPath = filefind.GetFileName();
 
        if(filefind.IsDirectory()){                             // �����ϰ��
            if(tmpReadPath != "." && tmpReadPath != ".."){          
                tmpDirName = tmpReadPath;                // ���Ŀ� ������ ���� ó���� ���ֽñ�...
				m_EduList.AddString(tmpDirName);
			}
        }else{                                                       // �����ϰ��
            tmpReadPath = filefind.GetFileName();
            tmpFileName = tmpReadPath;                    // ���Ŀ� ���Ͽ� ���� ó���� ���ֽð��.
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
	// ���õ� �׸� �޽��� ����
	CString tmpStrData;
	m_EduList.GetLBText(m_EduList.GetCurSel(),tmpStrData);
	MessageBoxA( _T(tmpStrData), _T("�ؽ�Ʈ"));
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
