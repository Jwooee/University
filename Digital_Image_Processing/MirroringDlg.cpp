// MirroringDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "MirroringDlg.h"
#include "afxdialogex.h"


// CMirroringDlg ��ȭ �����Դϴ�.

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


// CMirroringDlg �޽��� ó�����Դϴ�.
