// ConfigurationView.cpp : implementation file
//

#include "stdafx.h"
#include "FichSign2.h"
#include "ConfigurationView.h"
#include "FichSign2Doc.h"
#include "DisplayHandler.h"


// CConfigurationView

IMPLEMENT_DYNCREATE(CConfigurationView, CEditView)

CConfigurationView::CConfigurationView()
{

}

CConfigurationView::~CConfigurationView()
{
}

BEGIN_MESSAGE_MAP(CConfigurationView, CEditView)
END_MESSAGE_MAP()


// CConfigurationView diagnostics

#ifdef _DEBUG
void CConfigurationView::AssertValid() const
{
	CEditView::AssertValid();
}

#ifndef _WIN32_WCE
void CConfigurationView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif
#endif //_DEBUG

CFichSign2Doc* CConfigurationView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFichSign2Doc)));
	return (CFichSign2Doc*)m_pDocument;
}

// CConfigurationView message handlers


void CConfigurationView::OnInitialUpdate()
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
	displayHandler.Display_Configuration();
	displayHandler.ShowText();
}
