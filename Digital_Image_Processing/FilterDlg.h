#pragma once


// CFilterDlg 대화 상자입니다.

class CFilterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFilterDlg)

public:
	CFilterDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFilterDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_NOISE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_nAmount;
	// 라디오
	int m_nFunction;
};
