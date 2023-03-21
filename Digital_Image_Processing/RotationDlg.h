#pragma once


// CRotationDlg 대화 상자입니다.

class CRotationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRotationDlg)

public:
	CRotationDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CRotationDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ROTATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	// 각도
	int m_nDgree;
};
