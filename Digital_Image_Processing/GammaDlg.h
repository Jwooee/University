#pragma once


// CGammaDlg ��ȭ �����Դϴ�.

class CGammaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGammaDlg)

public:
	CGammaDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CGammaDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_GAM_CONST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	// ����
	double e_r1;
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeGamEdit();
};
