#pragma once
#include "afxwin.h"


// CAddAvgImageDlg 대화 상자입니다.

class CAddAvgImageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddAvgImageDlg)

public:
	CAddAvgImageDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CAddAvgImageDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ADDAVG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	// 콤박1
	CComboBox m_comboImage1;
	// 콤보2
	CComboBox m_comboImage2;
	// 덧셈
	int m_nFunction;

	//내가 쓴거
	void*m_pDoc1;
	void*m_pDoc2;
	//////////////

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
