// 랜덤으로 한가지 음식을 보여주는 사진 랜덤

#pragma once
#include "MyBitmapButton.h" // 버튼으로 랜덤을 구현함. 이 헤더파일에는 사진크기를 버튼에 맞게 수정하는 함수 포함.
#define MAX 13

// Newdialog2 대화 상자입니다.

class Newdialog2 : public CDialogEx
{
	DECLARE_DYNAMIC(Newdialog2)
private:
	CImage m_image[MAX];
public:
	Newdialog2(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~Newdialog2();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CMyBitmapButton m_btn3; // 다이얼로그 전체 크기의 버튼 생성, CMyBitmapButton 의 객체로 생성
};
