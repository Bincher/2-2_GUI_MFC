#pragma once


// CMyBtn

class CMyBtn : public CMFCButton
{
	DECLARE_DYNAMIC(CMyBtn)

public:
	CMyBtn();
	virtual ~CMyBtn();

protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
};


