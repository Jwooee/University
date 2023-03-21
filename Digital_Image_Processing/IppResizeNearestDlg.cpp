// IppResizeNearestDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "IppResizeNearestDlg.h"
#include "afxdialogex.h"


// CIppResizeNearestDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CIppResizeNearestDlg, CDialogEx)

CIppResizeNearestDlg::CIppResizeNearestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CIppResizeNearestDlg::IDD, pParent)
	, m_nsizeup(2)
	, m_nFunction(0)
{

}

CIppResizeNearestDlg::~CIppResizeNearestDlg()
{
}

void CIppResizeNearestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nsizeup);
	DDV_MinMaxInt(pDX, m_nsizeup, 1, 10);
	DDX_Radio(pDX, IDC_RADIO1, m_nFunction);
}


BEGIN_MESSAGE_MAP(CIppResizeNearestDlg, CDialogEx)
END_MESSAGE_MAP()


// CIppResizeNearestDlg �޽��� ó�����Դϴ�.
