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

// FichSign2View.cpp : implementation of the CFichSign2View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "FichSign2.h"
#endif

#include "FichSign2Doc.h"
#include "FichSign2View.h"
#include "DataHandler.h"
#include "WorkerItemHandler.h"
#include "DisplayHandler.h"
#include "FontHelper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFichSign2View

IMPLEMENT_DYNCREATE(CFichSign2View, CEditView)

BEGIN_MESSAGE_MAP(CFichSign2View, CEditView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFichSign2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CFichSign2View construction/destruction

CFichSign2View::CFichSign2View()
{
	// TODO: add construction code here

}

CFichSign2View::~CFichSign2View()
{
}

BOOL CFichSign2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}


// CFichSign2View printing


void CFichSign2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CFichSign2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CFichSign2View::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CFichSign2View::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}

void CFichSign2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CFichSign2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CFichSign2View diagnostics

#ifdef _DEBUG
void CFichSign2View::AssertValid() const
{
	CEditView::AssertValid();
}

void CFichSign2View::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CFichSign2Doc* CFichSign2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFichSign2Doc)));
	return (CFichSign2Doc*)m_pDocument;
}
#endif //_DEBUG


// CFichSign2View message handlers

void CFichSign2View::OnInitialUpdate()
{
	CEditView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	m_fh.CreateFont();
	SetFont(& m_fh.m_font, TRUE);

	CoInitializeEx(0, COINIT_MULTITHREADED);

	CString str;
	str.Format(_TEXT("Bienvenue sur la fiche signalitique du poste."));
	//AddLine(str);

	GetInformations();
	DisplayInformations();
}

UINT DoWorkSimple(LPVOID pParam)
{
	CoInitializeEx(0, COINIT_MULTITHREADED);

	CFichSign2View *pView = (CFichSign2View *)pParam;
	CFichSign2Doc * pDocument = pView->GetDocument();

	WorkerItemHandler wih;
	wih.GetComputerName();
	wih.GetEnvironmentStrings();
	wih.GetSystemInformation();

	//wih.GetWMIInformations();
	wih.GetWMIInformation2();
	wih.GetBiosInformation();
	wih.GetPrinterInformation();
	wih.GetPrinterInformation2();
	wih.GetVideoInformation();
	wih.GetDiskDriveInformation();
	wih.GetModelInformation();
	wih.GetNetworkAdapterInformation();
	wih.GetAltirisPackagesInformation();
	wih.GetApplicationsInformation();
	//
	// Business Operations
	//
	wih.GetWorkstationInformation();
	wih.GetInternetExplorerInformation();

	//
	// results
	//
	pDocument->m_data.CopySimple(wih.m_data);
	return true;
}

UINT DoWorkQFE(LPVOID pParam)
{
	CoInitializeEx(0, COINIT_MULTITHREADED);

	CFichSign2View *pView = (CFichSign2View *)pParam;
	CFichSign2Doc * pDocument = pView->GetDocument();

	WorkerItemHandler wih;
	wih.GetQFEInformation();

	//
	// results
	//
	pDocument->m_data.CopyQFE(wih.m_data);

	return true;
}

bool CFichSign2View::GetInformations()
{
	HANDLE hThreads[2];

	DWORD dwStart = ::GetTickCount();

	CWinThread *pThreadSimple = AfxBeginThread(&DoWorkSimple, this);
	pThreadSimple->ResumeThread();
	hThreads[0] = pThreadSimple->m_hThread;

	CWinThread *pThreadQFE = AfxBeginThread(&DoWorkQFE, this);
	pThreadQFE->ResumeThread();
	hThreads[1] = pThreadQFE->m_hThread;

	bool bThreadSimpleHasFinished = false;
	bool bThreadQFEHasFinished = false;
	while (TRUE)
	{
		DWORD dwExitCodeSimple = 0;
		::GetExitCodeThread(pThreadSimple->m_hThread, &dwExitCodeSimple);
		if (dwExitCodeSimple == STILL_ACTIVE) {}
		else
			bThreadSimpleHasFinished = true;

		DWORD dwExitCodeQFE = 0;
		::GetExitCodeThread(pThreadQFE->m_hThread, &dwExitCodeQFE);
		if (dwExitCodeQFE == STILL_ACTIVE) {}
		else
			bThreadQFEHasFinished = true;

		if (bThreadSimpleHasFinished == true && bThreadQFEHasFinished == true)
			break;

		Sleep(100);

	}

	//
	// Close the Splash Window
	//
	theApp.m_bFinished = true;

	DWORD dwEnd = ::GetTickCount();
	m_dwTime = dwEnd - dwStart;
	GetDocument()->m_data.m_dwTimeForCollectingAllData = m_dwTime;
	return true;
}

bool CFichSign2View::DisplayInformations()
{
	DataHandler data;
	data.CopySimple(GetDocument()->m_data);
	data.CopyQFE(GetDocument()->m_data);
	GetDocument()->m_dataAvailable = true;
	
	CString str;
	CDisplayHandler displayHandler(data, this);
	displayHandler.Display_Banner();
	displayHandler.Display_Workstation();
	displayHandler.Display_Configuration();
	displayHandler.Display_WorkstationBis();
	displayHandler.Display_EnvironementVariables();
	displayHandler.Display_Bios();
	displayHandler.Display_Printer();
	displayHandler.Display_USB();
	displayHandler.Display_Video();
	displayHandler.Display_Disk();
	displayHandler.Display_NetworkCard();
	displayHandler.Display_AltirisPackages();
	displayHandler.Display_Applications();
	displayHandler.Display_QFE();
	displayHandler.ShowText();
	return true;
}


