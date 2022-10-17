// CMyDlg.cpp: 구현 파일
//

#include "pch.h"
#include "My2.h"
#include "afxdialogex.h"
#include "CMyDlg.h"


// CMyDlg 대화 상자

IMPLEMENT_DYNAMIC(CMyDlg, CDialogEx)

CMyDlg::CMyDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CMyDlg::~CMyDlg()
{
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CMyDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT2, &CMyDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &CMyDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()

// CMyDlg 메시지 처리기

void CMyDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void CMyDlg::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMyDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMyDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CEdit* pEdit;
	pEdit = (CEdit*)GetDlgItem(IDC_EDIT2);

	CString strMsg;
	pEdit->GetWindowText(strMsg);

	pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	pEdit->SetWindowTextW(strMsg);

	m_strMsg = strMsg; // 객체 변수로 전달
}
