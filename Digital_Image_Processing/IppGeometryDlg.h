#pragma once


// CIppGeometryDlg ��ȭ �����Դϴ�.

class CIppGeometryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CIppGeometryDlg)

public:
	CIppGeometryDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CIppGeometryDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MOVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	// x��ǥ 
	int m_neditx1;
	// ��ǥy
	int m_nedit2y;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedOk();
};
