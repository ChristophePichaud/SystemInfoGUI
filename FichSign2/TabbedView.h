#pragma once
#include "FichSign2Doc.h"

class CTabbedView : public CTabView
{
protected: // create from serialization only
	CTabbedView();
	DECLARE_DYNCREATE(CTabbedView)

	// Attributes
public:
	CFichSign2Doc* GetDocument();

	// Operations
public:

	// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	BOOL IsScrollBar() const
	{
		return TRUE;
	}

	// Implementation
public:
	virtual ~CTabbedView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnFilePrintPreview();

	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TabbedView.cpp
inline CFichSign2Doc* CTabbedView::GetDocument()
{
	return (CFichSign2Doc*)m_pDocument;
}
#endif
