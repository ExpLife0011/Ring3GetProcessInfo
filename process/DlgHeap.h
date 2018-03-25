#pragma once
#include "afxcmn.h"


// CDlgHeap �Ի���

class CDlgHeap : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgHeap)

public:
	CDlgHeap(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgHeap();

// �Ի�������
	enum { IDD = IDD_DIALOG_HEAP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg LRESULT OnInsertHeap(WPARAM, LPARAM);
	afx_msg LRESULT ListInfo(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListHeap;
	virtual BOOL OnInitDialog();

	static HWND dlgHwnd;
	static void WINAPI ListHeap(PVOID);
};
