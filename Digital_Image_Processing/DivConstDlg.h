#pragma once


// CDivConstDlg 대화 상자입니다.

class CDivConstDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDivConstDlg)

public:
	CDivConstDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDivConstDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDC_DIV_CONST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
//	int m_nDivConst;
	afx_msg void OnEnChangeDivconstEdit();
	double m_dDivConst;
};
