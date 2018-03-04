// WindowsUpdateView.cpp : implementation file
//

#include "stdafx.h"
#include "FichSign2.h"
#include "WindowsUpdateView.h"
#include "FichSign2Doc.h"
#include "DisplayHandler.h"


// CWindowsUpdateView

IMPLEMENT_DYNCREATE(CWindowsUpdateView, CEditView)

CWindowsUpdateView::CWindowsUpdateView()
{

}

CWindowsUpdateView::~CWindowsUpdateView()
{
}

BEGIN_MESSAGE_MAP(CWindowsUpdateView, CEditView)
END_MESSAGE_MAP()


// CWindowsUpdateView diagnostics

#ifdef _DEBUG
void CWindowsUpdateView::AssertValid() const
{
	CEditView::AssertValid();
}

#ifndef _WIN32_WCE
void CWindowsUpdateView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif
#endif //_DEBUG

CFichSign2Doc* CWindowsUpdateView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFichSign2Doc)));
	return (CFichSign2Doc*)m_pDocument;
}

// CWindowsUpdateView message handlers


void CWindowsUpdateView::OnInitialUpdate()
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
