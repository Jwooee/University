// HistogramDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "HistogramDlg.h"
#include "afxdialogex.h"

//���� ����
#include "IppImage\IppDib.h"
#include "IppImage\IppImage.h"
#include "IppImage\IppConvert.h"
#include "GetHistogram.h"
//

// CHistogramDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CHistogramDlg, CDialogEx)

CHistogramDlg::CHistogramDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CHistogramDlg::IDD, pParent)
//, m_nHistogram(0)
, m_nMin(0)
, m_nMax(255)
{
	memset(m_nHistogram, 0, sizeof(int)* 256); //m_nHistogram[256] = {0}; //int 4����Ʈ�� 0���� �ʰ�ȭ���ִ°� sizof ��ŭ
}

CHistogramDlg::~CHistogramDlg()
{
}

void CHistogramDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MIN_EDIT, m_nMin);
	DDX_Text(pDX, IDC_MAX_EDIT, m_nMax);
}

BEGIN_MESSAGE_MAP(CHistogramDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CHistogramDlg �޽��� ó�����Դϴ�.

void CHistogramDlg::SetImage(IppDib pDib) //��Ʈ�� pDib
{
	if (&pDib != NULL && pDib.GetBitCount() == 8)
	{
		IppByteImage img;
		IppDibToImage(pDib, img);
		double histo[256] = { 0.0 };
		GetHistogram(img, histo);
		double max_histo = histo[0];

		for (int i = 1; i < 256; i++)
		{
			if (histo[i] > max_histo)
				max_histo = histo[i];
		}
		for (int i = 0; i < 256; i++)
			m_nHistogram[i] = static_cast<int>(histo[i] * 100. / max_histo); //m_nHistogram[i]�� y�� �׷����� �ִ��� max_histo �ִ����� ����
	}
	else
	{
		memset(m_nHistogram, 0, sizeof(int)* 256);
	}
}

void CHistogramDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CDialogEx::OnPaint()��(��) ȣ������ ���ʽÿ�.
	CGdiObject* pOIdpen = dc.SelectStockObject(DC_PEN); 	//�Ҽ��� SelectStockObject


	dc.SetDCPenColor(RGB(128, 128, 128));	dc.MoveTo(20, 20); 	//SetDCPenColor �� ����

	dc.LineTo(20, 120);						dc.LineTo(275, 120);
	dc.LineTo(275, 20);						dc.LineTo(20, 20);
	dc.SetDCPenColor(RGB(0, 0, 0));

	for (int i = 0; i < 256; i++)
	{
		dc.MoveTo(20 + i, 120);
		dc.LineTo(20 + i, 120 - m_nHistogram[i]);
	}
	for (int i = 0; i < 256; i++)
	{
		dc.SetDCPenColor(RGB(i, i, i));
		dc.MoveTo(20 + i, 130);
		dc.LineTo(20 + i, 145);
	}
	dc.SelectObject(pOIdpen);
	UpdateData(FALSE);
}
