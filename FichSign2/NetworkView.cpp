// NetworkView.cpp : implementation file
//

#include "stdafx.h"
#include "FichSign2.h"
#include "NetworkView.h"
#include "FichSign2Doc.h"
#include "DisplayHandler.h"

// CNetworkView

IMPLEMENT_DYNCREATE(CNetworkView, CEditView)

CNetworkView::CNetworkView()
{

}

CNetworkView::~CNetworkView()
{
}

BEGIN_MESSAGE_MAP(CNetworkView, CEditView)
END_MESSAGE_MAP()


// CNetworkView diagnostics

#ifdef _DEBUG
void CNetworkView::AssertValid() const
{
	CEditView::AssertValid();
}

#ifndef _WIN32_WCE
void CNetworkView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif
#endif //_DEBUG

CFichSign2Doc* CNetworkView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFichSign2Doc)));
	return (CFichSign2Doc*)m_pDocument;
}

// CNetworkView message handlers


void CNetworkView::OnInitialUpdate()
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
	displayHandler.Display_NetworkCard();
	displayHandler.ShowText();
}
