#pragma once
#include "afxwin.h"


// CGImageDlg ��ȭ �����Դϴ�.

class CGImageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGImageDlg)

public:
	CGImageDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CGImageDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_SIZEDown };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	// ����
	int m_nsizedown;
	int m_nFunction;
};
