// Newdialog2.cpp : ���� �����Դϴ�.
// ���� �������θ� ������ �����ϴ� Ŭ������ �Լ� ���� �κ� cpp ����

#include "stdafx.h"
#include "consider.h"
#include "Newdialog2.h"
#include "afxdialogex.h"
#include "imagerandom.h"


// Newdialog2 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(Newdialog2, CDialogEx)

Newdialog2::Newdialog2(CWnd* pParent /*=NULL*/) // ������ �Լ�
	: CDialogEx(IDD_DIALOG2, pParent)
{
}
Newdialog2::~Newdialog2()
{
}

BOOL Newdialog2::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	int con = 0;
	imagerandom a(con); // ���� ���ڸ� ��ü�� ����
	int index = a.random1(con); 
	m_btn3.LoadBitmaps(index, NULL, NULL, NULL); // ���� ���ڿ� �ش��ϴ� �̹��� ���� �ε�
	return TRUE;
}

void Newdialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, CC, m_btn3);
}


BEGIN_MESSAGE_MAP(Newdialog2, CDialogEx)
END_MESSAGE_MAP()


// Newdialog2 �޽��� ó�����Դϴ�.

