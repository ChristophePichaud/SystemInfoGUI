// PackageView.cpp : implementation file
//

#include "stdafx.h"
#include "FichSign2.h"
#include "PackageView.h"
#include "FichSign2Doc.h"
#include "DisplayHandler.h"


// CPackageView

IMPLEMENT_DYNCREATE(CPackageView, CEditView)

CPackageView::CPackageView()
{

}

CPackageView::~CPackageView()
{
}

BEGIN_MESSAGE_MAP(CPackageView, CEditView)
END_MESSAGE_MAP()


// CPackageView diagnostics

#ifdef _DEBUG
void CPackageView::AssertValid() const
{
	CEditView::AssertValid();
}

#ifndef _WIN32_WCE
void CPackageView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif
#endif //_DEBUG

CFichSign2Doc* CPackageView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFichSign2Doc)));
	return (CFichSign2Doc*)m_pDocument;
}

// CPackageView message handlers


void CPackageView::OnInitialUpdate()
{
	CEditView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	m_fh.CreateFont();
	SetFont(&m_fh.m_font, TRUE);

	GetDocument()->WaitForDataTobeAvailable();

	//
	// Data are available
	//
	DataHandler data;
	data.CopySimple(GetDocument()->m_data);
	data.CopyQFE(GetDocument()->m_data);

	CString str;
	CDisplayHandler displayHandler(data, this);
	displayHandler.Display_AltirisPackages();
	displayHandler.ShowText();
}
