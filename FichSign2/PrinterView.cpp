// PrinterView.cpp : implementation file
//

#include "stdafx.h"
#include "FichSign2.h"
#include "PrinterView.h"
#include "FichSign2Doc.h"
#include "DisplayHandler.h"


// CPrinterView

IMPLEMENT_DYNCREATE(CPrinterView, CEditView)

CPrinterView::CPrinterView()
{

}

CPrinterView::~CPrinterView()
{
}

BEGIN_MESSAGE_MAP(CPrinterView, CEditView)
END_MESSAGE_MAP()


// CPrinterView diagnostics

#ifdef _DEBUG
void CPrinterView::AssertValid() const
{
	CEditView::AssertValid();
}

#ifndef _WIN32_WCE
void CPrinterView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif
#endif //_DEBUG

CFichSign2Doc* CPrinterView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFichSign2Doc)));
	return (CFichSign2Doc*)m_pDocument;
}

// CPrinterView message handlers


void CPrinterView::OnInitialUpdate()
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
	displayHandler.Display_Printer();
	displayHandler.ShowText();
}
