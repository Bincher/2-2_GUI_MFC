// CMyBtn.cpp: 구현 파일
//

#include "pch.h"
#include "My.h"
#include "CMyBtn.h"




// CMyBtn

IMPLEMENT_DYNAMIC(CMyBtn, CMFCButton)

CMyBtn::CMyBtn()
{

}

CMyBtn::~CMyBtn()
{
}


BEGIN_MESSAGE_MAP(CMyBtn, CMFCButton)
//	ON_WM_MOUSEWHEEL()
ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// CMyBtn 메시지 처리기




//BOOL CMyBtn::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
//{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

//	return CMFCButton::OnMouseWheel(nFlags, zDelta, pt);
//}


void CMyBtn::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CDC* pDC;
	pDC = GetDC();
	CString strPos;
	strPos.Format(L"%04d %04d", point.x, point.y);
	pDC->TextOutW(0, 0, strPos);
	ReleaseDC(pDC);

	CMFCButton::OnMouseMove(nFlags, point);
}


LRESULT CMyBtn::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CMFCButton::WindowProc(message, wParam, lParam);
}
