
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "My2.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) // OnCreate() 전에 자동으로 먼저 호출
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);
	/*
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(nullptr, IDC_ARROW), (HBRUSH)::GetStockObject(BLACK_BRUSH), nullptr);
	*/
	// AfxRegisterWndClass : 윈도우클래스 정의,등록 처리

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}

#pragma warning(disable:4996) //sprintf

void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	CDC* pDC;
	pDC = GetDC();
	CString strPos;
	strPos.Format(L"%04d %04d", point.x, point.y);
	pDC->TextOut(0, 0, strPos);
	ReleaseDC(pDC);
	
	/*
	옛날방식
	HDC hdc;
	hdc = ::GetDC(m_hWnd);
	//CString strPos;
	//strPos.Format(L"%04d %04d", point.x, point.y);
	//::TextOutW(hdc, 0, 0, strPos, strPos.GetLength());
	char szPos[80];
	sprintf(szPos, "%04d %04d", point.x, point.y);
	::TextOutA(hdc, 0, 0, szPos, strlen(szPos));
	::ReleaseDC(m_hWnd, hdc);
	CWnd::OnMouseMove(nFlags, point);
	*/

}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	/*
	m_wndMy.Create(0, L"My Window",
		WS_VISIBLE | WS_OVERLAPPEDWINDOW,
		CRect(0, 0, 500, 500),
		this,
		999,
		0
	);
	m_wndMy.Create(0, L"My Window",
		WS_VISIBLE | WS_OVERLAPPEDWINDOW | WS_CHILD,
		CRect(0, 0, 500, 500),
		this,
		999,
		0
	); -> 기본적으로 WS_CHILD가 적용, 별도의 윈도우는 CreateEx
	*/
	CString strClass;
	strClass = AfxRegisterWndClass(
		CS_VREDRAW | CS_HREDRAW,
		::LoadCursor(NULL, IDC_ARROW),
		(HBRUSH) ::GetStockObject(BLACK_BRUSH),
		::LoadIcon(NULL, IDI_APPLICATION)
	);
	m_wndMy.CreateEx(
		0, 
		strClass,
		L"My Window created by CreateEx()",
		WS_VISIBLE | WS_OVERLAPPEDWINDOW,
		CRect(0, 0, 500, 500),
		this,
		0
	);
	return 0;
}
