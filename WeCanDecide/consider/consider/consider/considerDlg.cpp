
// considerDlg.cpp : 구현 파일
// 가장 기본이 되는 Base dialog를 위한 기능을 제공합니다.
// 시작 dialog 입니다.

#include "stdafx.h"
#include "consider.h"
#include "considerDlg.h"
#include "afxdialogex.h"
#include "Newdialog1.h"
#include "Newdialog2.h"
#include "Newdialog3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CFont mm_font;


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CconsiderDlg 대화 상자



CconsiderDlg::CconsiderDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CONSIDER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CconsiderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDNO, ID_no);
}

BEGIN_MESSAGE_MAP(CconsiderDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CconsiderDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CconsiderDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CconsiderDlg::OnBnClickedButton3)
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()


// CconsiderDlg 메시지 처리기

BOOL CconsiderDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetBackgroundColor(RGB(255, 205, 205)); // 배경 색깔을 지정합니다 // 분홍색
	mm_font.CreateFont(40, // nHeight 
		20, // nWidth 
		0, // nEscapement 
		0, // nOrientation 
		1, // nWeight 
		0, // bItalic 
		0, // bUnderline 
		0, // cStrikeOut 
		0, // nCharSet 
		OUT_DEFAULT_PRECIS, // nOutPrecision 
		0,                              // nClipPrecision 
		DEFAULT_QUALITY,       // nQuality
		DEFAULT_PITCH | FF_DONTCARE,  // nPitchAndFamily 
		_T("Algerian")); // lpszFacename  // 글씨체를 지정합니다.
	ID_no.SetFont(&mm_font, true);

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CconsiderDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CconsiderDlg::OnPaint()
{
	CPaintDC dc(this);

	//배경화면을 지정합니다.
	int cx = 600; //배경할 사진의 크기
	int cy = 320;
	CBitmap bmp;
	CBitmap *old_bmp;
	CDC memDC;

	memDC.CreateCompatibleDC(&dc);
	bmp.LoadBitmap(IDB_BITMAP1);
	old_bmp = memDC.SelectObject(&bmp);
	dc.BitBlt(0, 0, cx, cy, &memDC, 0, 0, SRCCOPY);
	memDC.SelectObject(old_bmp);
	bmp.DeleteObject();
	memDC.DeleteDC();

	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CconsiderDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CconsiderDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		Newdialog1 dlg;
	dlg.DoModal();
}


void CconsiderDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Newdialog2 dlg;
	dlg.DoModal();
}


void CconsiderDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Newdialog3 dlg;
	dlg.DoModal();
}


void CconsiderDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CDC dc;
	RECT rect;
	dc.Attach(lpDrawItemStruct->hDC);   // Get the Button DC to CDC

	rect = lpDrawItemStruct->rcItem;     //Store the Button rect to our local rect.
	dc.Draw3dRect(&rect, RGB(255, 255, 255), RGB(0, 0, 0));
	dc.FillSolidRect(&rect, RGB(255, 155, 155));//Here you can define the required color to appear on the Button.

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
