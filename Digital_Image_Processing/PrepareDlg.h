#pragma once


// PrepareDlg 대화 상자입니다.

class PrepareDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PrepareDlg)

public:
	PrepareDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~PrepareDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PRE_CONST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	// 기울기
	double e_x1;
	// 절편
	double e_y1;
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangePreEdit();
	afx_msg void OnEnChangePre2Edit();
};
