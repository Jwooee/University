#pragma once


// CSubConstDlg ��ȭ �����Դϴ�.

class CSubConstDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSubConstDlg)

public:
	CSubConstDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSubConstDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SUB_CONST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_nSubConst;
	afx_msg void OnEnChangeSubconstEdit();
	virtual BOOL OnInitDialog();
};
