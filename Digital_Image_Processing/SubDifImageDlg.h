#pragma once
#include "afxwin.h"


// SubDifImageDlg 대화 상자입니다.

class SubDifImageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SubDifImageDlg)

public:
	SubDifImageDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~SubDifImageDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SUBDIF };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	// 콤보1
	CComboBox m_comboImage1;
	// 콤보2
	CComboBox m_comboImage2;
	// 뺄샘
	int m_nFunction;

	//내가 쓴거
	void*m_pDoc1;
	void*m_pDoc2;
	//////////////


	afx_msg void OnBnClickedOk();
};
