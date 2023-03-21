// HistogramDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ImageTool.h"
#include "HistogramDlg.h"
#include "afxdialogex.h"

//내가 쓴거
#include "IppImage\IppDib.h"
#include "IppImage\IppImage.h"
#include "IppImage\IppConvert.h"
#include "GetHistogram.h"
//

// CHistogramDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CHistogramDlg, CDialogEx)

CHistogramDlg::CHistogramDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CHistogramDlg::IDD, pParent)
//, m_nHistogram(0)
, m_nMin(0)
, m_nMax(255)
{
	memset(m_nHistogram, 0, sizeof(int)* 256); //m_nHistogram[256] = {0}; //int 4바이트씩 0으로 초가화해주는거 sizof 만큼
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

// CHistogramDlg 메시지 처리기입니다.

void CHistogramDlg::SetImage(IppDib pDib) //비트맵 pDib
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
			m_nHistogram[i] = static_cast<int>(histo[i] * 100. / max_histo); //m_nHistogram[i]에 y축 그래프의 최댓값을 max_histo 최댓값으로 만듬
	}
	else
	{
		memset(m_nHistogram, 0, sizeof(int)* 256);
	}
}

void CHistogramDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	CGdiObject* pOIdpen = dc.SelectStockObject(DC_PEN); 	//팬선택 SelectStockObject


	dc.SetDCPenColor(RGB(128, 128, 128));	dc.MoveTo(20, 20); 	//SetDCPenColor 팬 색깔

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
