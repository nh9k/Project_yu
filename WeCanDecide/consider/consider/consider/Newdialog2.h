// �������� �Ѱ��� ������ �����ִ� ���� ����

#pragma once
#include "MyBitmapButton.h" // ��ư���� ������ ������. �� ������Ͽ��� ����ũ�⸦ ��ư�� �°� �����ϴ� �Լ� ����.
#define MAX 13

// Newdialog2 ��ȭ �����Դϴ�.

class Newdialog2 : public CDialogEx
{
	DECLARE_DYNAMIC(Newdialog2)
private:
	CImage m_image[MAX];
public:
	Newdialog2(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~Newdialog2();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CMyBitmapButton m_btn3; // ���̾�α� ��ü ũ���� ��ư ����, CMyBitmapButton �� ��ü�� ����
};
