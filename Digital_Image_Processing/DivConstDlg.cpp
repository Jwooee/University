// DivConstDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "DivConstDlg.h"
#include "afxdialogex.h"


// CDivConstDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDivConstDlg, CDialogEx)

CDivConstDlg::CDivConstDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDivConstDlg::IDD, pParent)
	, m_dDivConst(0)
{

}

CDivConstDlg::~CDivConstDlg()
{
}

void CDivConstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_DIVCONST_EDIT, m_nDivConst);
	//  DDV_MinMaxInt(pDX, m_nDivConst, 0, 255);
	DDX_Text(pDX, IDC_DIVCONST_EDIT, m_dDivConst);
	DDV_MinMaxDouble(pDX, m_dDivConst, 1.0, 32.0);
}


BEGIN_MESSAGE_MAP(CDivConstDlg, CDialogEx)
	ON_EN_CHANGE(IDC_DIVCONST_EDIT, &CDivConstDlg::OnEnChangeDivconstEdit)
END_MESSAGE_MAP()


// CDivConstDlg 메시지 처리기입니다.


void CDivConstDlg::OnEnChangeDivconstEdit()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
