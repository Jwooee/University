#pragma once
#include "afxwin.h"


// CLogicDlg ��ȭ �����Դϴ�.

class CLogicDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLogicDlg)

public:
	CLogicDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CLogicDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_LOGIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	// �޹�1
	CComboBox m_comboImage1;
	// �޹�2
	CComboBox m_comboImage2;
	// ����1
	int m_nFunction;

	//���� ����
	void*m_pDoc1;
	void*m_pDoc2;
	//////////////


	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
