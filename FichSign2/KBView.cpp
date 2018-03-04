// KBView.cpp : implementation file
//

#include "stdafx.h"
#include "FichSign2.h"
#include "KBView.h"
#include "FichSign2Doc.h"
#include "DisplayHandler.h"


// CKBView

IMPLEMENT_DYNCREATE(CKBView, CEditView)

CKBView::CKBView()
{

}

CKBView::~CKBView()
{
}

BEGIN_MESSAGE_MAP(CKBView, CEditView)
END_MESSAGE_MAP()


// CKBView diagnostics

#ifdef _DEBUG
void CKBView::AssertValid() const
{
	CEditView::AssertValid();
}

#ifndef _WIN32_WCE
void CKBView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif
#endif //_DEBUG

CFichSign2Doc* CKBView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFichSign2Doc)));
	return (CFichSign2Doc*)m_pDocument;
}

// CKBView message handlers


void CKBView::OnInitialUpdate()
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
	displayHandler.Display_QFE();
	displayHandler.ShowText();
}
