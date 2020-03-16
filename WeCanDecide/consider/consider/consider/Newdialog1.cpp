// Newdialog1.cpp : 구현 파일입니다.
// 6가지 음식중 1개를 고르는 다이얼로그의 cpp 파일

#include "stdafx.h"
#include "consider.h"
#include "Newdialog1.h"
#include "afxdialogex.h"
#include "random.h"

// Newdialog1 대화 상자입니다.

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


// Newdialog1 메시지 처리기입니다.


void Newdialog1::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str[6]; // 여섯가지 음식의 이름을 저장할 배열

	GetDlgItem(IDC_EDIT1)->GetWindowText(str[0]); // EDIT1 의 값을 가지고와서 str 로 넘깁니다.
	GetDlgItem(IDC_EDIT2)->GetWindowText(str[1]);
	GetDlgItem(IDC_EDIT3)->GetWindowText(str[2]);
	GetDlgItem(IDC_EDIT4)->GetWindowText(str[3]);
	GetDlgItem(IDC_EDIT5)->GetWindowText(str[4]);
	GetDlgItem(IDC_EDIT6)->GetWindowText(str[5]);

	int con = 0;
	random a(con); // 랜덤 함수가 포함된 클래스로 부터 숫자를 랜덤으로 골라 리턴하는 함수. 
	int nym = a.random1(con); // 음식의 이름이 저장된 배열

	GetDlgItem(IDC_EDIT7)->SetWindowText(str[nym]); //음식 이름 중 한가지를 랜덤으로 출력
}


void Newdialog1::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
