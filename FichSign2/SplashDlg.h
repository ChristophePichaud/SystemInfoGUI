#pragma once


// CSplashDlg dialog

class CSplashDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSplashDlg)

public:
	CSplashDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSplashDlg();

public:
	static CSplashDlg* c_pSplashDlg;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SPLASH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	static void ShowSplashScreen(CWnd* pParentWnd);
	void HideSplashScreen();
	static BOOL PreTranslateAppMessage(MSG* pMsg);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();
};
