#pragma once


// CFilterDlg ��ȭ �����Դϴ�.

class CFilterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFilterDlg)

public:
	CFilterDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFilterDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_NOISE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_nAmount;
	// ����
	int m_nFunction;
};
