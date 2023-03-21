// MultiConstDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "MultiConstDlg.h"
#include "afxdialogex.h"


// CMultiConstDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CMultiConstDlg, CDialogEx)

CMultiConstDlg::CMultiConstDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMultiConstDlg::IDD, pParent)
	, m_dMultiConst(0)
{

}

CMultiConstDlg::~CMultiConstDlg()
{
}

void CMultiConstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MULTICONSET_EDIT, m_dMultiConst);
	DDV_MinMaxDouble(pDX, m_dMultiConst, 1.0, 32.0);
}


BEGIN_MESSAGE_MAP(CMultiConstDlg, CDialogEx)
	ON_EN_CHANGE(IDC_MULTICONSET_EDIT, &CMultiConstDlg::OnEnChangeMulticonsetEdit)
END_MESSAGE_MAP()


// CMultiConstDlg �޽��� ó�����Դϴ�.


BOOL CMultiConstDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CMultiConstDlg::OnEnChangeMulticonsetEdit()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
