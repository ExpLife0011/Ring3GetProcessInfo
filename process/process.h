
// process.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once
#include "stdafx.h"
#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CprocessApp:
// �йش����ʵ�֣������ process.cpp
//

class CprocessApp : public CWinApp
{
public:
	CprocessApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CprocessApp theApp;