#pragma once
#include "afxwin.h"


// SubDifImageDlg ��ȭ �����Դϴ�.

class SubDifImageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SubDifImageDlg)

public:
	SubDifImageDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~SubDifImageDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SUBDIF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	// �޺�1
	CComboBox m_comboImage1;
	// �޺�2
	CComboBox m_comboImage2;
	// ����
	int m_nFunction;

	//���� ����
	void*m_pDoc1;
	void*m_pDoc2;
	//////////////


	afx_msg void OnBnClickedOk();
};
