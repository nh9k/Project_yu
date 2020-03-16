// Newdialog2.cpp : 구현 파일입니다.
// 오직 랜덤으로만 음식을 결정하는 클래스의 함수 정의 부분 cpp 파일

#include "stdafx.h"
#include "consider.h"
#include "Newdialog2.h"
#include "afxdialogex.h"
#include "imagerandom.h"


// Newdialog2 대화 상자입니다.

IMPLEMENT_DYNAMIC(Newdialog2, CDialogEx)

Newdialog2::Newdialog2(CWnd* pParent /*=NULL*/) // 생성자 함수
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
	imagerandom a(con); // 랜덤 숫자를 객체로 생성
	int index = a.random1(con); 
	m_btn3.LoadBitmaps(index, NULL, NULL, NULL); // 랜덤 숫자에 해당하는 이미지 파일 로드
	return TRUE;
}

void Newdialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, CC, m_btn3);
}


BEGIN_MESSAGE_MAP(Newdialog2, CDialogEx)
END_MESSAGE_MAP()


// Newdialog2 메시지 처리기입니다.

