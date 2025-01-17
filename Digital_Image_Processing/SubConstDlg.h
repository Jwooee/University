#pragma once


// CSubConstDlg 대화 상자입니다.

class CSubConstDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSubConstDlg)

public:
	CSubConstDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSubConstDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SUB_CONST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_nSubConst;
	afx_msg void OnEnChangeSubconstEdit();
	virtual BOOL OnInitDialog();
};
