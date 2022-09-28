
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "My.h"
#include "ChildView.h"
#include "CMyBtn.h" // new에서 필요

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_pBtn = NULL;
}

CChildView::~CChildView()
{
	if (m_pBtn)
	{
		m_pBtn->DestroyWindow();
		delete m_pBtn; // CButton 클래스의 객체를 생성 -> 지워라
	}
}

// 맵핑 매크로
BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN() //넣어주기
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
	//ON_COMMAND(999, OnClick)
	ON_BN_CLICKED(999, OnClick)
	//ON_EN_CHANGED CEdit
	ON_MESSAGE(WM_MYMESSAGE, OnMyMessage)
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() // WM_PAINT
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	//MessageBox(L"Left Button Down", L"MSG", MB_OK); // wide Character
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//MessageBox(L"Left Button Up", L"MSG", MB_OK);
	::MessageBox(this->m_hWnd, L"AAA", L"BBB", MB_OK); // win32 함수로 전환, child가 가지고 있는 m_hWnd
	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	/*
	HDC hdc;
	hdc = GetDC();
	TextOut(hdc, 0, 0, "dddd", 5);
	ReleaseDC(hWnd, hdc);
	*/
	CDC* pDC;
	pDC = this->GetDC();
	CString strPos; // CString 공부해보기
	strPos.Format(L"%04d %04d", point.x, point.y);
	pDC->TextOut(0, 0, strPos);
	this->ReleaseDC(pDC); // this-> 는 생략가능

	CWnd::OnMouseMove(nFlags, point);
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	m_pBtn = new CMyBtn();

	m_pBtn->Create(L"click",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		CRect(100, 100, 200, 200), this, 999); 

	return 0;
}

void CChildView::OnClick()
{
	//MessageBox(L"Clicked on the button", L"MSG", MB_OK);
	this->SendMessage(WM_MYMESSAGE, 0, 0);
}

LRESULT CChildView::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	MessageBox(L"WM_MYMESSAGE", L"MSG", MB_OK);
	return 0;
}

// 메시지맵을 이용한 메시지(이벤트) 처리

// 1. ON_WM_CREATE(), OnCreate()

// 2. ON_COMMAND(id, OnClick) void OnClick()

// 3. ON_BN_CLICKED(id, OnClick)

// 4. 상속을 하여 처리
// class CMyBtn: public CButton {}
// 새항목추가, ~.h, ~.cpp, 위저드를 이용해서 클래스를 추가하면, 이벤트처리도 위저드를 통해서 쉽게 할 수 있다.

// 5. ON_MESSAGE(WM_MYMSG, OnMyMsg)
//    LRESULT OnMyMsg(WPARAM, LPARAM)

// 6. Win32 처럼 처리
// LRESULT windowProc(UINT msg, WAPARAM, LPARAM) {return CWnd::DefaultwindowProc(msg, wParam, lParam);}

// keywords : CWnd MSDN