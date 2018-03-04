// AntiVirusView.cpp : implementation file
//

#include "stdafx.h"
#include "FichSign2.h"
#include "AntiVirusView.h"
#include "FichSign2Doc.h"
#include "DisplayHandler.h"


// CAntiVirusView

IMPLEMENT_DYNCREATE(CAntiVirusView, CEditView)

CAntiVirusView::CAntiVirusView()
{

}

CAntiVirusView::~CAntiVirusView()
{
}

BEGIN_MESSAGE_MAP(CAntiVirusView, CEditView)
END_MESSAGE_MAP()


// CAntiVirusView diagnostics

#ifdef _DEBUG
void CAntiVirusView::AssertValid() const
{
	CEditView::AssertValid();
}

#ifndef _WIN32_WCE
void CAntiVirusView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif
#endif //_DEBUG

CFichSign2Doc* CAntiVirusView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFichSign2Doc)));
	return (CFichSign2Doc*)m_pDocument;
}

// CAntiVirusView message handlers


void CAntiVirusView::OnInitialUpdate()
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
	//displayHandler.Display_Workstation();
	displayHandler.ShowText();
}
