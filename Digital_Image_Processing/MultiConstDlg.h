#pragma once


// CMultiConstDlg ��ȭ �����Դϴ�.

class CMultiConstDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMultiConstDlg)

public:
	CMultiConstDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMultiConstDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MULTI_CONST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	double m_dMultiConst;
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeMulticonsetEdit();
};
