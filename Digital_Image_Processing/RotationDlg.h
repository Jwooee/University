#pragma once


// CRotationDlg ��ȭ �����Դϴ�.

class CRotationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRotationDlg)

public:
	CRotationDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CRotationDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ROTATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	// ����
	int m_nDgree;
};
