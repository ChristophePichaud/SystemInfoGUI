#include "stdafx.h"
#include "FichSign2.h"

#include "FichSign2Doc.h"
#include "TabbedView.h"

#include "FichSign2View.h"
#include "WorkstationView.h"
#include "ConfigurationView.h"
#include "NetworkView.h"
#include "PrinterView.h"
#include "WorkstationView2.h"
#include "AntiVirusView.h"
#include "EnvironmentView.h"
#include "PackageView.h"
#include "ApplicationView.h"
#include "WindowsUpdateView.h"
#include "KBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabbedView

IMPLEMENT_DYNCREATE(CTabbedView, CTabView)

BEGIN_MESSAGE_MAP(CTabbedView, CTabView)
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CTabView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CTabView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTabbedView construction/destruction

CTabbedView::CTabbedView()
{
}

CTabbedView::~CTabbedView()
{
}

BOOL CTabbedView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CTabView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTabbedView drawing

void CTabbedView::OnDraw(CDC* /*pDC*/)
{
	//	CTabbedViewDoc* pDoc = GetDocument();
	//	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTabbedView printing

void CTabbedView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CTabbedView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTabbedView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTabbedView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTabbedView diagnostics

#ifdef _DEBUG
void CTabbedView::AssertValid() const
{
	CTabView::AssertValid();
}

void CTabbedView::Dump(CDumpContext& dc) const
{
	CTabView::Dump(dc);
}

CFichSign2Doc* CTabbedView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFichSign2Doc)));
	return (CFichSign2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTabbedView message handlers

int CTabbedView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CTabView::OnCreate(lpCreateStruct) == -1)
		return -1;

	AddView(RUNTIME_CLASS(CFichSign2View), _T("Accueil"), 100);
	AddView(RUNTIME_CLASS(CWorkstationView), _T("Poste de travail"), 101);
	AddView(RUNTIME_CLASS(CConfigurationView), _T("Configuration"), 102);
	AddView(RUNTIME_CLASS(CNetworkView), _T("Carte Réseau"), 103);
	AddView(RUNTIME_CLASS(CPrinterView), _T("Imprimante"), 104);
	AddView(RUNTIME_CLASS(CWorkstationView2), _T("Poste"), 105);
	AddView(RUNTIME_CLASS(CAntiVirusView), _T("AntiVirus"), 106);
	AddView(RUNTIME_CLASS(CEnvironmentView), _T("Var. Environnement"), 107);
	AddView(RUNTIME_CLASS(CPackageView), _T("Packages"), 108);
	AddView(RUNTIME_CLASS(CApplicationView), _T("Applications"), 109);
	AddView(RUNTIME_CLASS(CWindowsUpdateView), _T("Windows Update"), 110);
	AddView(RUNTIME_CLASS(CKBView), _T("KB"), 110);

	return 0;
}

BOOL CTabbedView::OnEraseBkgnd(CDC* /*pDC*/)
{
	return TRUE;
}
