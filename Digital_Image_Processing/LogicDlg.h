#pragma once
#include "afxwin.h"


// CLogicDlg 대화 상자입니다.

class CLogicDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLogicDlg)

public:
	CLogicDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CLogicDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_LOGIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	// 콤박1
	CComboBox m_comboImage1;
	// 콤박2
	CComboBox m_comboImage2;
	// 라디오1
	int m_nFunction;

	//내가 쓴거
	void*m_pDoc1;
	void*m_pDoc2;
	//////////////


	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
