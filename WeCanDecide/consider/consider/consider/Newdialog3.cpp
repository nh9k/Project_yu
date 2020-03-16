// Newdialog3.cpp : 구현 파일입니다.
// 음식 월드컵을 구현하기 위한 클래스의 함수의 정의가 담긴 cpp 파일

#include "stdafx.h"
#include "consider.h"
#include "Newdialog3.h"
#include "afxdialogex.h"
#include "MyBitmapButton.h"
#include <math.h>
#include <time.h>
#include <string>
#include<iostream>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CFont m_font;
// Newdialog3 대화 상자입니다.

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

BEGIN_MESSAGE_MAP(Newdialog3, CDialogEx)
	

	ON_BN_CLICKED(AA, &Newdialog3::OnBnClickedAa)
	ON_BN_CLICKED(BB, &Newdialog3::OnBnClickedBb)
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()
IMPLEMENT_DYNAMIC(Newdialog3, CDialogEx)

Newdialog3::Newdialog3(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

Newdialog3::~Newdialog3()
{
}

void Newdialog3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_ok); // 나가기 버튼
	DDX_Control(pDX, AA, m_btn);  // 왼쪽 버튼
	DDX_Control(pDX, BB, m_btn2);  // 오른쪽 버튼
}


// CMFCApplication1Dlg 메시지 처리기

BOOL Newdialog3::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetBackgroundColor(RGB(255, 255, 255)); // 배경 색 흰색 지정
	m_font.CreateFont(35, // nHeight 
		17, // nWidth 
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
		_T("함초롬바탕")); // lpszFacename  // 글자체 함초롱 바탕 사용
	m_ok.SetFont(&m_font, true);
	//m_ok.SetButtonStyle();
	m_btn.LoadBitmaps(1, NULL, NULL, NULL); // 이미지이름이 1인 이미지를 왼쪽버튼에 로드한다.
	m_btn2.LoadBitmaps(8, NULL, NULL, NULL); // 이미지 이름이 8인 이미지를 오른쪽 버튼에 로드한다.

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

void Newdialog3::OnSysCommand(UINT nID, LPARAM lParam)
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

void Newdialog3::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
		CFont font;
		//font.CreateFont();
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
HCURSOR Newdialog3::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Newdialog3::OnBnClickedAa() // 왼쪽버튼
{
	int fname = 0;
	imageset(fname); //int type이 들어가면 오른쪽 버튼의 사진을 변경함.

					 //m_btn.SizeToContent(); //사이즈 자동조절 - 사진크기에 따라 버튼크기를 수정하는 함수여서 적절치 않음.
					 // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
void Newdialog3::OnBnClickedBb() //오른쪽 버튼
{
	string f = "ASD";
	imageset(&f);  // string 형을 넣으면 왼쪽버튼의 사진을 변경함.

				   //m_btn.SizeToContent(); //사이즈 자동조절
}

void Newdialog3::imageset(int fname) // 오버로드 함수 사용 int type
{
	static int i = 2; // static으로 선언해야 함수를 나가도 i = 2를 유지함.
	for (i; i <8; i++)
	{
		m_btn2.LoadBitmaps(i, NULL, NULL, NULL); //오른쪽 버튼에 이미지이름이 2부터 올린다.
		Invalidate(); // 왼쪽 버튼을 누르면, 오른쪽 버튼이 바로 변경되어야하는데,
		              // 오른쪽버튼이 바로 변경되지 않고 클릭을 해줘야 변경되는 문제점 때문에 써줌.
		              // 업데이트를 해서 바로 결과가 보이도록 유도.
		i++;
		break; // 한번 올리고 함수를 빠져나온다. 한번만 변경하게 돕는다.
	}
}
void Newdialog3::imageset(string*fname) // 오버로드 함수 사용 string type
{
	static int K = 9;
	for (K; K < 15; K++) // 9번 이미지부터 for을 시행한다.
	{
		m_btn.LoadBitmaps(K, NULL, NULL, NULL); // 왼쪽버튼에 숫자 k에 해당하는 이미지를 로드해준다.
		Invalidate();
		K++;
		break; 
	}
}
CMyBitmapButton::CMyBitmapButton(void)
{
}

CMyBitmapButton::~CMyBitmapButton(void)
{
}

BOOL CMyBitmapButton::AutoLoad(UINT nID, CWnd* pParent) 
{
	// first attach the CBitmapButton to the dialog control
	if (!SubclassDlgItem(nID, pParent))
		return FALSE;

	CString buttonName;
	GetWindowText(buttonName);
	ASSERT(!buttonName.IsEmpty());      // must provide a title

	LoadBitmaps(buttonName + _T("U"), buttonName + _T("D"),
		buttonName + _T("F"), buttonName + _T("X"));

	// we need at least the primary
	if (m_bitmap.m_hObject == NULL)
		return FALSE;

	// size to content
	//SizeToContent();
	return TRUE;
}

// Draw the appropriate bitmap
void CMyBitmapButton::DrawItem(LPDRAWITEMSTRUCT lpDIS) //사진크기를 버튼에 맞게 조절해주는 함수
{
	ASSERT(lpDIS != NULL);
	// must have at least the first bitmap loaded before calling DrawItem
	ASSERT(m_bitmap.m_hObject != NULL);     // required

											// use the main bitmap for up, the selected bitmap for down
	CBitmap* pBitmap = &m_bitmap; // 비트맵에 포인터 사용
	UINT state = lpDIS->itemState;
	if ((state & ODS_SELECTED) && m_bitmapSel.m_hObject != NULL)
		pBitmap = &m_bitmapSel;
	else if ((state & ODS_FOCUS) && m_bitmapFocus.m_hObject != NULL)
		pBitmap = &m_bitmapFocus;   // third image for focused
	else if ((state & ODS_DISABLED) && m_bitmapDisabled.m_hObject != NULL)
		pBitmap = &m_bitmapDisabled;   // last image for disabled

									   // draw the whole button
	CDC* pDC = CDC::FromHandle(lpDIS->hDC);
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);
	CBitmap* pOld = memDC.SelectObject(pBitmap);
	if (pOld == NULL)
		return;     // destructors will clean up

	CRect rect;
	rect.CopyRect(&lpDIS->rcItem);
	// pDC->BitBlt(rect.left, rect.top, rect.Width(), rect.Height(),
	// 	 &memDC, 0, 0, SRCCOPY);

	// determine bitmaps size for use in StretchBlt
	BITMAP bits;
	pBitmap->GetObject(sizeof(BITMAP), &bits);
	pDC->StretchBlt(rect.left, rect.top, rect.Width(), rect.Height(),
		&memDC, 0, 0, bits.bmWidth, bits.bmHeight, SRCCOPY);

	memDC.SelectObject(pOld);
}




void Newdialog3::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}

