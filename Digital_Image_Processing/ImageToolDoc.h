
// ImageToolDoc.h : CImageToolDoc 클래스의 인터페이스
//


#pragma once
#include ".\IppImage\IppDib.h"


class CImageToolDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CImageToolDoc();
	DECLARE_DYNCREATE(CImageToolDoc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CImageToolDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	// 비트맵 객체
	IppDib m_Dib;

	// 파일 불러오기 & 저장하기
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
