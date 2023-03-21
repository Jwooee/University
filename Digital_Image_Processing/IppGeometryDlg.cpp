// IppGeometryDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "IppGeometryDlg.h"
#include "afxdialogex.h"


// CIppGeometryDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CIppGeometryDlg, CDialogEx)

CIppGeometryDlg::CIppGeometryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CIppGeometryDlg::IDD, pParent)
	, m_neditx1(0)
	, m_nedit2y(0)
{

}

CIppGeometryDlg::~CIppGeometryDlg()
{
}

void CIppGeometryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_neditx1);
	DDX_Text(pDX, IDC_EDIT2, m_nedit2y);
}


BEGIN_MESSAGE_MAP(CIppGeometryDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &CIppGeometryDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CIppGeometryDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDOK, &CIppGeometryDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CIppGeometryDlg �޽��� ó�����Դϴ�.


void CIppGeometryDlg::OnEnChangeEdit1()
{
	UpdateData (TRUE);
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CIppGeometryDlg::OnEnChangeEdit2()
{
	UpdateData(TRUE);

	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CIppGeometryDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnOK();
}
