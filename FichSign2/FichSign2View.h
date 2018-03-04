// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// FichSign2View.h : interface of the CFichSign2View class
//

#pragma once
#include "FontHelper.h"

class CFichSign2View : public CEditView
{
protected: // create from serialization only
	CFichSign2View();
	DECLARE_DYNCREATE(CFichSign2View)

// Attributes
public:
	CFichSign2Doc* GetDocument() const;
	CFontHelper m_fh;
	DWORD m_dwTime;

// Operations
public:
	bool GetInformations();
	bool DisplayInformations();

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CFichSign2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // debug version in FichSign2View.cpp
inline CFichSign2Doc* CFichSign2View::GetDocument() const
   { return reinterpret_cast<CFichSign2Doc*>(m_pDocument); }
#endif

