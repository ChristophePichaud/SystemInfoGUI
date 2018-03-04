#pragma once
#include "FichSign2Doc.h"
#include "FontHelper.h"

// CAntiVirusView view

class CAntiVirusView : public CEditView
{
	DECLARE_DYNCREATE(CAntiVirusView)

protected:
	CAntiVirusView();           // protected constructor used by dynamic creation
	virtual ~CAntiVirusView();

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


