﻿
// ChildView.h: CChildView 클래스의 인터페이스
//


#pragma once


// CChildView 창
// class CMyWnd;
#include "CMyWnd.h"

class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();

// 특성입니다.
public:
	CMyWnd m_wndMy;

// 작업입니다.
public:

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CChildView();

	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTestMin(); 
	afx_msg void OnTestMax();
	afx_msg void OnTestTest();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

