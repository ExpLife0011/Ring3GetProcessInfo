#pragma once
#include "afxcmn.h"


// CDlgPage �Ի���

class CDlgPage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgPage)

public:
	CDlgPage(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgPage();

// �Ի�������
	enum { IDD = IDD_DIALOG_PAGES };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg LRESULT OnInsertPage(WPARAM, LPARAM);
	afx_msg LRESULT ListInfo(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_ListPage;

	static HWND dlgHwnd;
	static void WINAPI ListPage(PVOID);
};
