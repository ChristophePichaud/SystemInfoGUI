#pragma once
#include "FichSign2Doc.h"
#include "FontHelper.h"

// CPrinterView view

class CPrinterView : public CEditView
{
	DECLARE_DYNCREATE(CPrinterView)

protected:
	CPrinterView();           // protected constructor used by dynamic creation
	virtual ~CPrinterView();

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


