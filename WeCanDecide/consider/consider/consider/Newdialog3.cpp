// Newdialog3.cpp : ���� �����Դϴ�.
// ���� �������� �����ϱ� ���� Ŭ������ �Լ��� ���ǰ� ��� cpp ����

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
// Newdialog3 ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

														// �����Դϴ�.
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
	DDX_Control(pDX, IDOK, m_ok); // ������ ��ư
	DDX_Control(pDX, AA, m_btn);  // ���� ��ư
	DDX_Control(pDX, BB, m_btn2);  // ������ ��ư
}


// CMFCApplication1Dlg �޽��� ó����

BOOL Newdialog3::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetBackgroundColor(RGB(255, 255, 255)); // ��� �� ��� ����
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
		_T("���ʷҹ���")); // lpszFacename  // ����ü ���ʷ� ���� ���
	m_ok.SetFont(&m_font, true);
	//m_ok.SetButtonStyle();
	m_btn.LoadBitmaps(1, NULL, NULL, NULL); // �̹����̸��� 1�� �̹����� ���ʹ�ư�� �ε��Ѵ�.
	m_btn2.LoadBitmaps(8, NULL, NULL, NULL); // �̹��� �̸��� 8�� �̹����� ������ ��ư�� �ε��Ѵ�.

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

									// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void Newdialog3::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
		CFont font;
		//font.CreateFont();
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR Newdialog3::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Newdialog3::OnBnClickedAa() // ���ʹ�ư
{
	int fname = 0;
	imageset(fname); //int type�� ���� ������ ��ư�� ������ ������.

					 //m_btn.SizeToContent(); //������ �ڵ����� - ����ũ�⿡ ���� ��ưũ�⸦ �����ϴ� �Լ����� ����ġ ����.
					 // TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
void Newdialog3::OnBnClickedBb() //������ ��ư
{
	string f = "ASD";
	imageset(&f);  // string ���� ������ ���ʹ�ư�� ������ ������.

				   //m_btn.SizeToContent(); //������ �ڵ�����
}

void Newdialog3::imageset(int fname) // �����ε� �Լ� ��� int type
{
	static int i = 2; // static���� �����ؾ� �Լ��� ������ i = 2�� ������.
	for (i; i <8; i++)
	{
		m_btn2.LoadBitmaps(i, NULL, NULL, NULL); //������ ��ư�� �̹����̸��� 2���� �ø���.
		Invalidate(); // ���� ��ư�� ������, ������ ��ư�� �ٷ� ����Ǿ���ϴµ�,
		              // �����ʹ�ư�� �ٷ� ������� �ʰ� Ŭ���� ����� ����Ǵ� ������ ������ ����.
		              // ������Ʈ�� �ؼ� �ٷ� ����� ���̵��� ����.
		i++;
		break; // �ѹ� �ø��� �Լ��� �������´�. �ѹ��� �����ϰ� ���´�.
	}
}
void Newdialog3::imageset(string*fname) // �����ε� �Լ� ��� string type
{
	static int K = 9;
	for (K; K < 15; K++) // 9�� �̹������� for�� �����Ѵ�.
	{
		m_btn.LoadBitmaps(K, NULL, NULL, NULL); // ���ʹ�ư�� ���� k�� �ش��ϴ� �̹����� �ε����ش�.
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
void CMyBitmapButton::DrawItem(LPDRAWITEMSTRUCT lpDIS) //����ũ�⸦ ��ư�� �°� �������ִ� �Լ�
{
	ASSERT(lpDIS != NULL);
	// must have at least the first bitmap loaded before calling DrawItem
	ASSERT(m_bitmap.m_hObject != NULL);     // required

											// use the main bitmap for up, the selected bitmap for down
	CBitmap* pBitmap = &m_bitmap; // ��Ʈ�ʿ� ������ ���
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnOK();
}

