#pragma once


// CIppGeometryDlg 대화 상자입니다.

class CIppGeometryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CIppGeometryDlg)

public:
	CIppGeometryDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CIppGeometryDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MOVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	// x좌표 
	int m_neditx1;
	// 좌표y
	int m_nedit2y;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedOk();
};
