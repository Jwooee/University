// IppGeometryDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "IppGeometryDlg.h"
#include "afxdialogex.h"


// CIppGeometryDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CIppGeometryDlg, CDialogEx)

CIppGeometryDlg::CIppGeometryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CIppGeometryDlg::IDD, pParent)
	, m_neditx1(0)
	, m_nedit2y(0)
{

}

CIppGeometryDlg::~CIppGeometryDlg()
{
}

void CIppGeometryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_neditx1);
	DDX_Text(pDX, IDC_EDIT2, m_nedit2y);
}


BEGIN_MESSAGE_MAP(CIppGeometryDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CIppGeometryDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CIppGeometryDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDOK, &CIppGeometryDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CIppGeometryDlg 메시지 처리기입니다.


void CIppGeometryDlg::OnEnChangeEdit1()
{
	UpdateData (TRUE);
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CIppGeometryDlg::OnEnChangeEdit2()
{
	UpdateData(TRUE);

	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CIppGeometryDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}
