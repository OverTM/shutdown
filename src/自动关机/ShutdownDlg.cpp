
// ShutdownDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�Զ��ػ�.h"
#include "ShutdownDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSysteminfo();
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	ON_BN_CLICKED(IDC_SystemInfo, &CAboutDlg::OnBnClickedSysteminfo)
END_MESSAGE_MAP()


// CShutdownDlg �Ի���




CShutdownDlg::CShutdownDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShutdownDlg::IDD, pParent)
	, m_Bool(true)
	, m_LongTime(0)
	, m_TomorrowBool(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShutdownDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Timing, m_Timing);
	DDX_Control(pDX, IDC_EDIT, m_Second);
	DDX_Control(pDX, IDC_CurrentDate, m_CurrentDate);
	DDX_Control(pDX, IDC_EDITTime, m_CEdit);
	DDX_Control(pDX, IDC_EDITBack, m_BackTime);
	DDX_Control(pDX, IDC_About, m_btnSet);
}

BEGIN_MESSAGE_MAP(CShutdownDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_About, &CShutdownDlg::OnBnClickedAbout)
	//	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_Timing, &CShutdownDlg::OnDtnDatetimechangeTiming)
	ON_BN_CLICKED(IDC_xTiming, &CShutdownDlg::OnBnClickedxtiming)
	ON_BN_CLICKED(IDC_xSecond, &CShutdownDlg::OnBnClickedxsecond)
	ON_BN_CLICKED(IDC_Start, &CShutdownDlg::OnBnClickedStart)
	ON_WM_TIMER()
//	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_Timing, &CShutdownDlg::OnDtnDatetimechangeTiming)
//	ON_EN_CHANGE(IDC_EDIT, &CShutdownDlg::OnEnChangeEdit)
ON_BN_CLICKED(IDC_Tomorrow, &CShutdownDlg::OnBnClickedTomorrow)
ON_BN_CLICKED(IDC_Cancel, &CShutdownDlg::OnBnClickedCancel)
//ON_BN_CLICKED(IDC_Hide, &CShutdownDlg::OnBnClickedHide)
ON_BN_CLICKED(IDC_Hide, &CShutdownDlg::OnBnClickedHide)
END_MESSAGE_MAP()


// CShutdownDlg ��Ϣ�������

BOOL CShutdownDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//�Ի����ʼ�������ö�ʱ��1�����������Ҳ�ʱ����ʾ
	SetTimer(Timer1,1000,0);
	m_BackTime.SetWindowText(_T("δ����"));
	m_btnSet.SetCheck(true);

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CShutdownDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CShutdownDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CShutdownDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CShutdownDlg::OnBnClickedAbout()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CAboutDlg about;
	about.DoModal();
}

void CShutdownDlg::OnBnClickedxtiming()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Bool = true;
}

void CShutdownDlg::OnBnClickedxsecond()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Bool = false;
}

void CShutdownDlg::OnBnClickedStart()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_Bool)
	{
		SYSTEMTIME stSet;
		SYSTEMTIME stCurrent;
		GetLocalTime(&stCurrent);
		m_Timing.GetTime(&stSet);
		int stHour = stSet.wHour - stCurrent.wHour;
		int stMinute = stSet.wMinute - stCurrent.wMinute;
		int stSecond = stSet.wSecond - stCurrent.wSecond;
		if (m_TomorrowBool)
		{
			stHour = stHour + 24;
		}
		int sec = (stHour * 3600 + stMinute * 60 + stSecond) * 1000;
		m_LongTime = sec/1000;
		if (sec <= 0)
		{
			MessageBox(_T("���õĹػ�ʱ���Ѿ���ȥ�ˣ�"),_T("������"));
			return;
		}
		//������ʱ��2��������sec�����ϵͳ�ػ�
		SetTimer(Timer2,sec,0);
		//������ʱ��3�����õ���ʱ����
		SetTimer(Timer3,1000,0);
	}
	else
	{
		CString str;
		m_Second.GetWindowText(str);
		if (str == "")
		{
			MessageBox(_T("��Ҫ�����ӳٹػ��ķ��Ӳ��У�"),_T("������"));
			return;
		}
		long sec = StrToInt(str) * 60000;
		m_LongTime = sec/1000;
		//������ʱ��2��������sec�����ϵͳ�ػ�
		SetTimer(Timer2,sec,0);
		//������ʱ��3�����õ���ʱ����
		SetTimer(Timer3,1000,0);
	}
}

BOOL CShutdownDlg::WinShutDown(UINT uFags)
{
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;
	OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES|TOKEN_QUERY,&hToken);
	LookupPrivilegeValue(NULL,SE_SHUTDOWN_NAME,&tkp.Privileges[0].Luid);
	tkp.PrivilegeCount=1;
	tkp.Privileges[0].Attributes=SE_PRIVILEGE_ENABLED;
	//ȡ�ý�����Ȩ
	AdjustTokenPrivileges(hToken,FALSE,&tkp,0,(PTOKEN_PRIVILEGES)NULL,0);
	return ExitWindowsEx(uFags,NULL);
}


void CShutdownDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString str;
	SYSTEMTIME st;
	CString lSeccond;
	switch (nIDEvent)
	{
	//ʵ���Ҳ���ʾϵͳʱ�䣨�����Ǿ�̬�ģ�
	case Timer1: 
		GetLocalTime(&st);
		str.Format(L"%d:%d:%d",st.wHour,st.wMinute,st.wSecond);
		m_CEdit.SetWindowText(str);
		break;
	//ʵ�ֶ�ʱ�ػ�
	case Timer2:
		WinShutDown(EWX_SHUTDOWN);
		break;
	//ʵ�ֵ���ʱ��ʾ
	case Timer3:
		lSeccond.Format(L"%ld",--m_LongTime);
		m_BackTime.SetWindowText(lSeccond);
	default:
		break;
	}

	CDialog::OnTimer(nIDEvent);
}


void CShutdownDlg::OnBnClickedTomorrow()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_TomorrowBool = !m_TomorrowBool;
}

void CShutdownDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	KillTimer(Timer3);
	KillTimer(Timer2);
	m_BackTime.SetWindowText(_T("δ����"));
}

void CAboutDlg::OnBnClickedSysteminfo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("��δʵ�ֹ���!"),_T("��ܰ��ʾ"));
}

void CShutdownDlg::OnBnClickedHide()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("��δʵ�ֹ���!"),_T("��ܰ��ʾ"));
}
