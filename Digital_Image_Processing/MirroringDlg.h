#pragma once


// CMirroringDlg 대화 상자입니다.

class CMirroringDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMirroringDlg)

public:
	CMirroringDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMirroringDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MIRR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	// 미러링 사이즈
	int n_Msize;
};
