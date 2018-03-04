// EnvironmentView.cpp : implementation file
//

#include "stdafx.h"
#include "FichSign2.h"
#include "EnvironmentView.h"
#include "FichSign2Doc.h"
#include "DisplayHandler.h"


// CEnvironmentView

IMPLEMENT_DYNCREATE(CEnvironmentView, CEditView)

CEnvironmentView::CEnvironmentView()
{

}

CEnvironmentView::~CEnvironmentView()
{
}

BEGIN_MESSAGE_MAP(CEnvironmentView, CEditView)
END_MESSAGE_MAP()


// CEnvironmentView diagnostics

#ifdef _DEBUG
void CEnvironmentView::AssertValid() const
{
	CEditView::AssertValid();
}

#ifndef _WIN32_WCE
void CEnvironmentView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif
#endif //_DEBUG

CFichSign2Doc* CEnvironmentView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFichSign2Doc)));
	return (CFichSign2Doc*)m_pDocument;
}

// CEnvironmentView message handlers


void CEnvironmentView::OnInitialUpdate()
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
	displayHandler.Display_EnvironementVariables();
	displayHandler.ShowText();
}
