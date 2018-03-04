// WorkstationView2.cpp : implementation file
//

#include "stdafx.h"
#include "FichSign2.h"
#include "WorkstationView2.h"
#include "FichSign2Doc.h"
#include "DisplayHandler.h"


// CWorkstationView2

IMPLEMENT_DYNCREATE(CWorkstationView2, CEditView)

CWorkstationView2::CWorkstationView2()
{

}

CWorkstationView2::~CWorkstationView2()
{
}

BEGIN_MESSAGE_MAP(CWorkstationView2, CEditView)
END_MESSAGE_MAP()


// CWorkstationView2 diagnostics

#ifdef _DEBUG
void CWorkstationView2::AssertValid() const
{
	CEditView::AssertValid();
}

#ifndef _WIN32_WCE
void CWorkstationView2::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif
#endif //_DEBUG

CFichSign2Doc* CWorkstationView2::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFichSign2Doc)));
	return (CFichSign2Doc*)m_pDocument;
}

// CWorkstationView2 message handlers


void CWorkstationView2::OnInitialUpdate()
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
	displayHandler.Display_WorkstationBis();
	displayHandler.Display_Bios();
	displayHandler.Display_Disk();
	displayHandler.Display_Video();
	displayHandler.ShowText();
}
