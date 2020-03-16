
// considerDlg.h : 헤더 파일
// 가장 기본이 되는 Base dialog를 위한 기능을 제공합니다.
// 시작 dialog 입니다.

#pragma once
#include "afxwin.h"


// CconsiderDlg 대화 상자
class CconsiderDlg : public CDialogEx
{
// 생성입니다.
public:
	CconsiderDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONSIDER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();  // 배경지정 함수
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1(); // 6가지 음식중 1가지 음식의 랜덤 선택 다이얼로그를 불러오는 함수
	afx_msg void OnBnClickedButton2(); // 오직 랜덤만 있는 다이얼로그를 불러오는 함수
	afx_msg void OnBnClickedButton3(); // 음식 월드컵 다이얼로그를 불러오는 함수
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	CStatic ID_no; // 나가기 버튼
	afx_msg void OnStnClickedNo(); //나가기 버튼 함수
};
