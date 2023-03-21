
// ImageToolDoc.cpp : CImageToolDoc 클래스의 구현
// 정우 2주차

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImageTool.h"

//내가 쓴거
//1주차
#include "IppImage\IppImage.h"
#include "IppImage\IppConvert.h"
#include "InverseImage.h"
//2주차
#include "AddConstDlg.h"
#include "AddConst.h"

#include "SubConstDlg.h"
#include "SubConst.h"

#include "MultiConstDlg.h"
#include "MultiConst.h"

#include "DivConstDlg.h"
#include "DivConst.h"

//3주차
#include "PrepareDlg.h"
#include "Prepare.h"

#include "GammaDlg.h"
#include "Gamma.h"

//4주차
#include "GetHistogram.h"
#include "HistogramDlg.h"

//5주차
#include "Stretching.h"

#include "Endin.h"
#include "EedinDlg.h"

#include "Equalization.h"

//6주차

#include "AddAvgImage.h"
#include "AddAvgImageDlg.h"

#include "SubDifImage.h"
#include "SubDifImageDlg.h"

//7주차
#include "Logic.h"
#include "LogicDlg.h"

#include "IppBitPlane.h"

//8주차
#include "IppGeometry.h"
#include "IppGeometryDlg.h"

#include "IppResizeNearest.h"
#include "IppResizeNearestDlg.h"
#include "IppResizeBilinear.h"

//9주차
#include "GImage.h"
#include "GImageDlg.h"

#include "RightLeft.h"
#include "Updown.h"
#include "RLUD.h"

//10주차 
#include "Filter.h"
#include "FilterDlg.h"
#include "Rotation.h"
#include "RotationDlg.h"

//11주차
#include "Mirroring.h"
#include "MirroringDlg.h"

//13주차
#include "IppFilter.h"


#endif

#include "ImageToolDoc.h"
#include "FileNewDlg.h"
#include "ImageToolSecChk.h"
#include "ImageToolSecChkDlg.h"

#include <propkey.h>

//내가 쓴거 1주차
#define CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)\
	IppByteImage img; \
	IppDibToImage(m_Dib, img);

#define CONVERT_BYTEIMAGE_TO_DIB(img, dib)\
	IppDib dib; \
	IppImageToDib(img, dib);
//


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CImageToolDoc

IMPLEMENT_DYNCREATE(CImageToolDoc, CDocument)

BEGIN_MESSAGE_MAP(CImageToolDoc, CDocument)
	ON_COMMAND(ID_WINDOW_DUPLICATE, &CImageToolDoc::OnWindowDuplicate)
	ON_COMMAND(ID_EDIT_COPY, &CImageToolDoc::OnEditCopy)
	ON_COMMAND(ID_SEC_CHK, &CImageToolDoc::OnSecChk)
	ON_COMMAND(ID_INVERSE_IMAGE, &CImageToolDoc::OnInverseImage)
	ON_UPDATE_COMMAND_UI(ID_INVERSE_IMAGE, &CImageToolDoc::OnUpdateInverseImage)
	ON_COMMAND(ID_ADD_CONST, &CImageToolDoc::OnAddConst)
	ON_COMMAND(ID_SUB_CONST, &CImageToolDoc::OnSubConst)
	ON_UPDATE_COMMAND_UI(ID_SUB_CONST, &CImageToolDoc::OnUpdateSubConst)
	ON_COMMAND(ID_MULTI_CONST, &CImageToolDoc::OnMultiConst)
	ON_UPDATE_COMMAND_UI(ID_MULTI_CONST, &CImageToolDoc::OnUpdateMultiConst)
	ON_COMMAND(ID_DIV_CONST, &CImageToolDoc::OnDivConst)
	ON_UPDATE_COMMAND_UI(ID_DIV_CONST, &CImageToolDoc::OnUpdateDivConst)
	ON_COMMAND(ID_PRE_CONST, &CImageToolDoc::OnPreConst)
	ON_UPDATE_COMMAND_UI(ID_PRE_CONST, &CImageToolDoc::OnUpdatePreConst)
	ON_COMMAND(ID_GAM_CONST, &CImageToolDoc::OnGamConst)
	ON_UPDATE_COMMAND_UI(ID_GAM_CONST, &CImageToolDoc::OnUpdateGamConst)
	ON_COMMAND(ID_VIEW_HISTOGRAM, &CImageToolDoc::OnViewHistogram)
	ON_UPDATE_COMMAND_UI(ID_VIEW_HISTOGRAM, &CImageToolDoc::OnUpdateViewHistogram)
	ON_COMMAND(ID_STR_ING, &CImageToolDoc::OnStrIng)
	ON_COMMAND(IDD_END_IN, &CImageToolDoc::OnEndIn)
	ON_COMMAND(ID_EQ, &CImageToolDoc::OnEq)
	ON_COMMAND(ID_ADDAVG, &CImageToolDoc::OnAddavg)
	ON_COMMAND(ID_SUBDIF, &CImageToolDoc::OnSubdif)
	ON_COMMAND(ID_LOGIC, &CImageToolDoc::OnLogic)
	ON_COMMAND(ID_PLANE, &CImageToolDoc::OnPlane)
	ON_COMMAND(ID_MOVE, &CImageToolDoc::OnMove)
	ON_COMMAND(ID_SIZEUP, &CImageToolDoc::OnSizeup)
	ON_COMMAND(ID_SIZEDown, &CImageToolDoc::OnSizedown)
	ON_COMMAND(ID_32828, &CImageToolDoc::On32828)
	ON_COMMAND(ID_32829, &CImageToolDoc::On32829)
	ON_COMMAND(ID_32830, &CImageToolDoc::On32830)
	ON_COMMAND(ID_NOISE, &CImageToolDoc::OnNoise)
	ON_COMMAND(ID_ROTATION, &CImageToolDoc::OnRotation)
	ON_COMMAND(ID_MIRR, &CImageToolDoc::OnMirr)
	ON_COMMAND(ID_32837, &CImageToolDoc::On32837)
END_MESSAGE_MAP()


// CImageToolDoc 생성/소멸

CImageToolDoc::CImageToolDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CImageToolDoc::~CImageToolDoc()
{
}

BOOL CImageToolDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	BOOL ret = TRUE;

	if (theApp.m_pNewDib == NULL)
	{
		CFileNewDlg dlg;
		if (dlg.DoModal() == IDOK)
		{
			if (dlg.m_nType == 0) // 그레이스케일 비트맵
				ret = m_Dib.CreateGrayBitmap(dlg.m_nWidth, dlg.m_nHeight);
			else // 트루컬러 비트맵
				ret = m_Dib.CreateRgbBitmap(dlg.m_nWidth, dlg.m_nHeight);
		}
		else
		{
			ret = FALSE;
		}
	}
	else
	{
		m_Dib = *(theApp.m_pNewDib);
		theApp.m_pNewDib = NULL;
	}

	return ret;
}




// CImageToolDoc serialization

void CImageToolDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CImageToolDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CImageToolDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CImageToolDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CImageToolDoc 진단

#ifdef _DEBUG
void CImageToolDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImageToolDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CImageToolDoc 명령


BOOL CImageToolDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	BOOL res = m_Dib.Load(CT2A(lpszPathName));
	if (res)
		AfxPrintInfo(_T("[파일 열기] 파일 경로: %s, 가로 크기: %d픽셀, 세로 크기: %d픽셀, 색상수: %d"),
		lpszPathName, m_Dib.GetWidth(), m_Dib.GetHeight(), 0x01 << m_Dib.GetBitCount());

	return res;
}


BOOL CImageToolDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	return m_Dib.Save(CT2A(lpszPathName));
}


void CImageToolDoc::OnWindowDuplicate()
{
	AfxNewBitmap(m_Dib);
}


void CImageToolDoc::OnEditCopy()
{
	if (m_Dib.IsValid())
		m_Dib.CopyToClipboard();
}


void CImageToolDoc::OnSecChk()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageToolSecChkDlg dlg;
	int result;
	if (dlg.DoModal() == IDOK)
	{
		result = ImageToolSecChk(dlg.m_nSecChk);
	}

	if (result == 0)
		AfxMessageBox(_T("실패(x): 보안코드 불일치"), MB_ICONERROR);
	else
		AfxMessageBox(_T("성공(o): 보안코드 일치"), MB_ICONINFORMATION);
}


void CImageToolDoc::OnInverseImage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
		InverseImage(img);
	CONVERT_BYTEIMAGE_TO_DIB(img, dib)

		AfxPrintInfo(_T("[반전] 입력 영상 : %s"), GetTitle());
	AfxNewBitmap(dib);
}


void CImageToolDoc::OnUpdateInverseImage(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8); // 8 일 때만 동작
}


void CImageToolDoc::OnAddConst()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CAddConstDlg dlg;

	if (dlg.DoModal() == IDOK) //확인버튼 눌러지면 IF문 사용
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
		AddConst(img, dlg.m_nAddConst); // dig.m_nAddConst = addc

		CONVERT_BYTEIMAGE_TO_DIB(img, dib);

		AfxPrintInfo(_T("[밝기 증가] 입력 영상:%s, 밝기값:%d"), GetTitle(), dlg.m_nAddConst);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnSubConst()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CSubConstDlg dlg;

	if (dlg.DoModal() == IDOK) //확인버튼 눌러지면 IF문 사용
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
		SubConst(img, dlg.m_nSubConst); // dig.m_nSubConst = addc

		CONVERT_BYTEIMAGE_TO_DIB(img, dib);

		AfxPrintInfo(_T("[밝기 감소] 입력 영상:%s, 밝기값:%d"), GetTitle(), dlg.m_nSubConst);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnUpdateSubConst(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8); // 8 일 때만 동작
}


void CImageToolDoc::OnMultiConst()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMultiConstDlg dlg;

	if (dlg.DoModal() == IDOK) //확인버튼 눌러지면 IF문 사용
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
		MultiConst(img, dlg.m_dMultiConst); // dig.m_nSubConst = addc

		CONVERT_BYTEIMAGE_TO_DIB(img, dib);

		AfxPrintInfo(_T("[밝기 증가] 입력 영상:%s, 밝기값:%lf"), GetTitle(), dlg.m_dMultiConst);


		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnUpdateMultiConst(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8); // 8 일 때만 동작

}


void CImageToolDoc::OnDivConst()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDivConstDlg dlg;

	if (dlg.DoModal() == IDOK) //확인버튼 눌러지면 IF문 사용
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
		DivConst(img, dlg.m_dDivConst); // dig.m_nSubConst = addc

		CONVERT_BYTEIMAGE_TO_DIB(img, dib);

		AfxPrintInfo(_T("[밝기 감소] 입력 영상:%s, 밝기값:%lf"), GetTitle(), dlg.m_dDivConst);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnUpdateDivConst(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8); // 8 일 때만 동작
}


void CImageToolDoc::OnPreConst()  //기울기 절편
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	PrepareDlg dlg;

	if (dlg.DoModal() == IDOK) //확인버튼 눌러지면 IF문 사용
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
		Prepare(img, dlg.e_x1, dlg.e_y1);

		CONVERT_BYTEIMAGE_TO_DIB(img, dib);

		AfxPrintInfo(_T("입력 영상:%s, 기울기:%lf, 절편:%lf"), GetTitle(), dlg.e_x1, dlg.e_y1);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnUpdatePreConst(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8); // 8 일 때만 동작

}


void CImageToolDoc::OnGamConst()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CGammaDlg dlg;

	if (dlg.DoModal() == IDOK) //확인버튼 눌러지면 IF문 사용
	{

		if (dlg.e_r1 == 0)
		{
			AfxMessageBox(_T("안되욥."));
		}
		else
		{
			CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
			Gamma(img, dlg.e_r1);

			CONVERT_BYTEIMAGE_TO_DIB(img, dib);

			AfxPrintInfo(_T("입력 영상:%s, 감마:%lf"), GetTitle(), dlg.e_r1);
			AfxNewBitmap(dib);
		}
	}
}


void CImageToolDoc::OnUpdateGamConst(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8); // 8 일 때만 동작

}


void CImageToolDoc::OnViewHistogram()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CHistogramDlg dlg;

	dlg.SetImage(m_Dib);
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
	dlg.m_nMin = GetMinGrayValue(img);
	dlg.m_nMax = GetMaxGrayValue(img);

	AfxPrintInfo(_T("[히스토그램] 입력 영상:%s, 최솟값:%d, 최댓값:%d"), GetTitle(), dlg.m_nMin, dlg.m_nMax);
	dlg.DoModal();
}


void CImageToolDoc::OnUpdateViewHistogram(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8); // 8 일 때만 동작
}


void CImageToolDoc::OnStrIng()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
		STRGrayValue(img);
	CONVERT_BYTEIMAGE_TO_DIB(img, dib)

		AfxPrintInfo(_T("[반전] 입력 영상 : %s"), GetTitle());
	AfxNewBitmap(dib);
}


void CImageToolDoc::OnEndIn()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CEedinDlg dlg;


	if (dlg.DoModal() == IDOK) //확인버튼 눌러지면 IF문 사용
	{

		if (dlg.n_min == dlg.m_max)
		{
			AfxMessageBox(_T("안됩니다...."));
		}
		else if (dlg.n_min > dlg.m_max)
		{
			AfxMessageBox(_T("안됩니다...."));
		}
		else
		{
			CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
			ENDIN(img, dlg.n_min, dlg.m_max);
			CONVERT_BYTEIMAGE_TO_DIB(img, dib);

			AfxNewBitmap(dib);
		}

	}
}


void CImageToolDoc::OnEq()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
		EQ(img);
	CONVERT_BYTEIMAGE_TO_DIB(img, dib)

		AfxNewBitmap(dib);
}


void CImageToolDoc::OnAddavg()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CAddAvgImageDlg dlg;

	if (dlg.DoModal() == IDOK) //확인버튼 눌러지면 IF문 사용
	{
		CImageToolDoc* pDoc1 = (CImageToolDoc*)dlg.m_pDoc1;
		CImageToolDoc* pDoc2 = (CImageToolDoc*)dlg.m_pDoc2;


		CONVERT_DIB_TO_BYTEIMAGE(pDoc1->m_Dib, img1);
		CONVERT_DIB_TO_BYTEIMAGE(pDoc2->m_Dib, img2);
		IppByteImage img3; // img1 과 img2 를 img 3에

		bool ret = false; //ret 초기값 정의

		switch (dlg.m_nFunction)
		{
		case 0: ret = AddImage(img1, img2, img3); break;
		case 1: ret = AvgImage(img1, img2, img3); break;
		}

		if (ret)
		{
			CONVERT_BYTEIMAGE_TO_DIB(img3, dib);

			TCHAR*op[] = { _T("덧셈"), _T("평균") };
			AfxPrintInfo(_T("[산술연산(영상):%s] 입력영상#1:%s,입력영상#2:%s"),
				op[dlg.m_nFunction], pDoc1->GetTitle(), pDoc2->GetTitle());
			AfxNewBitmap(dib);
		}
		else
			AfxMessageBox(_T("ERROR: 영상의 크기가 다릅니다."), MB_ICONERROR);
	}



}


void CImageToolDoc::OnSubdif()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	SubDifImageDlg dlg;

	if (dlg.DoModal() == IDOK) //확인버튼 눌러지면 IF문 사용
	{
		CImageToolDoc* pDoc1 = (CImageToolDoc*)dlg.m_pDoc1;
		CImageToolDoc* pDoc2 = (CImageToolDoc*)dlg.m_pDoc2;


		CONVERT_DIB_TO_BYTEIMAGE(pDoc1->m_Dib, img1);
		CONVERT_DIB_TO_BYTEIMAGE(pDoc2->m_Dib, img2);
		IppByteImage img3; // img1 과 img2 를 img 3에

		bool ret = false; //ret 초기값 정의

		switch (dlg.m_nFunction)
		{
		case 0: ret = SubImage(img1, img2, img3); break;
		case 1: ret = DifImage(img1, img2, img3); break;
		}

		if (ret)
		{
			CONVERT_BYTEIMAGE_TO_DIB(img3, dib);

			TCHAR*op[] = { _T("뺄샘"), _T("차이") };
			AfxPrintInfo(_T("[산술연산(영상):%s] 입력영상#1:%s,입력영상#2:%s"),
				op[dlg.m_nFunction], pDoc1->GetTitle(), pDoc2->GetTitle());
			AfxNewBitmap(dib);
		}
		else
			AfxMessageBox(_T("ERROR: 영상의 크기가 다릅니다."), MB_ICONERROR);
	}
}




void CImageToolDoc::OnLogic()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CLogicDlg dlg;

	if (dlg.DoModal() == IDOK) //확인버튼 눌러지면 IF문 사용
	{
		CImageToolDoc* pDoc1 = (CImageToolDoc*)dlg.m_pDoc1;
		CImageToolDoc* pDoc2 = (CImageToolDoc*)dlg.m_pDoc2;


		CONVERT_DIB_TO_BYTEIMAGE(pDoc1->m_Dib, img1);
		CONVERT_DIB_TO_BYTEIMAGE(pDoc2->m_Dib, img2);
		IppByteImage img3; // img1 과 img2 를 img 3에

		bool ret = false; //ret 초기값 정의

		switch (dlg.m_nFunction)
		{
		case 0: ret = ANDImage(img1, img2, img3); break;
		case 1: ret = ORImage(img1, img2, img3); break;
		case 2: ret = XORImage(img1, img2, img3); break;

		}

		if (ret)
		{
			CONVERT_BYTEIMAGE_TO_DIB(img3, dib);

			TCHAR*op[] = { _T("And"), _T("Or"), _T("Xor") };
			AfxPrintInfo(_T("[논리연산(영상):] 입력영상#1:%s,입력영상#2:%s"),
				op[dlg.m_nFunction], pDoc1->GetTitle(), pDoc2->GetTitle());
			AfxNewBitmap(dib);
		}
		else
			AfxMessageBox(_T("ERROR: 영상의 크기가 다릅니다."), MB_ICONERROR);
	}
}


void CImageToolDoc::OnPlane()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
		IppByteImage imgPlane;

	for (int i = 0; i < 8; i++)
	{
		IppBitPlane(img, imgPlane, i);
		CONVERT_BYTEIMAGE_TO_DIB(imgPlane, dib)
			AfxNewBitmap(dib);
	}

	AfxPrintInfo(_T("[비트 평면 분할] 입력 영상: %s"), GetTitle());
}


void CImageToolDoc::OnMove()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIppGeometryDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
			IppByteImage imgDst;

		bool ret = false; //ret 초기값 정의

		ret = IppTranslate(imgSrc, imgDst, dlg.m_neditx1, dlg.m_nedit2y);

		if (ret)
		{
			CONVERT_BYTEIMAGE_TO_DIB(imgDst, dib)

				AfxPrintInfo(_T("[이동 변환] 입력 영상: %s, 가로 이동: %d, 세로 이동: %d"),
				GetTitle(), dlg.m_neditx1, dlg.m_nedit2y);
			AfxNewBitmap(dib);
		}
		else
		{
			AfxMessageBox(_T("ERROR: 영상의 크기보다 큰 값이 입력되었습니다."), MB_ICONERROR);
		}
	}
}

void CImageToolDoc::OnSizeup()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CIppResizeNearestDlg dlg;


	if (dlg.DoModal() == IDOK) //확인버튼 눌러지면 IF문 사용
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
			IppByteImage imgDst;

		switch (dlg.m_nFunction)
		{
			case 0: IppResizeNearest(imgSrc, imgDst, dlg.m_nsizeup * m_Dib.GetWidth(), dlg.m_nsizeup * m_Dib.GetHeight()); break;
			case 1: IppResizeBilinear(imgSrc, imgDst, dlg.m_nsizeup * m_Dib.GetWidth(), dlg.m_nsizeup * m_Dib.GetHeight()); break;
		}
		CONVERT_BYTEIMAGE_TO_DIB(imgDst, dib)

			AfxPrintInfo(_T("[이동 변환] 입력 영상: %s, 확율 비 : %d"),
			GetTitle(), dlg.m_nsizeup);
			AfxNewBitmap(dib);
	}
}



void CImageToolDoc::OnSizedown()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CGImageDlg dlg;

	if (dlg.DoModal() == IDOK){

		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)

			IppByteImage imgDst;

			switch (dlg.m_nFunction)
			{
			case 0: SamplingImage(imgSrc, imgDst, (m_Dib.GetWidth() / (dlg.m_nsizedown)), (m_Dib.GetHeight() / (dlg.m_nsizedown))); break;
			case 1: SamplingImage2(imgSrc, imgDst, dlg.m_nsizedown); break;
			case 2: SamplingImage3(imgSrc, imgDst, dlg.m_nsizedown); break;
			}

			CONVERT_BYTEIMAGE_TO_DIB(imgDst, dib);

			TCHAR* op[] = { _T("단순샘플링"), _T("평균값 샘플링"), _T("중간값 샘플링") };
			AfxPrintInfo(_T("[축소변환:%s] 입력영상#1: %s,배율:%d"), op[dlg.m_nFunction], GetTitle(), dlg.m_nsizedown);
			AfxNewBitmap(dib);
	}
}

void CImageToolDoc::On32828()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
		IppByteImage imgDst;
	IppMirror(imgSrc, imgDst);
	CONVERT_BYTEIMAGE_TO_DIB(imgDst, dib)

		AfxPrintInfo(_T("[좌우 대칭] 입력 영상: %s"), GetTitle());
		AfxNewBitmap(dib);
}


void CImageToolDoc::On32829()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
		IppByteImage imgDst;
	IppFlip(imgSrc, imgDst);
	CONVERT_BYTEIMAGE_TO_DIB(imgDst, dib)

		AfxPrintInfo(_T("[상하 대칭] 입력 영상: %s"), GetTitle());
	AfxNewBitmap(dib);
}


void CImageToolDoc::On32830()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
		IppByteImage imgDst;
	MirrorFlip(imgSrc, imgDst);
	CONVERT_BYTEIMAGE_TO_DIB(imgDst, dib)

		AfxPrintInfo(_T("[상하좌우 대칭] 입력 영상: %s"), GetTitle());
	AfxNewBitmap(dib);
}


void CImageToolDoc::OnNoise()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CFilterDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
			IppByteImage imgDst;

		if (dlg.m_nFunction == 0)
			GenerateGaussianNoise(imgSrc, imgDst, dlg.m_nAmount);
		else
			GenerateSaltNPepperNoise(imgSrc, imgDst, dlg.m_nAmount);

		CONVERT_BYTEIMAGE_TO_DIB(imgDst, dib)

			TCHAR* noise[] = { _T("가우시안"), _T("소금&후추") };
		AfxPrintInfo(_T("[잡음 추가] 입력 영상: %s, 잡음 종류: %s, 잡음 양: %d"),
			GetTitle(), noise[dlg.m_nFunction], dlg.m_nAmount);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnRotation()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CRotationDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
			IppByteImage imgDst;

		IppRotate(imgSrc, imgDst, (double)dlg.m_nDgree);

		CONVERT_BYTEIMAGE_TO_DIB(imgDst, dib)

			TCHAR* rotate[] = { _T("각도") };
		AfxPrintInfo(_T("[회전 변환] 입력 영상: %s, 회전 각도: %d"), GetTitle(), dlg.m_nDgree);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnMirr()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CMirroringDlg dlg;


	if (dlg.DoModal() == IDOK) //확인버튼 눌러지면 IF문 사용
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
			IppByteImage imgDst;

		Mirroring(imgSrc, imgDst, dlg.n_Msize);

		CONVERT_BYTEIMAGE_TO_DIB(imgDst, dib)

		AfxNewBitmap(dib);
	}
}




void CImageToolDoc::On32837()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
			IppByteImage imgDst;
		IppFilterUnsharpMask(imgSrc, imgDst);
		CONVERT_BYTEIMAGE_TO_DIB(imgDst, dib)

			AfxPrintInfo(_T("[언샤프 마스크 필터] 입력 영상: %s"), GetTitle());
		AfxNewBitmap(dib);

	
}
