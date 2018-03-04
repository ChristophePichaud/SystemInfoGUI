#pragma once
#include "FichSign2Doc.h"
#include "FontHelper.h"

// CEnvironmentView view

class CEnvironmentView : public CEditView
{
	DECLARE_DYNCREATE(CEnvironmentView)

protected:
	CEnvironmentView();           // protected constructor used by dynamic creation
	virtual ~CEnvironmentView();

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


