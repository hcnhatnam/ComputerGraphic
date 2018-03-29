
// MFCTemplateView.h : interface of the CMFCTemplateView class
//

#pragma once


class CMFCTemplateView : public CView
{
protected: // create from serialization only
	CMFCTemplateView();
	DECLARE_DYNCREATE(CMFCTemplateView)

// Attributes
public:
	CMFCTemplateDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCTemplateView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCTemplateView.cpp
inline CMFCTemplateDoc* CMFCTemplateView::GetDocument() const
   { return reinterpret_cast<CMFCTemplateDoc*>(m_pDocument); }
#endif

