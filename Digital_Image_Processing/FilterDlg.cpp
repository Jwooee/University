// FilterDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "FilterDlg.h"
#include "afxdialogex.h"


// CFilterDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFilterDlg, CDialogEx)

CFilterDlg::CFilterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFilterDlg::IDD, pParent)
	, m_nAmount(0)
	, m_nFunction(0)
{

}

CFilterDlg::~CFilterDlg()
{
}

void CFilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nAmount);
	DDV_MinMaxInt(pDX, m_nAmount, 0, 100);
	DDX_Radio(pDX, IDC_RADIO1, m_nFunction);
}


BEGIN_MESSAGE_MAP(CFilterDlg, CDialogEx)
END_MESSAGE_MAP()


// CFilterDlg 메시지 처리기입니다.
