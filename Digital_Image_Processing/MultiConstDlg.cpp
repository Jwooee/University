// MultiConstDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "MultiConstDlg.h"
#include "afxdialogex.h"


// CMultiConstDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMultiConstDlg, CDialogEx)

CMultiConstDlg::CMultiConstDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMultiConstDlg::IDD, pParent)
	, m_dMultiConst(0)
{

}

CMultiConstDlg::~CMultiConstDlg()
{
}

void CMultiConstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MULTICONSET_EDIT, m_dMultiConst);
	DDV_MinMaxDouble(pDX, m_dMultiConst, 1.0, 32.0);
}


BEGIN_MESSAGE_MAP(CMultiConstDlg, CDialogEx)
	ON_EN_CHANGE(IDC_MULTICONSET_EDIT, &CMultiConstDlg::OnEnChangeMulticonsetEdit)
END_MESSAGE_MAP()


// CMultiConstDlg 메시지 처리기입니다.


BOOL CMultiConstDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CMultiConstDlg::OnEnChangeMulticonsetEdit()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
