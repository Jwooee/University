#pragma once


// CAddConstDlg ��ȭ �����Դϴ�.

class CAddConstDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddConstDlg)

public:
	CAddConstDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAddConstDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ADD_CONST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_nAddConst;
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeAddconsetEdit();
};
