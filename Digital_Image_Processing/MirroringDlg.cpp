// MirroringDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "MirroringDlg.h"
#include "afxdialogex.h"


// CMirroringDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMirroringDlg, CDialogEx)

CMirroringDlg::CMirroringDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMirroringDlg::IDD, pParent)
	, n_Msize(0)
{

}

CMirroringDlg::~CMirroringDlg()
{
}

void CMirroringDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, n_Msize);
}


BEGIN_MESSAGE_MAP(CMirroringDlg, CDialogEx)
END_MESSAGE_MAP()


// CMirroringDlg 메시지 처리기입니다.
