#pragma once
#include "afxdialogex.h"


// CMyDlg 대화 상자


class CMyDlg : public CDialogEx
{
	

	DECLARE_DYNAMIC(CMyDlg)

public:
	CString m_strMsg;
	CMyDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMyDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
};
