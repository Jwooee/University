#pragma once


// PrepareDlg ��ȭ �����Դϴ�.

class PrepareDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PrepareDlg)

public:
	PrepareDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~PrepareDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PRE_CONST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	// ����
	double e_x1;
	// ����
	double e_y1;
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangePreEdit();
	afx_msg void OnEnChangePre2Edit();
};
