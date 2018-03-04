// SplashDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FichSign2.h"
#include "SplashDlg.h"
#include "afxdialogex.h"


// CSplashDlg dialog

IMPLEMENT_DYNAMIC(CSplashDlg, CDialogEx)

CSplashDlg::CSplashDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SPLASH, pParent)
{

}

CSplashDlg::~CSplashDlg()
{
}

void CSplashDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSplashDlg, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CSplashDlg message handlers


void CSplashDlg::ShowSplashScreen(CWnd* pParentWnd)
{
	// Allocate a new splash screen, and create the window.
	c_pSplashDlg = new CSplashDlg;
	if (!c_pSplashDlg->Create(IDD_SPLASH, pParentWnd))
		delete c_pSplashDlg;
	else
		c_pSplashDlg->ShowWindow(SW_SHOW);
	c_pSplashDlg->UpdateWindow();

	c_pSplashDlg->SetTimer(1, 250, NULL);
}

void CSplashDlg::HideSplashScreen()
{
	// Destroy the window, and update the mainframe.
	c_pSplashDlg->KillTimer(1);
	DestroyWindow();

	AfxGetMainWnd()->ShowWindow(SW_SHOW);
	AfxGetMainWnd()->UpdateWindow();

	delete c_pSplashDlg;
	c_pSplashDlg = NULL;
}

BOOL CSplashDlg::PreTranslateAppMessage(MSG* pMsg)
{
	if (c_pSplashDlg == NULL)
		return FALSE;

	// If you receive a keyboard or a mouse message, hide the splash screen.
	if (c_pSplashDlg->m_hWnd != NULL && pMsg->message == WM_KEYDOWN ||
		pMsg->message == WM_SYSKEYDOWN ||
		pMsg->message == WM_LBUTTONDOWN ||
		pMsg->message == WM_RBUTTONDOWN ||
		pMsg->message == WM_MBUTTONDOWN ||
		pMsg->message == WM_NCLBUTTONDOWN ||
		pMsg->message == WM_NCRBUTTONDOWN ||
		pMsg->message == WM_NCMBUTTONDOWN)
	{
		c_pSplashDlg->HideSplashScreen();
		return TRUE;	// message handled here
	}

	return FALSE;	// message not handled
}



void CSplashDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	if (theApp.m_bFinished == true)
	{
		// Destroy the splash screen window.
		HideSplashScreen();
	}

	//CDialogEx::OnTimer(nIDEvent);
}


BOOL CSplashDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	CenterWindow();

	SetWindowPos(&CWnd::wndTopMost, 0, 0, 0, 0,
		SWP_NOMOVE | SWP_NOSIZE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
