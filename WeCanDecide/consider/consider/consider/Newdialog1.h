// 6���� ������ 1���� ������ �������� �����ϴ� Ŭ������ �������

#pragma once


// Newdialog1 ��ȭ �����Դϴ�.

class Newdialog1 : public CDialogEx
{
	DECLARE_DYNAMIC(Newdialog1)

public:
	Newdialog1(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~Newdialog1();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct); // ��ư ũ�⿡ ������ ���ߴ� �Լ�
};
