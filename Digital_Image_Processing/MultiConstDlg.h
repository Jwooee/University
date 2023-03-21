#pragma once


// CMultiConstDlg 대화 상자입니다.

class CMultiConstDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMultiConstDlg)

public:
	CMultiConstDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMultiConstDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MULTI_CONST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	double m_dMultiConst;
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeMulticonsetEdit();
};
