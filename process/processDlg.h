
// processDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"

#include "DlgProc.h"
#include "DlgThread.h"
#include "DlgHeap.h"
#include "DlgPage.h"
// CprocessDlg �Ի���
class CprocessDlg : public CDialogEx
{
// ����
public:
	CprocessDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_PROCESS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_TabMain;
	CDlgProc m_DlgProc;
	DlgThread m_DlgThread;
	CDlgHeap m_DlgHeap;
	CDlgPage m_DlgPage;

	int		 m_TabNumber;
	CDialog  *m_pDlgTabs[6];
	afx_msg void OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnThread();

	CStatusBar m_StatusBar;
};
