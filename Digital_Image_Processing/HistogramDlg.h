#pragma once


// CHistogramDlg 대화 상자입니다.

class CHistogramDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CHistogramDlg)

public:
	CHistogramDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CHistogramDlg();

	// 대화 상자 데이터입니다.
	enum { IDD = IDD_HISTOGTAM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_nHistogram[256];
	int m_nMin;
	int m_nMax;
	void SetImage(IppDib pDib); //내부함수 
	afx_msg void OnPaint();
};
