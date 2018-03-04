// WorkstationView.cpp : implementation file
//

#include "stdafx.h"
#include "FichSign2.h"
#include "WorkstationView.h"
#include "FichSign2Doc.h"
#include "DisplayHandler.h"

// WorkstationView

IMPLEMENT_DYNCREATE(CWorkstationView, CEditView)

CWorkstationView::CWorkstationView()
{

}

CWorkstationView::~CWorkstationView()
{
}

BEGIN_MESSAGE_MAP(CWorkstationView, CEditView)
END_MESSAGE_MAP()


// WorkstationView diagnostics

#ifdef _DEBUG
void CWorkstationView::AssertValid() const
{
	CEditView::AssertValid();
}

#ifndef _WIN32_WCE
void CWorkstationView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif
#endif //_DEBUG

CFichSign2Doc* CWorkstationView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFichSign2Doc)));
	return (CFichSign2Doc*)m_pDocument;
}


// WorkstationView message handlers


void CWorkstationView::OnInitialUpdate()
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
	displayHandler.Display_Workstation();
	displayHandler.ShowText();
}
