#pragma once
#include "FichSign2Doc.h"
#include "FontHelper.h"

// CNetworkView view

class CNetworkView : public CEditView
{
	DECLARE_DYNCREATE(CNetworkView)

protected:
	CNetworkView();           // protected constructor used by dynamic creation
	virtual ~CNetworkView();

public:
	CFichSign2Doc* GetDocument() const;
	CFontHelper m_fh;

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};


