#pragma once


// CEedinDlg ��ȭ �����Դϴ�.

class CEedinDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEedinDlg)

public:
	CEedinDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CEedinDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_END_IN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int n_min;
	int m_max;
};
