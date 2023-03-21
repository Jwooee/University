#pragma once
#include "afxwin.h"


// CGImageDlg 대화 상자입니다.

class CGImageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGImageDlg)

public:
	CGImageDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CGImageDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SIZEDown };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	// 배율
	int m_nsizedown;
	int m_nFunction;
};
