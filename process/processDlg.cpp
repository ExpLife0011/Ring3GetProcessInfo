
// processDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "process.h"
#include "processDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
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
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CprocessDlg �Ի���



CprocessDlg::CprocessDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CprocessDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CprocessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_MAIN, m_TabMain);
}

BEGIN_MESSAGE_MAP(CprocessDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_MAIN, &CprocessDlg::OnTcnSelchangeTabMain)
	ON_COMMAND(IDM_THREAD, &CprocessDlg::OnThread)
END_MESSAGE_MAP()


// CprocessDlg ��Ϣ�������
static UINT indicators[] = {
IDS_CONTENT,IDS_TOTAL,
};

BOOL CprocessDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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
	//m_TabMain.Create(TCS_TABS | TCS_FIXEDWIDTH | WS_CHILD | WS_VISIBLE, rtWnd, this, IDC_TAB_MAIN);
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	MoveWindow(0, 0, x-100, y-100, TRUE);

	RECT rtTab ;
	this->GetClientRect(&rtTab);
	//rtTab.bottom -= 20;
	m_TabMain.MoveWindow(&rtTab);

	m_TabMain.InsertItem(0, _T("����"));
	m_TabMain.InsertItem(1, _T("�߳�"));
	m_TabMain.InsertItem(2, _T("��"));
	m_TabMain.InsertItem(3, _T("�ڴ��ҳ"));
	//m_TabMain.InsertItem(4, _T("��ҵ"));
	//m_TabMain.InsertItem(5, _T("�ں�"));
	m_TabMain.SetMinTabWidth(100);

	//////////////////////////////////////////////////////////////////////////
	m_DlgProc.Create(IDD_DIALOG_PROC, &m_TabMain);	
	m_DlgThread.Create(IDD_DIALOG_THREAD, &m_TabMain);
	m_DlgHeap.Create(IDD_DIALOG_HEAP, &m_TabMain);
	m_DlgPage.Create(IDD_DIALOG_PAGES, &m_TabMain);
	m_pDlgTabs[0] = &m_DlgProc;
	m_pDlgTabs[1] = &m_DlgThread;
	m_pDlgTabs[2] = &m_DlgHeap;
	m_pDlgTabs[3] = &m_DlgPage;

	m_TabMain.GetClientRect(&rtTab);
	rtTab.top += 20;
	RECT rt = rtTab;
	int width = rt.right- rt.left;
	int height = rt.bottom - rt.top;
	for(int i=0; i<4; i++) {
		m_pDlgTabs[i]->MoveWindow(&rt, TRUE);
	}
	//m_DlgProc.MoveWindow(rt.left, rt.top, width, height, TRUE);

	m_DlgProc.ShowWindow(SW_SHOW);
	m_TabNumber = 0;

	//m_StatusBar.Create(this);
	//m_StatusBar.SetIndicators(indicators, 2);
	
	//CRect rect;
	//GetClientRect(rect);

	//int strPartDim[4]= {100, 280}; //�ָ�����
	//m_StatusBar.GetStatusBarCtrl().SetParts(2, strPartDim);
	//m_StatusBar.SetPaneInfo(0, IDS_CONTENT, SBPS_NORMAL, 100);
	//m_StatusBar.SetPaneInfo(1, IDS_TOTAL, SBPS_NORMAL, 100);
	//m_StatusBar.SetPaneText(0,_T("����"));
	//m_StatusBar.SetPaneText(1,_T("����:100"));

	//m_StatusBar.MoveWindow(0, rect.bottom-20, rect.right, 20);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CprocessDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CprocessDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}

	CRect rect;
	GetClientRect(rect);
	if (m_StatusBar)
		m_StatusBar.MoveWindow(0, rect.bottom-20, rect.right, 20);
	
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CprocessDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CprocessDlg::OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	m_pDlgTabs[m_TabNumber]->ShowWindow(SW_HIDE);

	m_TabNumber = m_TabMain.GetCurSel();

	m_pDlgTabs[m_TabNumber]->ShowWindow(SW_SHOW);
	
	::SendMessage(m_pDlgTabs[m_TabNumber]->m_hWnd, WM_LIST_INFO, m_DlgProc.m_CurItemPID, 0);
	m_DlgProc.m_CurItemPID = 4;

	*pResult = 0;
}


void CprocessDlg::OnThread()
{
	// TODO: �ڴ���������������
	m_TabMain.SetCurSel(1);
	//m_DlgThread
}
