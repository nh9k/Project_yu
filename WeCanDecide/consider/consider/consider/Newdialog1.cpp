// Newdialog1.cpp : ���� �����Դϴ�.
// 6���� ������ 1���� ���� ���̾�α��� cpp ����

#include "stdafx.h"
#include "consider.h"
#include "Newdialog1.h"
#include "afxdialogex.h"
#include "random.h"

// Newdialog1 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(Newdialog1, CDialogEx)

Newdialog1::Newdialog1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Newdialog1::~Newdialog1()
{
}

void Newdialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Newdialog1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Newdialog1::OnBnClickedButton1)
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()


// Newdialog1 �޽��� ó�����Դϴ�.


void Newdialog1::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str[6]; // �������� ������ �̸��� ������ �迭

	GetDlgItem(IDC_EDIT1)->GetWindowText(str[0]); // EDIT1 �� ���� ������ͼ� str �� �ѱ�ϴ�.
	GetDlgItem(IDC_EDIT2)->GetWindowText(str[1]);
	GetDlgItem(IDC_EDIT3)->GetWindowText(str[2]);
	GetDlgItem(IDC_EDIT4)->GetWindowText(str[3]);
	GetDlgItem(IDC_EDIT5)->GetWindowText(str[4]);
	GetDlgItem(IDC_EDIT6)->GetWindowText(str[5]);

	int con = 0;
	random a(con); // ���� �Լ��� ���Ե� Ŭ������ ���� ���ڸ� �������� ��� �����ϴ� �Լ�. 
	int nym = a.random1(con); // ������ �̸��� ����� �迭

	GetDlgItem(IDC_EDIT7)->SetWindowText(str[nym]); //���� �̸� �� �Ѱ����� �������� ���
}


void Newdialog1::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CDC dc;
	RECT rect;
	dc.Attach(lpDrawItemStruct->hDC);   // Get the Button DC to CDC

	rect = lpDrawItemStruct->rcItem;     //Store the Button rect to our local rect.
	dc.Draw3dRect(&rect, RGB(255, 255, 255), RGB(0, 0, 0));
	dc.FillSolidRect(&rect, RGB(255, 255, 255));//Here you can define the required color to appear on the Button.

	UINT state = lpDrawItemStruct->itemState;  //This defines the state of the Push button either pressed or not. 
	if ((state & ODS_SELECTED))
		dc.DrawEdge(&rect, EDGE_SUNKEN, BF_RECT);
	else
		dc.DrawEdge(&rect, EDGE_RAISED, BF_RECT);

	dc.SetTextColor(RGB(0, 0, 0));     //Setting the Text Color

	TCHAR buffer[MAX_PATH];           //To store the Caption of the button.
	ZeroMemory(buffer, MAX_PATH);     //Intializing the buffer to zero
	::GetWindowText(lpDrawItemStruct->hwndItem, buffer, MAX_PATH); //Get the Caption of Button Window 

	dc.DrawText(buffer, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//Redraw the  Caption of Button Window 
	dc.Detach();  // Detach the Button DC

	CDialogEx::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
