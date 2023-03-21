
// ImageToolDoc.h : CImageToolDoc Ŭ������ �������̽�
//


#pragma once
#include ".\IppImage\IppDib.h"


class CImageToolDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CImageToolDoc();
	DECLARE_DYNCREATE(CImageToolDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CImageToolDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	// ��Ʈ�� ��ü
	IppDib m_Dib;

	// ���� �ҷ����� & �����ϱ�
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	
	afx_msg void OnWindowDuplicate();
	afx_msg void OnEditCopy();
	afx_msg void OnSecChk();
	afx_msg void OnInverseImage();
	afx_msg void OnUpdateInverseImage(CCmdUI *pCmdUI);
	afx_msg void OnAddConst();
	afx_msg void OnSubConst();
	afx_msg void OnUpdateSubConst(CCmdUI *pCmdUI);
	afx_msg void OnMultiConst();
	afx_msg void OnUpdateMultiConst(CCmdUI *pCmdUI);
	afx_msg void OnDivConst();
	afx_msg void OnUpdateDivConst(CCmdUI *pCmdUI);
	afx_msg void OnPreConst();
	afx_msg void OnUpdatePreConst(CCmdUI *pCmdUI);
	afx_msg void OnGamConst();
	afx_msg void OnUpdateGamConst(CCmdUI *pCmdUI);
	afx_msg void OnViewHistogram();
	afx_msg void OnUpdateViewHistogram(CCmdUI *pCmdUI);
	afx_msg void OnStrIng();
	afx_msg void OnEndIn();
	afx_msg void OnEq();
	afx_msg void OnAddavg();
	afx_msg void OnSubdif();
	afx_msg void OnLogic();
	afx_msg void OnPlane();
	afx_msg void OnMove();
	afx_msg void OnSizeup();
	afx_msg void OnSizedown();
	afx_msg void On32828();
	afx_msg void On32829();
	afx_msg void On32830();
	afx_msg void OnNoise();
	afx_msg void OnRotation();
	afx_msg void OnMirr();
	afx_msg void On32837();
};
