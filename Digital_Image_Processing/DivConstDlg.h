#pragma once


// CDivConstDlg ��ȭ �����Դϴ�.

class CDivConstDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDivConstDlg)

public:
	CDivConstDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDivConstDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDC_DIV_CONST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
//	int m_nDivConst;
	afx_msg void OnEnChangeDivconstEdit();
	double m_dDivConst;
};
