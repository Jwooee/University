// PrepareDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "PrepareDlg.h"
#include "afxdialogex.h"


// PrepareDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(PrepareDlg, CDialogEx)

PrepareDlg::PrepareDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(PrepareDlg::IDD, pParent)
	, e_x1(1)
	, e_y1(0)
{

}

PrepareDlg::~PrepareDlg()
{
}

void PrepareDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PRE_EDIT, e_x1);
	DDV_MinMaxDouble(pDX, e_x1, -1.0, 64.0);
	DDX_Text(pDX, IDC_PRE2_EDIT, e_y1);
	DDV_MinMaxDouble(pDX, e_y1, -255, 255);
}


BEGIN_MESSAGE_MAP(PrepareDlg, CDialogEx)
	ON_EN_CHANGE(IDC_PRE_EDIT, &PrepareDlg::OnEnChangePreEdit)
	ON_EN_CHANGE(IDC_PRE2_EDIT, &PrepareDlg::OnEnChangePre2Edit)
END_MESSAGE_MAP()


// PrepareDlg �޽��� ó�����Դϴ�.


BOOL PrepareDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void PrepareDlg::OnEnChangePreEdit()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void PrepareDlg::OnEnChangePre2Edit()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
