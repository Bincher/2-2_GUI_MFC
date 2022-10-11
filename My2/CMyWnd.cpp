// CMyWnd.cpp: 구현 파일
//

#include "pch.h"
#include "My2.h"
#include "CMyWnd.h"


// CMyWnd

IMPLEMENT_DYNAMIC(CMyWnd, CWnd)

CMyWnd::CMyWnd()
{

}

CMyWnd::~CMyWnd()
{
}


BEGIN_MESSAGE_MAP(CMyWnd, CWnd)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// CMyWnd 메시지 처리기




BOOL CMyWnd::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rt;
	this->GetClientRect(&rt);
	pDC->FillSolidRect(rt, RGB(255, 255, 255));

	return CWnd::OnEraseBkgnd(pDC);
}
