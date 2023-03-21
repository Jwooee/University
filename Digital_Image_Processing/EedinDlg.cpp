// EedinDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "EedinDlg.h"
#include "afxdialogex.h"


// CEedinDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CEedinDlg, CDialogEx)

CEedinDlg::CEedinDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEedinDlg::IDD, pParent)
	, n_min(0)
	, m_max(0)
{

}

CEedinDlg::~CEedinDlg()
{
}

void CEedinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, n_min);
	DDV_MinMaxInt(pDX, n_min, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, m_max);
	DDV_MinMaxInt(pDX, m_max, 0, 255);
}


BEGIN_MESSAGE_MAP(CEedinDlg, CDialogEx)
END_MESSAGE_MAP()


// CEedinDlg 메시지 처리기입니다.
