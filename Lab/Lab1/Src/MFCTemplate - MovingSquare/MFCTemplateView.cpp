
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

#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

// CMFCTemplateView

IMPLEMENT_DYNCREATE(CMFCTemplateView, CView)

BEGIN_MESSAGE_MAP(CMFCTemplateView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCTemplateView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CMFCTemplateView construction/destruction

CMFCTemplateView::CMFCTemplateView()
	: m_angle(0)
	, m_hTimer(0)
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


int CMFCTemplateView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	//Setup Opengl
	SetupOpenGL();
	//Create Timer
	m_hTimer = SetTimer(1, 100, NULL);
	

	return 0;
}


void CMFCTemplateView::SetupOpenGL(void)
{
	//Declare Pixel Format
	static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		32, // bit depth
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		16, // z-buffer depth
		0, 0, 0, 0, 0, 0, 0,
	};

	// Get device context only once.
	HDC hdc = GetDC()->m_hDC;
	
	// Set Pixel format.
	int nPixelFormat = ChoosePixelFormat(hdc, &pfd);
	SetPixelFormat(hdc, nPixelFormat, &pfd);

	// Create the OpenGL Rendering Context.
	m_hRC = wglCreateContext(hdc);
	wglMakeCurrent(hdc, m_hRC);
}

#define DEG2RAD (3.14159f/180.0f)

void CMFCTemplateView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CView::OnPaint() for painting messages
	
	glClearColor(0.0f, 0.7f, 0.7f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT); 
	glColor3f(1.0f, 0.0f, 0.0f);

	GLfloat cx, cy;
	cx = 0.5*cos(DEG2RAD*m_angle); cy = 0.5*sin(DEG2RAD*m_angle);

	glBegin(GL_POLYGON);        
		glVertex2f(cx - 0.5, cy - 0.5);        
		glVertex2f(cx - 0.5, cy + 0.5);        
		glVertex2f(cx + 0.5, cy + 0.5);        
		glVertex2f(cx + 0.5, cy - 0.5);    
	glEnd();
	glFlush();
	
	SwapBuffers(dc.m_ps.hdc);
}


void CMFCTemplateView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here

	//Setting up viewport
	CRect rect;
	GetClientRect(rect);
	int size = min(rect.Width(), rect.Height());
	glViewport(0, 0, size, size);
}


void CMFCTemplateView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnTimer(nIDEvent);
	
	//RePaint the window
	m_angle	+= 10.0f;
	if(m_angle > 360) m_angle = m_angle - 360.0f;

	InvalidateRect(NULL, false);
}


void CMFCTemplateView::RemoveOpenGL(void)
{
	//Delete Rendering Context
	if(wglGetCurrentContext() != NULL)
		wglMakeCurrent(NULL,NULL);

	if(m_hRC != NULL)
	{
		wglDeleteContext(m_hRC);
		m_hRC = NULL;
	}
}


void CMFCTemplateView::OnDestroy()
{
	CView::OnDestroy();

	RemoveOpenGL();

	//Remove timer
	if(m_hTimer > 0){
		KillTimer(m_hTimer);
		m_hTimer = -1;
	}
}
