// GammaDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "GammaDlg.h"
#include "afxdialogex.h"


// CGammaDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CGammaDlg, CDialogEx)

CGammaDlg::CGammaDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGammaDlg::IDD, pParent)
	, e_r1(0)
{

}

CGammaDlg::~CGammaDlg()
{
}

void CGammaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_GAM_EDIT, e_r1);
	DDV_MinMaxDouble(pDX, e_r1, 0.0, 32.0);
}


BEGIN_MESSAGE_MAP(CGammaDlg, CDialogEx)
	ON_EN_CHANGE(IDC_GAM_EDIT, &CGammaDlg::OnEnChangeGamEdit)
END_MESSAGE_MAP()


// CGammaDlg �޽��� ó�����Դϴ�.


BOOL CGammaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.


	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CGammaDlg::OnEnChangeGamEdit()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
