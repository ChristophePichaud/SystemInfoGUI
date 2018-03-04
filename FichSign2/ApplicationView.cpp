// ApplicationView.cpp : implementation file
//

#include "stdafx.h"
#include "FichSign2.h"
#include "ApplicationView.h"
#include "FichSign2Doc.h"
#include "DisplayHandler.h"


// CApplicationView

IMPLEMENT_DYNCREATE(CApplicationView, CEditView)

CApplicationView::CApplicationView()
{

}

CApplicationView::~CApplicationView()
{
}

BEGIN_MESSAGE_MAP(CApplicationView, CEditView)
END_MESSAGE_MAP()


// CApplicationView diagnostics

#ifdef _DEBUG
void CApplicationView::AssertValid() const
{
	CEditView::AssertValid();
}

#ifndef _WIN32_WCE
void CApplicationView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif
#endif //_DEBUG

CFichSign2Doc* CApplicationView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFichSign2Doc)));
	return (CFichSign2Doc*)m_pDocument;
}

// CApplicationView message handlers


void CApplicationView::OnInitialUpdate()
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
	displayHandler.Display_Applications();
	displayHandler.ShowText();
}
