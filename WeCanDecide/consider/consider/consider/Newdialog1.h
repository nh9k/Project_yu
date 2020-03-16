// 6가지 음식중 1가지 음식을 랜덤으로 선택하는 클래스의 헤더파일

#pragma once


// Newdialog1 대화 상자입니다.

class Newdialog1 : public CDialogEx
{
	DECLARE_DYNAMIC(Newdialog1)

public:
	Newdialog1(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~Newdialog1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct); // 버튼 크기에 사진을 맞추는 함수
};
