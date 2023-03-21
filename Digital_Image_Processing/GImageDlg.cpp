// GImageDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "GImageDlg.h"
#include "afxdialogex.h"


// CGImageDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CGImageDlg, CDialogEx)

CGImageDlg::CGImageDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGImageDlg::IDD, pParent)
	, m_nsizedown(2)
	, m_nFunction(0)
{

}

CGImageDlg::~CGImageDlg()
{
}

void CGImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nsizedown);
	DDV_MinMaxInt(pDX, m_nsizedown, 0, 10);
	DDX_Radio(pDX, IDC_RADIO1, m_nFunction);
}


BEGIN_MESSAGE_MAP(CGImageDlg, CDialogEx)
END_MESSAGE_MAP()


// CGImageDlg �޽��� ó�����Դϴ�.
