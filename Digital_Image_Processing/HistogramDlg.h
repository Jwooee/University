#pragma once


// CHistogramDlg ��ȭ �����Դϴ�.

class CHistogramDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHistogramDlg)

public:
	CHistogramDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CHistogramDlg();

	// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_HISTOGTAM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_nHistogram[256];
	int m_nMin;
	int m_nMax;
	void SetImage(IppDib pDib); //�����Լ� 
	afx_msg void OnPaint();
};
