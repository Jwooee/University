// AddConstDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "AddConstDlg.h"
#include "afxdialogex.h"


// CAddConstDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CAddConstDlg, CDialogEx)

CAddConstDlg::CAddConstDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddConstDlg::IDD, pParent)
	, m_nAddConst(0)
{

}

CAddConstDlg::~CAddConstDlg()
{
}

void CAddConstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ADDCONSET_EDIT, m_nAddConst);
	DDV_MinMaxInt(pDX, m_nAddConst, 0, 255);
}


BEGIN_MESSAGE_MAP(CAddConstDlg, CDialogEx)
	ON_EN_CHANGE(IDC_ADDCONSET_EDIT, &CAddConstDlg::OnEnChangeAddconsetEdit)
END_MESSAGE_MAP()


// CAddConstDlg �޽��� ó�����Դϴ�.


BOOL CAddConstDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CAddConstDlg::OnEnChangeAddconsetEdit()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	UpdateData(TRUE);

}
