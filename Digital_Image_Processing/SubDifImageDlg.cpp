// SubDifImageDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "SubDifImageDlg.h"
#include "afxdialogex.h"

//���� �Ѱ�
#include "ImageToolDoc.h"
///////////

// SubDifImageDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(SubDifImageDlg, CDialogEx)

SubDifImageDlg::SubDifImageDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SubDifImageDlg::IDD, pParent)
	, m_nFunction(0), m_pDoc1(NULL), m_pDoc2(NULL)
{

}

SubDifImageDlg::~SubDifImageDlg()
{
}

void SubDifImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_IMAGE1, m_comboImage1);
	DDX_Control(pDX, IDC_COMBO_IMAGE2, m_comboImage2);
	DDX_Radio(pDX, IDC_RADIO1, m_nFunction);
}


BEGIN_MESSAGE_MAP(SubDifImageDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &SubDifImageDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// SubDifImageDlg �޽��� ó�����Դϴ�.


BOOL SubDifImageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	int nIndex = 0;
	CString strTitle;

	CImageToolApp* pApp = (CImageToolApp*)AfxGetApp();
	POSITION pos = pApp->m_pImageDocTemplate->GetFirstDocPosition();

	while (pos != NULL)
	{
		CImageToolDoc* pDoc = (CImageToolDoc*)pApp->m_pImageDocTemplate->GetNextDoc(pos);

		if (pDoc->m_Dib.GetBitCount() != 8)
			continue;

		strTitle = pDoc->GetTitle();
		m_comboImage1.InsertString(nIndex, strTitle);
		m_comboImage2.InsertString(nIndex, strTitle);

		m_comboImage1.SetItemDataPtr(nIndex, (void*)pDoc);
		m_comboImage2.SetItemDataPtr(nIndex, (void*)pDoc);

		nIndex++;
	}

	m_comboImage1.SetCurSel(0);
	m_comboImage2.SetCurSel(0);
	if (nIndex > 1)
		m_comboImage2.SetCurSel(1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void SubDifImageDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_pDoc1 = (CImageToolDoc*)m_comboImage1.GetItemDataPtr(m_comboImage1.GetCurSel());
	m_pDoc2 = (CImageToolDoc*)m_comboImage2.GetItemDataPtr(m_comboImage2.GetCurSel());

	CDialogEx::OnOK();
}
