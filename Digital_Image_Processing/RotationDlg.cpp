// RotationDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "RotationDlg.h"
#include "afxdialogex.h"


// CRotationDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CRotationDlg, CDialogEx)

CRotationDlg::CRotationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRotationDlg::IDD, pParent)
	, m_nDgree(0)
{

}

CRotationDlg::~CRotationDlg()
{
}

void CRotationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SUBCONST_EDIT, m_nDgree);
	DDV_MinMaxInt(pDX, m_nDgree, -359, 359);
}


BEGIN_MESSAGE_MAP(CRotationDlg, CDialogEx)
END_MESSAGE_MAP()


// CRotationDlg �޽��� ó�����Դϴ�.
