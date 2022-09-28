#pragma once

class CMyBtn : public CButton
{
public:
	CMyBtn();
	~CMyBtn();

	LRESULT WindowProc(UINT, WPARAM, LPARAM);
	/*
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	DECLARE_MESSAGE_MAP() 
	*/
};