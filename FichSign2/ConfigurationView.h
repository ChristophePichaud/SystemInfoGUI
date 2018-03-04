#pragma once
#include "FichSign2Doc.h"
#include "FontHelper.h"

// CConfigurationView view

class CConfigurationView : public CEditView
{
	DECLARE_DYNCREATE(CConfigurationView)

protected:
	CConfigurationView();           // protected constructor used by dynamic creation
	virtual ~CConfigurationView();

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


