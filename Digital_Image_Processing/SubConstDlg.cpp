// SubConstDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "SubConstDlg.h"
#include "afxdialogex.h"


// CSubConstDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CSubConstDlg, CDialogEx)

CSubConstDlg::CSubConstDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSubConstDlg::IDD, pParent)
	, m_nSubConst(0)
{

}

CSubConstDlg::~CSubConstDlg()
{
}

void CSubConstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SUBCONST_EDIT, m_nSubConst);
	DDV_MinMaxInt(pDX, m_nSubConst, 0, 255);
}


BEGIN_MESSAGE_MAP(CSubConstDlg, CDialogEx)
	ON_EN_CHANGE(IDC_SUBCONST_EDIT, &CSubConstDlg::OnEnChangeSubconstEdit)
END_MESSAGE_MAP()


// CSubConstDlg �޽��� ó�����Դϴ�.


void CSubConstDlg::OnEnChangeSubconstEdit()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


BOOL CSubConstDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
