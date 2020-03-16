//음식 월드컵을 위한 다이얼로그 헤더파일
#pragma once


// Newdialog3 대화 상자입니다.
#include "afxext.h"
#include "MyBitmapButton.h" // 사진크기 수정 헤더파일
#include <string> // 문자열 사용을 위한 헤더파일
#include <iostream>

class Newdialog3 : public CDialogEx
{
	DECLARE_DYNAMIC(Newdialog3)

public:
	Newdialog3(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~Newdialog3();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	// 함수 오버로드
	void imageset(string*fname);
	void imageset(int fname);

	afx_msg void OnBnClickedOk(); // 나가기 버튼
	afx_msg void OnBnClickedAa(); // 왼쪽버튼
	afx_msg void OnBnClickedBb(); // 오른쪽 버튼

	// 객체 생성
	CMyBitmapButton m_ok; 
	CMyBitmapButton m_btn;
	CMyBitmapButton m_btn2;
};
