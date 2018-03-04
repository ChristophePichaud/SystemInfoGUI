#pragma once
#include "DataHandler.h"

class CDisplayHandler
{
public:
	CDisplayHandler(const DataHandler& dh, CEditView *pView);
	~CDisplayHandler();

public:
	void AddLine(CString str);
	void AddLine(CString name, CString value);
	void AddLine(CString name, long value);
	void AddBlankLine();
	void Clear();

public:
	void ShowText();

public:
	void Display_Banner();
	void Display_Workstation();
	void Display_Configuration();
	void Display_EnvironementVariables();
	void Display_WorkstationBis();
	void Display_Bios();
	void Display_Printer();
	void Display_USB();
	void Display_Video();
	void Display_Disk();
	void Display_NetworkCard();
	void Display_QFE();
	void Display_AltirisPackages();
	void Display_Applications();

public:
	CString m_text;
	DataHandler m_data;
	CEditView *m_pEditView;
};

