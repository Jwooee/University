#pragma once
#include "afxwin.h"


// CAddAvgImageDlg ��ȭ �����Դϴ�.

class CAddAvgImageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddAvgImageDlg)

public:
	CAddAvgImageDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAddAvgImageDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ADDAVG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	// �޹�1
	CComboBox m_comboImage1;
	// �޺�2
	CComboBox m_comboImage2;
	// ����
	int m_nFunction;

	//���� ����
	void*m_pDoc1;
	void*m_pDoc2;
	//////////////

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
