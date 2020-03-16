// 버튼에 사진 크기를 맞추는 사진 크기 수정 함수와 로드 함수가 포함된 헤더파일
#pragma once
#include "afxext.h"
#include <string> // 문자열 사용을 위한 스트링 헤더파일
#include <iostream> // 이것을 안써주면 오류가 생김 <string과 함께>
using namespace std; // 이것을 안써주면 오류가 생김

class CMyBitmapButton :
	public CBitmapButton
{
public:
	CMyBitmapButton(void);
	~CMyBitmapButton(void);

	BOOL AutoLoad(UINT nID, CWnd* pParent); // 자동 사진 로드

	void DrawItem(LPDRAWITEMSTRUCT lpDIS); // 버튼에 사진 크기를 맞추는 사진 크기 수정 함수
	

};
