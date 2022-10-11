#pragma once


// CMyWnd

class CMyWnd : public CWnd
{
	DECLARE_DYNAMIC(CMyWnd)

public:
	CMyWnd();
	virtual ~CMyWnd();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};


