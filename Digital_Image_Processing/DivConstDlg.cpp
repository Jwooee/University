// DivConstDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "DivConstDlg.h"
#include "afxdialogex.h"


// CDivConstDlg ��ȭ �����Դϴ�.

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


// CDivConstDlg �޽��� ó�����Դϴ�.


void CDivConstDlg::OnEnChangeDivconstEdit()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
