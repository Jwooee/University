#pragma once


// CAddConstDlg 대화 상자입니다.

class CAddConstDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddConstDlg)

public:
	CAddConstDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CAddConstDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ADD_CONST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_nAddConst;
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeAddconsetEdit();
};
