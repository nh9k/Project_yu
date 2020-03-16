/*
#include "MyBitmapButton.h"

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
void CMyBitmapButton::DrawItem(LPDRAWITEMSTRUCT lpDIS)
{
	ASSERT(lpDIS != NULL);
	// must have at least the first bitmap loaded before calling DrawItem
	ASSERT(m_bitmap.m_hObject != NULL);     // required

	// use the main bitmap for up, the selected bitmap for down
	CBitmap* pBitmap = &m_bitmap;
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
	pBitmap->GetObject(sizeof(BITMAP),&bits);
	pDC->StretchBlt(rect.left,rect.top,rect.Width(),rect.Height(),
		&memDC,0,0,bits.bmWidth, bits.bmHeight, SRCCOPY);

	memDC.SelectObject(pOld);
}
*/