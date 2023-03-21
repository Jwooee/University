#pragma once


// CGammaDlg 대화 상자입니다.

class CGammaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGammaDlg)

public:
	CGammaDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CGammaDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_GAM_CONST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	// 감마
	double e_r1;
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeGamEdit();
};
