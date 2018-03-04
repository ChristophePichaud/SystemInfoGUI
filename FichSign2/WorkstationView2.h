#pragma once
#include "FichSign2Doc.h"
#include "FontHelper.h"

// CWorkstationView2 view

class CWorkstationView2 : public CEditView
{
	DECLARE_DYNCREATE(CWorkstationView2)

protected:
	CWorkstationView2();           // protected constructor used by dynamic creation
	virtual ~CWorkstationView2();

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


