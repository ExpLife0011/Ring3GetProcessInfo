#pragma once
#include "afxcmn.h"


// CDlgModule �Ի���

class CDlgModule : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgModule)

public:
	CDlgModule(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgModule();

// �Ի�������
	enum { IDD = IDD_DIALOG_MODULE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	afx_msg LRESULT OnInsertModule(WPARAM, LPARAM);
	afx_msg LRESULT ListInfo(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_ListModule;

	static HWND dlgHwnd;
	static void WINAPI ListModule(PVOID);
};
