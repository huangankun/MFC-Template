
// MyMFC_Lib.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMyMFC_LibApp: 
// �йش����ʵ�֣������ MyMFC_Lib.cpp
//

class CMyMFC_LibApp : public CWinApp
{
public:
	CMyMFC_LibApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMyMFC_LibApp theApp;