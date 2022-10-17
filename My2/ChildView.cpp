
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "My2.h"
#include "ChildView.h"
#include "MainFrm.h"
#include "CMyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CPoint m_point;
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
	//ON_WM_CREATE()
	ON_COMMAND(ID_TEST_MIN, &CChildView::OnTestMin)
	ON_COMMAND(ID_TEST_MAX, &CChildView::OnTestMax)
	ON_COMMAND(ID_TEST_TEST, &CChildView::OnTestTest)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) // OnCreate() 전에 자동으로 먼저 호출
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	/*
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);
	*/
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(nullptr, IDC_ARROW), (HBRUSH)::GetStockObject(WHITE_BRUSH), nullptr);
	
	// AfxRegisterWndClass : 윈도우클래스 정의,등록 처리

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	// CDC *pDC 와 같음 + 더 지능적인 처리 가능

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CRect rt;
	rt.left = m_point.x - 50; // point는 OnLButtonDown()에서 넘어온 것임으로 멤버 변수로 대치
	rt.top = m_point.y - 50;
	rt.right = m_point.x + 50;
	rt.bottom = m_point.y + 50;

	CPen pen, * oldPen;
	pen.CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	oldPen = dc.SelectObject(&pen);

	dc.Rectangle(rt);

	dc.SelectObject(oldPen);
	pen.DeleteObject();

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

void CChildView::OnTestMin()
{
	this->MoveWindow(CRect(200, 200, 500, 500));
}

// My2.h에 extern CMy2App theApp; 를 없애면 동작 x
// extern CMy2App theApp; 정상
// CMy2App theApp; 중복선언

void CChildView::OnTestMax()
{
	CRect rt;
	// 프레임 윈도우에서 클라이언트 영역의 크기를 알아내서 다시 차일드 윈도우를 움직여준다
	//GetClientRect(rt); //this->MoveWindow(rt) - ChildView 그러나 Mainfirm에서 받아야됨
	//MoveWindow(rt); //this->MoveWindow(rt)
	
	// #include "mainfrm.h"
	//CMainFrame* pFrame;
	//pFrame = (CMainFrame*)this->GetParent();
	// or

	CMainFrame* pFrame = 0; // 일반적인 경우에 메인 프레임에 접근하는 방법이 필요
	//                      CMyApp()에 접근하는 방법이 필요
	
	CMy2App* pApp = 0;
	//pApp = &theApp;
	pApp = (CMy2App*)AfxGetApp();
	//pFrame = (CMainFrame*)pApp->m_pMainWnd;
	pFrame = (CMainFrame*)AfxGetMainWnd();
	pFrame->GetClientRect(rt);
	//CFrameWnd*

	/*
	pFrame = (CMainFrame*)this->GetParent();
	pFrame = (CMainFrame*)GetParent();
	pFrame->GetClientRect(rt);
	*/
//	MoveWindow(rt); 툴바 없으면
//  툴바 적용시
	CMFCToolBar* pTool;
	pTool = &pFrame->m_wndToolBar;
	if (!pTool->IsFloating())
	{
		CRect rtTool;
		pTool->GetWindowRect(rtTool);
		rt.top = rt.top + rtTool.Height();
	}

	CMFCMenuBar* pMenu;
	pMenu = &pFrame->m_wndMenuBar;
	if (!pMenu->IsFloating())
	{
		CRect rtMenu;
		pMenu->GetWindowRect(rtMenu);
		rt.top = rt.top + rtMenu.Height();
	}

	this->MoveWindow(rt);
	//InitInstance(), ExitInstance(), Run()

	//AfxGetMainWnd()
	//AfxGetApp()
	//AfxGetInstancHandle()
}

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CDC* pDC;
	pDC = GetDC(); // 사용 시작 -> 포인터 연결

	CRect rt;
	rt.left = point.x - 50;
	rt.top = point.y - 50;
	rt.right = point.x + 50;
	rt.bottom = point.y + 50;

	CPen pen, * oldPen;
	pen.CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	oldPen = pDC->SelectObject(&pen);

	pDC->Rectangle(rt);

	pDC->SelectObject(oldPen); // 중요
	pen.DeleteObject();
	
	
	ReleaseDC(pDC); // 사용 끝 -> 포인터 해제
	m_point = point;
	Invalidate(); // 특정 영역만 무효화 (UpdateWindow()는 생략 가능)
	UpdateWindow(); // 화면을 무효화 시킨다 -> 적절한 시점에 WM_PAINT 메시지 발생 유발
	CWnd::OnLButtonDown(nFlags, point);

	// WM_PAINT는 출력 당시만 유효
	// 계속 표시되어야 하면 OnPaint() 또는 OnDraw() 함수에 구현
}

void CChildView::OnTestTest()
{
	CMyDlg dlg(this); // 대화상자 객체 생성
	if (dlg.DoModal() == IDOK)// CreateWindow역할 대신 DoModal -> 대화상자 화면에 나타내기
	{
		CClientDC dc(this); // GetDC, ReleaseDC 불필요. 클라이언트 영역 출력에 한정
		dc.TextOutW(0, 0, dlg.m_strMsg);
	}
	// 닫힐땐 CDialog::onOK()
}