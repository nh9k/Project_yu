//���� �������� ���� ���̾�α� �������
#pragma once


// Newdialog3 ��ȭ �����Դϴ�.
#include "afxext.h"
#include "MyBitmapButton.h" // ����ũ�� ���� �������
#include <string> // ���ڿ� ����� ���� �������
#include <iostream>

class Newdialog3 : public CDialogEx
{
	DECLARE_DYNAMIC(Newdialog3)

public:
	Newdialog3(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~Newdialog3();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()

public:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	// �Լ� �����ε�
	void imageset(string*fname);
	void imageset(int fname);

	afx_msg void OnBnClickedOk(); // ������ ��ư
	afx_msg void OnBnClickedAa(); // ���ʹ�ư
	afx_msg void OnBnClickedBb(); // ������ ��ư

	// ��ü ����
	CMyBitmapButton m_ok; 
	CMyBitmapButton m_btn;
	CMyBitmapButton m_btn2;
};
