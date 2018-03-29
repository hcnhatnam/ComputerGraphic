
// MFCTemplateView.cpp : implementation of the CMFCTemplateView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCTemplate.h"
#endif

#include "MFCTemplateDoc.h"
#include "MFCTemplateView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCTemplateView

IMPLEMENT_DYNCREATE(CMFCTemplateView, CView)

BEGIN_MESSAGE_MAP(CMFCTemplateView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCTemplateView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCTemplateView construction/destruction

CMFCTemplateView::CMFCTemplateView()
{
	// TODO: add construction code here

}

CMFCTemplateView::~CMFCTemplateView()
{
}

BOOL CMFCTemplateView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCTemplateView drawing

void CMFCTemplateView::OnDraw(CDC* /*pDC*/)
{
	CMFCTemplateDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCTemplateView printing


void CMFCTemplateView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCTemplateView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCTemplateView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCTemplateView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCTemplateView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCTemplateView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCTemplateView diagnostics

#ifdef _DEBUG
void CMFCTemplateView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCTemplateView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCTemplateDoc* CMFCTemplateView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCTemplateDoc)));
	return (CMFCTemplateDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCTemplateView message handlers
