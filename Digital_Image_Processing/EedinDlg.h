#pragma once


// CEedinDlg 대화 상자입니다.

class CEedinDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEedinDlg)

public:
	CEedinDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CEedinDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_END_IN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int n_min;
	int m_max;
};
