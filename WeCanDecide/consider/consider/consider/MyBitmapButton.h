// ��ư�� ���� ũ�⸦ ���ߴ� ���� ũ�� ���� �Լ��� �ε� �Լ��� ���Ե� �������
#pragma once
#include "afxext.h"
#include <string> // ���ڿ� ����� ���� ��Ʈ�� �������
#include <iostream> // �̰��� �Ƚ��ָ� ������ ���� <string�� �Բ�>
using namespace std; // �̰��� �Ƚ��ָ� ������ ����

class CMyBitmapButton :
	public CBitmapButton
{
public:
	CMyBitmapButton(void);
	~CMyBitmapButton(void);

	BOOL AutoLoad(UINT nID, CWnd* pParent); // �ڵ� ���� �ε�

	void DrawItem(LPDRAWITEMSTRUCT lpDIS); // ��ư�� ���� ũ�⸦ ���ߴ� ���� ũ�� ���� �Լ�
	

};
