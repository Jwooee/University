#pragma once


// CIppResizeNearestDlg ��ȭ �����Դϴ�.

class CIppResizeNearestDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CIppResizeNearestDlg)

public:
	CIppResizeNearestDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CIppResizeNearestDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SIZEUP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	// ����
	int m_nsizeup;
	// ����
	int m_nFunction;
};
