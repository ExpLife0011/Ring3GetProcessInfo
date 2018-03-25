#pragma once
#include "afxcmn.h"



// DlgThread �Ի���

class DlgThread : public CDialogEx
{
	DECLARE_DYNAMIC(DlgThread)

public:
	DlgThread(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DlgThread();

// �Ի�������
	enum { IDD = IDD_DIALOG_THREAD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg LRESULT OnInsertThread(WPARAM, LPARAM);
	afx_msg LRESULT ListInfo(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListHeap;
	virtual BOOL OnInitDialog();

	static HWND dlgHwnd;
	static void WINAPI ListThread(PVOID);
};
