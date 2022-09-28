#include "pch.h"
#include "framework.h"
#include "mybtn.h"
/*
BEGIN_MESSAGE_MAP(CMyBtn, CButton)

	ON_WM_MOUSEMOVE()
	
END_MESSAGE_MAP()
*/

CMyBtn::CMyBtn()
{

}
CMyBtn::~CMyBtn()
{

}
/*
void CMyBtn::OnMouseMove(UINT nFlags, CPoint pt)
{
	CDC* pDC;
	pDC = GetDC();
	CString strPos;
	strPos.Format(L"%04d %04d", pt.x, pt.y);
	pDC->TextOut(0, 0, strPos);
	ReleaseDC(pDC);
}
*/
// win32 방식으로도 가능
LRESULT CMyBtn::WindowProc(UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_MOUSEMOVE:
		CDC* pDC;
		pDC = GetDC();
		CString strPos;
		strPos.Format(L"%04d %04d", LOWORD(lParam), HIWORD(lParam));
		pDC->TextOut(0, 0, strPos);
		ReleaseDC(pDC);
		break;
	}
	return CButton::DefWindowProcW(msg, wParam, lParam);
}