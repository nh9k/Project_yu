
// consider.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
// ���� �⺻�� �Ǵ� Base dialog�� ���� ����� �����մϴ�.
// ���� dialog �Դϴ�.


#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CconsiderApp:
// �� Ŭ������ ������ ���ؼ��� consider.cpp�� �����Ͻʽÿ�.
//

class CconsiderApp : public CWinApp
{
public:
	CconsiderApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CconsiderApp theApp;
