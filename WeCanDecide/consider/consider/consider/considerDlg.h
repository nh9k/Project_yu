
// considerDlg.h : ��� ����
// ���� �⺻�� �Ǵ� Base dialog�� ���� ����� �����մϴ�.
// ���� dialog �Դϴ�.

#pragma once
#include "afxwin.h"


// CconsiderDlg ��ȭ ����
class CconsiderDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CconsiderDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONSIDER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();  // ������� �Լ�
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1(); // 6���� ������ 1���� ������ ���� ���� ���̾�α׸� �ҷ����� �Լ�
	afx_msg void OnBnClickedButton2(); // ���� ������ �ִ� ���̾�α׸� �ҷ����� �Լ�
	afx_msg void OnBnClickedButton3(); // ���� ������ ���̾�α׸� �ҷ����� �Լ�
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	CStatic ID_no; // ������ ��ư
	afx_msg void OnStnClickedNo(); //������ ��ư �Լ�
};
