// DlgHeap.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "process.h"
#include "DlgHeap.h"
#include "afxdialogex.h"


// CDlgHeap �Ի���

IMPLEMENT_DYNAMIC(CDlgHeap, CDialogEx)

CDlgHeap::CDlgHeap(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgHeap::IDD, pParent)
{

}

CDlgHeap::~CDlgHeap()
{
}

void CDlgHeap::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_HEAP, m_ListHeap);
}


BEGIN_MESSAGE_MAP(CDlgHeap, CDialogEx)
	ON_MESSAGE(WM_INSERT_HEAP, &CDlgHeap::OnInsertHeap)
	ON_MESSAGE(WM_LIST_INFO, &CDlgHeap::ListInfo)
END_MESSAGE_MAP()


// CDlgHeap ��Ϣ�������


BOOL CDlgHeap::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_ListHeap.InsertColumn(0, _T("�Ѿ��"), LVCFMT_LEFT, 100, -1);
	m_ListHeap.InsertColumn(1, _T("��ʼ��ַ"), LVCFMT_LEFT, 100, -1);
	m_ListHeap.InsertColumn(2, _T("��С"), LVCFMT_LEFT, 100, -1);
	m_ListHeap.InsertColumn(3, _T("״̬"), LVCFMT_LEFT, 100, -1);
	m_ListHeap.InsertColumn(4, _T("Lock��"), LVCFMT_LEFT, 100, -1);
	m_ListHeap.InsertColumn(5, _T("��ID"), LVCFMT_LEFT, 300, -1);
	m_ListHeap.InsertColumn(6, _T("PID"), LVCFMT_LEFT, 300, -1);

	DWORD style = m_ListHeap.GetStyle();
	style |= LVS_EX_FULLROWSELECT;
	m_ListHeap.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	RECT rt;
	GetParent()->GetClientRect(&rt);
	m_ListHeap.MoveWindow(&rt);


	dlgHwnd = m_hWnd;

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

HWND CDlgHeap::dlgHwnd = NULL;
void CDlgHeap::ListHeap(PVOID info)
{
	::SendMessage(dlgHwnd, WM_INSERT_HEAP, (WPARAM)info, 0);
}

LRESULT CDlgHeap::OnInsertHeap(WPARAM wParam, LPARAM lParam)
{
	PHEAPENTRY32 te32 = (PHEAPENTRY32)wParam;
	CString text;
	TCHAR tszExe[MAX_PATH] = {0};

	ProcAnalyze pa;
	pa.GetProcessName(te32->th32ProcessID, tszExe);
	text.Format(_T("%d"), te32->hHandle);
	m_ListHeap.InsertItem(0, tszExe);
	text.Format(_T("%d"), te32->dwAddress);
	m_ListHeap.SetItemText(0, 1, text.GetBuffer());
	text.Format(_T("%d"), te32->dwBlockSize);
	m_ListHeap.SetItemText(0, 2, text.GetBuffer());
	text.Format(_T("%d"), te32->dwFlags);
	m_ListHeap.SetItemText(0, 3, text.GetBuffer());
	text.Format(_T("%d"), te32->dwLockCount);
	m_ListHeap.SetItemText(0, 4, text.GetBuffer());
	text.Format(_T("%d"), te32->th32HeapID);
	m_ListHeap.SetItemText(0, 5,  text.GetBuffer());
	text.Format(_T("%d"), te32->th32ProcessID);
	m_ListHeap.SetItemText(0, 6,  text.GetBuffer());
	return 1;
}
LRESULT CDlgHeap::ListInfo(WPARAM wParam, LPARAM lParam)
{
	m_ListHeap.DeleteAllItems();
	ProcAnalyze pa;
	pa.ListHeap(ListHeap
		, wParam);

	return 1;
}