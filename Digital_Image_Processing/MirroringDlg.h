#pragma once


// CMirroringDlg ��ȭ �����Դϴ�.

class CMirroringDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMirroringDlg)

public:
	CMirroringDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMirroringDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MIRR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	// �̷��� ������
	int n_Msize;
};
