// DlgModule.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "process.h"
#include "DlgModule.h"
#include "afxdialogex.h"

#include "DlgProc.h"
// CDlgModule �Ի���

IMPLEMENT_DYNAMIC(CDlgModule, CDialogEx)

CDlgModule::CDlgModule(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgModule::IDD, pParent)
{

}

CDlgModule::~CDlgModule()
{
}

void CDlgModule::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListModule);
}


BEGIN_MESSAGE_MAP(CDlgModule, CDialogEx)
	ON_MESSAGE(WM_INSERT_MODULE, &CDlgModule::OnInsertModule)
	ON_MESSAGE(WM_LIST_INFO, &CDlgModule::ListInfo)
END_MESSAGE_MAP()


// CDlgModule ��Ϣ�������


BOOL CDlgModule::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//m_ListModule.InsertColumn(0, _T("MID"), LVCFMT_LEFT, 50, 0);
	m_ListModule.InsertColumn(0, _T("����"), LVCFMT_LEFT, 100, 0);
	m_ListModule.InsertColumn(1, _T("ȫ��������"), LVCFMT_LEFT, 100, 0);
	m_ListModule.InsertColumn(2, _T("����������"), LVCFMT_LEFT, 100, 0);
	m_ListModule.InsertColumn(3, _T("����ַ"), LVCFMT_LEFT, 50, 0);
	m_ListModule.InsertColumn(4, _T("��С"), LVCFMT_LEFT, 100, 0);
	m_ListModule.InsertColumn(5, _T("���"), LVCFMT_LEFT, 100, 0);
	m_ListModule.InsertColumn(6, _T("·��"), LVCFMT_LEFT, 200, 0);

	m_ListModule.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	dlgHwnd = m_hWnd;

// 	RECT rt;
// 	GetParent()->GetClientRect(&rt);
// 	rt.left += 50;
// 	rt.right -= 50;
// 	rt.top += 30;
// 	rt.bottom -= 30;
// 	MoveWindow(&rt);

	ListInfo(CDlgProc::m_CurItemPID, 0);
	CDlgProc::m_CurItemPID = 4;

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

HWND CDlgModule::dlgHwnd = NULL;
void CDlgModule::ListModule(PVOID info)
{
	::SendMessage(dlgHwnd, WM_INSERT_MODULE, (WPARAM)info, 0);
}

LRESULT CDlgModule::OnInsertModule(WPARAM wParam, LPARAM lParam)
{
	PMODULEENTRY32 me32 = (PMODULEENTRY32)wParam;
	CString text;
	TCHAR tszExe[MAX_PATH] = {0};

	text.Format(_T("%ws"), me32->szModule);
	m_ListModule.InsertItem(0, text.GetBuffer());
	text.Format(_T("%d"), me32->GlblcntUsage);
	m_ListModule.SetItemText(0, 1, text.GetBuffer());
	text.Format(_T("%d"), me32->ProccntUsage);
	m_ListModule.SetItemText(0, 2, text.GetBuffer());
	text.Format(_T("0x%08X"), me32->modBaseAddr);
	m_ListModule.SetItemText(0, 3, text.GetBuffer());
	text.Format(_T("%d"), me32->modBaseSize);
	m_ListModule.SetItemText(0, 4, text.GetBuffer());
	text.Format(_T("0x%08X"), me32->hModule);
	m_ListModule.SetItemText(0, 5,  text.GetBuffer());
	
	//m_ListModule.SetItemText(0, 6,  text.GetBuffer());
	text.Format(_T("%ws"), me32->szExePath);
	m_ListModule.SetItemText(0, 6,  text.GetBuffer());

	return 1;
}

LRESULT CDlgModule::ListInfo(WPARAM wParam, LPARAM lParam)
{
	m_ListModule.DeleteAllItems();
	
	ProcAnalyze pa;
	pa.ListModule(ListModule, wParam);

	return 1;
}