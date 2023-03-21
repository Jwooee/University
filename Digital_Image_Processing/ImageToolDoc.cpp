
// ImageToolDoc.cpp : CImageToolDoc Ŭ������ ����
// ���� 2����

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "ImageTool.h"

//���� ����
//1����
#include "IppImage\IppImage.h"
#include "IppImage\IppConvert.h"
#include "InverseImage.h"
//2����
#include "AddConstDlg.h"
#include "AddConst.h"

#include "SubConstDlg.h"
#include "SubConst.h"

#include "MultiConstDlg.h"
#include "MultiConst.h"

#include "DivConstDlg.h"
#include "DivConst.h"

//3����
#include "PrepareDlg.h"
#include "Prepare.h"

#include "GammaDlg.h"
#include "Gamma.h"

//4����
#include "GetHistogram.h"
#include "HistogramDlg.h"

//5����
#include "Stretching.h"

#include "Endin.h"
#include "EedinDlg.h"

#include "Equalization.h"

//6����

#include "AddAvgImage.h"
#include "AddAvgImageDlg.h"

#include "SubDifImage.h"
#include "SubDifImageDlg.h"

//7����
#include "Logic.h"
#include "LogicDlg.h"

#include "IppBitPlane.h"

//8����
#include "IppGeometry.h"
#include "IppGeometryDlg.h"

#include "IppResizeNearest.h"
#include "IppResizeNearestDlg.h"
#include "IppResizeBilinear.h"

//9����
#include "GImage.h"
#include "GImageDlg.h"

#include "RightLeft.h"
#include "Updown.h"
#include "RLUD.h"

//10���� 
#include "Filter.h"
#include "FilterDlg.h"
#include "Rotation.h"
#include "RotationDlg.h"

//11����
#include "Mirroring.h"
#include "MirroringDlg.h"

//13����
#include "IppFilter.h"


#endif

#include "ImageToolDoc.h"
#include "FileNewDlg.h"
#include "ImageToolSecChk.h"
#include "ImageToolSecChkDlg.h"

#include <propkey.h>

//���� ���� 1����
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


// CImageToolDoc ����/�Ҹ�

CImageToolDoc::CImageToolDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

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
			if (dlg.m_nType == 0) // �׷��̽����� ��Ʈ��
				ret = m_Dib.CreateGrayBitmap(dlg.m_nWidth, dlg.m_nHeight);
			else // Ʈ���÷� ��Ʈ��
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
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CImageToolDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
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

// �˻� ó���⸦ �����մϴ�.
void CImageToolDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
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

// CImageToolDoc ����

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


// CImageToolDoc ���


BOOL CImageToolDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	BOOL res = m_Dib.Load(CT2A(lpszPathName));
	if (res)
		AfxPrintInfo(_T("[���� ����] ���� ���: %s, ���� ũ��: %d�ȼ�, ���� ũ��: %d�ȼ�, �����: %d"),
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
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CImageToolSecChkDlg dlg;
	int result;
	if (dlg.DoModal() == IDOK)
	{
		result = ImageToolSecChk(dlg.m_nSecChk);
	}

	if (result == 0)
		AfxMessageBox(_T("����(x): �����ڵ� ����ġ"), MB_ICONERROR);
	else
		AfxMessageBox(_T("����(o): �����ڵ� ��ġ"), MB_ICONINFORMATION);
}


void CImageToolDoc::OnInverseImage()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
		InverseImage(img);
	CONVERT_BYTEIMAGE_TO_DIB(img, dib)

		AfxPrintInfo(_T("[����] �Է� ���� : %s"), GetTitle());
	AfxNewBitmap(dib);
}


void CImageToolDoc::OnUpdateInverseImage(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8); // 8 �� ���� ����
}


void CImageToolDoc::OnAddConst()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	CAddConstDlg dlg;

	if (dlg.DoModal() == IDOK) //Ȯ�ι�ư �������� IF�� ���
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
		AddConst(img, dlg.m_nAddConst); // dig.m_nAddConst = addc

		CONVERT_BYTEIMAGE_TO_DIB(img, dib);

		AfxPrintInfo(_T("[��� ����] �Է� ����:%s, ��Ⱚ:%d"), GetTitle(), dlg.m_nAddConst);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnSubConst()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CSubConstDlg dlg;

	if (dlg.DoModal() == IDOK) //Ȯ�ι�ư �������� IF�� ���
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
		SubConst(img, dlg.m_nSubConst); // dig.m_nSubConst = addc

		CONVERT_BYTEIMAGE_TO_DIB(img, dib);

		AfxPrintInfo(_T("[��� ����] �Է� ����:%s, ��Ⱚ:%d"), GetTitle(), dlg.m_nSubConst);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnUpdateSubConst(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8); // 8 �� ���� ����
}


void CImageToolDoc::OnMultiConst()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CMultiConstDlg dlg;

	if (dlg.DoModal() == IDOK) //Ȯ�ι�ư �������� IF�� ���
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
		MultiConst(img, dlg.m_dMultiConst); // dig.m_nSubConst = addc

		CONVERT_BYTEIMAGE_TO_DIB(img, dib);

		AfxPrintInfo(_T("[��� ����] �Է� ����:%s, ��Ⱚ:%lf"), GetTitle(), dlg.m_dMultiConst);


		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnUpdateMultiConst(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8); // 8 �� ���� ����

}


void CImageToolDoc::OnDivConst()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CDivConstDlg dlg;

	if (dlg.DoModal() == IDOK) //Ȯ�ι�ư �������� IF�� ���
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
		DivConst(img, dlg.m_dDivConst); // dig.m_nSubConst = addc

		CONVERT_BYTEIMAGE_TO_DIB(img, dib);

		AfxPrintInfo(_T("[��� ����] �Է� ����:%s, ��Ⱚ:%lf"), GetTitle(), dlg.m_dDivConst);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnUpdateDivConst(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8); // 8 �� ���� ����
}


void CImageToolDoc::OnPreConst()  //���� ����
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	PrepareDlg dlg;

	if (dlg.DoModal() == IDOK) //Ȯ�ι�ư �������� IF�� ���
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
		Prepare(img, dlg.e_x1, dlg.e_y1);

		CONVERT_BYTEIMAGE_TO_DIB(img, dib);

		AfxPrintInfo(_T("�Է� ����:%s, ����:%lf, ����:%lf"), GetTitle(), dlg.e_x1, dlg.e_y1);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnUpdatePreConst(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8); // 8 �� ���� ����

}


void CImageToolDoc::OnGamConst()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CGammaDlg dlg;

	if (dlg.DoModal() == IDOK) //Ȯ�ι�ư �������� IF�� ���
	{

		if (dlg.e_r1 == 0)
		{
			AfxMessageBox(_T("�ȵǿ�."));
		}
		else
		{
			CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
			Gamma(img, dlg.e_r1);

			CONVERT_BYTEIMAGE_TO_DIB(img, dib);

			AfxPrintInfo(_T("�Է� ����:%s, ����:%lf"), GetTitle(), dlg.e_r1);
			AfxNewBitmap(dib);
		}
	}
}


void CImageToolDoc::OnUpdateGamConst(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8); // 8 �� ���� ����

}


void CImageToolDoc::OnViewHistogram()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CHistogramDlg dlg;

	dlg.SetImage(m_Dib);
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img);
	dlg.m_nMin = GetMinGrayValue(img);
	dlg.m_nMax = GetMaxGrayValue(img);

	AfxPrintInfo(_T("[������׷�] �Է� ����:%s, �ּڰ�:%d, �ִ�:%d"), GetTitle(), dlg.m_nMin, dlg.m_nMax);
	dlg.DoModal();
}


void CImageToolDoc::OnUpdateViewHistogram(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->Enable(m_Dib.GetBitCount() == 8); // 8 �� ���� ����
}


void CImageToolDoc::OnStrIng()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
		STRGrayValue(img);
	CONVERT_BYTEIMAGE_TO_DIB(img, dib)

		AfxPrintInfo(_T("[����] �Է� ���� : %s"), GetTitle());
	AfxNewBitmap(dib);
}


void CImageToolDoc::OnEndIn()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CEedinDlg dlg;


	if (dlg.DoModal() == IDOK) //Ȯ�ι�ư �������� IF�� ���
	{

		if (dlg.n_min == dlg.m_max)
		{
			AfxMessageBox(_T("�ȵ˴ϴ�...."));
		}
		else if (dlg.n_min > dlg.m_max)
		{
			AfxMessageBox(_T("�ȵ˴ϴ�...."));
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
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
		EQ(img);
	CONVERT_BYTEIMAGE_TO_DIB(img, dib)

		AfxNewBitmap(dib);
}


void CImageToolDoc::OnAddavg()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	CAddAvgImageDlg dlg;

	if (dlg.DoModal() == IDOK) //Ȯ�ι�ư �������� IF�� ���
	{
		CImageToolDoc* pDoc1 = (CImageToolDoc*)dlg.m_pDoc1;
		CImageToolDoc* pDoc2 = (CImageToolDoc*)dlg.m_pDoc2;


		CONVERT_DIB_TO_BYTEIMAGE(pDoc1->m_Dib, img1);
		CONVERT_DIB_TO_BYTEIMAGE(pDoc2->m_Dib, img2);
		IppByteImage img3; // img1 �� img2 �� img 3��

		bool ret = false; //ret �ʱⰪ ����

		switch (dlg.m_nFunction)
		{
		case 0: ret = AddImage(img1, img2, img3); break;
		case 1: ret = AvgImage(img1, img2, img3); break;
		}

		if (ret)
		{
			CONVERT_BYTEIMAGE_TO_DIB(img3, dib);

			TCHAR*op[] = { _T("����"), _T("���") };
			AfxPrintInfo(_T("[�������(����):%s] �Է¿���#1:%s,�Է¿���#2:%s"),
				op[dlg.m_nFunction], pDoc1->GetTitle(), pDoc2->GetTitle());
			AfxNewBitmap(dib);
		}
		else
			AfxMessageBox(_T("ERROR: ������ ũ�Ⱑ �ٸ��ϴ�."), MB_ICONERROR);
	}



}


void CImageToolDoc::OnSubdif()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	SubDifImageDlg dlg;

	if (dlg.DoModal() == IDOK) //Ȯ�ι�ư �������� IF�� ���
	{
		CImageToolDoc* pDoc1 = (CImageToolDoc*)dlg.m_pDoc1;
		CImageToolDoc* pDoc2 = (CImageToolDoc*)dlg.m_pDoc2;


		CONVERT_DIB_TO_BYTEIMAGE(pDoc1->m_Dib, img1);
		CONVERT_DIB_TO_BYTEIMAGE(pDoc2->m_Dib, img2);
		IppByteImage img3; // img1 �� img2 �� img 3��

		bool ret = false; //ret �ʱⰪ ����

		switch (dlg.m_nFunction)
		{
		case 0: ret = SubImage(img1, img2, img3); break;
		case 1: ret = DifImage(img1, img2, img3); break;
		}

		if (ret)
		{
			CONVERT_BYTEIMAGE_TO_DIB(img3, dib);

			TCHAR*op[] = { _T("����"), _T("����") };
			AfxPrintInfo(_T("[�������(����):%s] �Է¿���#1:%s,�Է¿���#2:%s"),
				op[dlg.m_nFunction], pDoc1->GetTitle(), pDoc2->GetTitle());
			AfxNewBitmap(dib);
		}
		else
			AfxMessageBox(_T("ERROR: ������ ũ�Ⱑ �ٸ��ϴ�."), MB_ICONERROR);
	}
}




void CImageToolDoc::OnLogic()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	CLogicDlg dlg;

	if (dlg.DoModal() == IDOK) //Ȯ�ι�ư �������� IF�� ���
	{
		CImageToolDoc* pDoc1 = (CImageToolDoc*)dlg.m_pDoc1;
		CImageToolDoc* pDoc2 = (CImageToolDoc*)dlg.m_pDoc2;


		CONVERT_DIB_TO_BYTEIMAGE(pDoc1->m_Dib, img1);
		CONVERT_DIB_TO_BYTEIMAGE(pDoc2->m_Dib, img2);
		IppByteImage img3; // img1 �� img2 �� img 3��

		bool ret = false; //ret �ʱⰪ ����

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
			AfxPrintInfo(_T("[������(����):] �Է¿���#1:%s,�Է¿���#2:%s"),
				op[dlg.m_nFunction], pDoc1->GetTitle(), pDoc2->GetTitle());
			AfxNewBitmap(dib);
		}
		else
			AfxMessageBox(_T("ERROR: ������ ũ�Ⱑ �ٸ��ϴ�."), MB_ICONERROR);
	}
}


void CImageToolDoc::OnPlane()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, img)
		IppByteImage imgPlane;

	for (int i = 0; i < 8; i++)
	{
		IppBitPlane(img, imgPlane, i);
		CONVERT_BYTEIMAGE_TO_DIB(imgPlane, dib)
			AfxNewBitmap(dib);
	}

	AfxPrintInfo(_T("[��Ʈ ��� ����] �Է� ����: %s"), GetTitle());
}


void CImageToolDoc::OnMove()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CIppGeometryDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
			IppByteImage imgDst;

		bool ret = false; //ret �ʱⰪ ����

		ret = IppTranslate(imgSrc, imgDst, dlg.m_neditx1, dlg.m_nedit2y);

		if (ret)
		{
			CONVERT_BYTEIMAGE_TO_DIB(imgDst, dib)

				AfxPrintInfo(_T("[�̵� ��ȯ] �Է� ����: %s, ���� �̵�: %d, ���� �̵�: %d"),
				GetTitle(), dlg.m_neditx1, dlg.m_nedit2y);
			AfxNewBitmap(dib);
		}
		else
		{
			AfxMessageBox(_T("ERROR: ������ ũ�⺸�� ū ���� �ԷµǾ����ϴ�."), MB_ICONERROR);
		}
	}
}

void CImageToolDoc::OnSizeup()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CIppResizeNearestDlg dlg;


	if (dlg.DoModal() == IDOK) //Ȯ�ι�ư �������� IF�� ���
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
			IppByteImage imgDst;

		switch (dlg.m_nFunction)
		{
			case 0: IppResizeNearest(imgSrc, imgDst, dlg.m_nsizeup * m_Dib.GetWidth(), dlg.m_nsizeup * m_Dib.GetHeight()); break;
			case 1: IppResizeBilinear(imgSrc, imgDst, dlg.m_nsizeup * m_Dib.GetWidth(), dlg.m_nsizeup * m_Dib.GetHeight()); break;
		}
		CONVERT_BYTEIMAGE_TO_DIB(imgDst, dib)

			AfxPrintInfo(_T("[�̵� ��ȯ] �Է� ����: %s, Ȯ�� �� : %d"),
			GetTitle(), dlg.m_nsizeup);
			AfxNewBitmap(dib);
	}
}



void CImageToolDoc::OnSizedown()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

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

			TCHAR* op[] = { _T("�ܼ����ø�"), _T("��հ� ���ø�"), _T("�߰��� ���ø�") };
			AfxPrintInfo(_T("[��Һ�ȯ:%s] �Է¿���#1: %s,����:%d"), op[dlg.m_nFunction], GetTitle(), dlg.m_nsizedown);
			AfxNewBitmap(dib);
	}
}

void CImageToolDoc::On32828()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
		IppByteImage imgDst;
	IppMirror(imgSrc, imgDst);
	CONVERT_BYTEIMAGE_TO_DIB(imgDst, dib)

		AfxPrintInfo(_T("[�¿� ��Ī] �Է� ����: %s"), GetTitle());
		AfxNewBitmap(dib);
}


void CImageToolDoc::On32829()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
		IppByteImage imgDst;
	IppFlip(imgSrc, imgDst);
	CONVERT_BYTEIMAGE_TO_DIB(imgDst, dib)

		AfxPrintInfo(_T("[���� ��Ī] �Է� ����: %s"), GetTitle());
	AfxNewBitmap(dib);
}


void CImageToolDoc::On32830()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
		IppByteImage imgDst;
	MirrorFlip(imgSrc, imgDst);
	CONVERT_BYTEIMAGE_TO_DIB(imgDst, dib)

		AfxPrintInfo(_T("[�����¿� ��Ī] �Է� ����: %s"), GetTitle());
	AfxNewBitmap(dib);
}


void CImageToolDoc::OnNoise()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
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

			TCHAR* noise[] = { _T("����þ�"), _T("�ұ�&����") };
		AfxPrintInfo(_T("[���� �߰�] �Է� ����: %s, ���� ����: %s, ���� ��: %d"),
			GetTitle(), noise[dlg.m_nFunction], dlg.m_nAmount);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnRotation()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	CRotationDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
			IppByteImage imgDst;

		IppRotate(imgSrc, imgDst, (double)dlg.m_nDgree);

		CONVERT_BYTEIMAGE_TO_DIB(imgDst, dib)

			TCHAR* rotate[] = { _T("����") };
		AfxPrintInfo(_T("[ȸ�� ��ȯ] �Է� ����: %s, ȸ�� ����: %d"), GetTitle(), dlg.m_nDgree);
		AfxNewBitmap(dib);
	}
}


void CImageToolDoc::OnMirr()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	CMirroringDlg dlg;


	if (dlg.DoModal() == IDOK) //Ȯ�ι�ư �������� IF�� ���
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
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

		CONVERT_DIB_TO_BYTEIMAGE(m_Dib, imgSrc)
			IppByteImage imgDst;
		IppFilterUnsharpMask(imgSrc, imgDst);
		CONVERT_BYTEIMAGE_TO_DIB(imgDst, dib)

			AfxPrintInfo(_T("[����� ����ũ ����] �Է� ����: %s"), GetTitle());
		AfxNewBitmap(dib);

	
}
