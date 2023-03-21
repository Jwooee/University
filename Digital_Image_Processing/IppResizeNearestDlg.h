#pragma once


// CIppResizeNearestDlg 대화 상자입니다.

class CIppResizeNearestDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CIppResizeNearestDlg)

public:
	CIppResizeNearestDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CIppResizeNearestDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SIZEUP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	// 배율
	int m_nsizeup;
	// 라디오
	int m_nFunction;
};
