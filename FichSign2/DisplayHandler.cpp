#include "stdafx.h"
#include "DisplayHandler.h"


CDisplayHandler::CDisplayHandler(const DataHandler& dh, CEditView *pView)
{
	m_data.CopySimple(dh);
	m_data.CopyQFE(dh);
	m_pEditView = pView;
}

CDisplayHandler::~CDisplayHandler()
{
}

void CDisplayHandler::AddLine(CString str)
{
	m_text = m_text + str + _TEXT("\r\n");
}

void CDisplayHandler::AddLine(CString name, CString value)
{
	m_text = m_text + name + _TEXT(": ") + value + _TEXT("\r\n");
}

void CDisplayHandler::AddLine(CString name, long value)
{
	CString str;
	str.Format(_TEXT("%ld"), value);
	m_text = m_text + name + _TEXT(": ") + str + _TEXT("\r\n");
}

void CDisplayHandler::AddBlankLine()
{
	m_text = m_text + _TEXT("\r\n");
}

void CDisplayHandler::Clear()
{
	m_text = _TEXT("");
}

void CDisplayHandler::ShowText()
{
	m_pEditView->GetEditCtrl().SetWindowTextW(m_text);
}

void CDisplayHandler::Display_Banner()
{
	AddLine(_TEXT("-------------------------------"));
	AddLine(_TEXT("- Fiche Signalitique du Poste -"));
	AddLine(_TEXT("-------------------------------"));
	AddLine(_TEXT("Temps de collecte des données (ms)"), m_data.m_dwTimeForCollectingAllData);
	AddLine(_TEXT("ComputerName"), m_data.m_ComputerName);
	AddLine(_TEXT("IP"), m_data.m_IPV4);
	AddBlankLine();
	AddBlankLine();
}

void CDisplayHandler::Display_Workstation()
{
	AddLine(_TEXT("Information Poste de Travail:"));
	AddLine(_TEXT("-----------------------------"));
	AddLine(_TEXT("Adm Machine"), m_data.m_Workstation.m_AdmMachine);
	AddLine(_TEXT("Agence Station"), m_data.m_Workstation.m_AgenceStation);
	AddLine(_TEXT("Idmsr"), m_data.m_Workstation.m_Idmsr);
	AddLine(_TEXT("Version OS"), m_data.m_Workstation.m_VersionOS);
	AddLine(_TEXT("Version OS String"), m_data.m_Workstation.m_VersionOSString);
	AddLine(_TEXT("Type poste"), m_data.m_Workstation.m_TypePoste);
	AddLine(_TEXT("Oridnateur"), m_data.m_Workstation.m_ComputerName);
	AddLine(_TEXT("Utilisateur courant"), m_data.m_Workstation.m_CurrentUser);
	AddLine(_TEXT("Domaine"), m_data.m_Workstation.m_UserDomain);
	AddBlankLine();

	AddLine(_TEXT("Variables d'installation:"));
	AddLine(_TEXT("-------------------------"));
	for (int c = 0; c != m_data.m_Workstation.m_RegistryLCL.GetCount(); c++)
	{
		CString strLCL;
		strLCL.Format(_TEXT("%s : %s"), m_data.m_Workstation.m_RegistryLCL.GetAt(c).m_NameValue, m_data.m_Workstation.m_RegistryLCL.GetAt(c).m_Value);
		AddLine(strLCL);
	}
	AddBlankLine();
	AddBlankLine();

	//AddLine(_TEXT("Variables d'installation:"));
	//AddLine(_TEXT("-------------------------"));
	//AddLine(_TEXT("Abonne"), m_data.m_Workstation.m_Registry.m_Abonne);
	//AddLine(_TEXT("DateAbonne"), m_data.m_Workstation.m_Registry.m_DateAbonne);
	//AddLine(_TEXT("DateInst"), m_data.m_Workstation.m_Registry.m_DateInst);
	//AddLine(_TEXT("DateSocle"), m_data.m_Workstation.m_Registry.m_DateSocle);
	//AddLine(_TEXT("InstPlateforme"), m_data.m_Workstation.m_Registry.m_InstPlateforme);
	//AddLine(_TEXT("LCLAppABOPDT"), m_data.m_Workstation.m_Registry.m_LCLAppABOPDT);
	//AddLine(_TEXT("LCLAppMDTABOPDT"), m_data.m_Workstation.m_Registry.m_LCLAppMDTABOPDT);
	//AddLine(_TEXT("LCLAppMetierPDT"), m_data.m_Workstation.m_Registry.m_LCLAppMetierPDT);
	//AddLine(_TEXT("LCLMediaVersion"), m_data.m_Workstation.m_Registry.m_LCLMediaVersion);
	//AddLine(_TEXT("LCLMIG"), m_data.m_Workstation.m_Registry.m_LCLMIG);
	//AddLine(_TEXT("PDT"), m_data.m_Workstation.m_Registry.m_PDT);
	//AddLine(_TEXT("Type"), m_data.m_Workstation.m_Registry.m_Type);
	//AddLine(_TEXT("TypeMaster"), m_data.m_Workstation.m_Registry.m_TypeMaster);
	//AddLine(_TEXT("TypePoste"), m_data.m_Workstation.m_Registry.m_TypePoste);
	//AddLine(_TEXT("VersionAbonne"), m_data.m_Workstation.m_Registry.m_VersionAbonne);
	//AddLine(_TEXT("VersionProc"), m_data.m_Workstation.m_Registry.m_VersionProc);
	//AddLine(_TEXT("VersionSocle"), m_data.m_Workstation.m_Registry.m_VersionSocle);
	//AddLine(_TEXT("VersionVia"), m_data.m_Workstation.m_Registry.m_VersionVia);
	//AddBlankLine();
}

void CDisplayHandler::Display_Configuration()
{
	CString str;

	//AddLine(_TEXT("Paramétrage du CL.INI"));
	//AddLine(_TEXT("---------------------"));
	//AddLine(_TEXT("Type"), m_data.m_Workstation.m_Type);
	//AddLine(_TEXT("Nom Abonné"), m_data.m_Workstation.m_NomAbonne);
	//AddLine(_TEXT("Nom Abonné R"), m_data.m_Workstation.m_NomAbonneR);
	//AddLine(_TEXT("Version Abonné"), m_data.m_Workstation.m_VersionAbonne);
	//AddLine(_TEXT("Métier"), m_data.m_Workstation.m_Metier);
	//AddLine(_TEXT("Entité"), m_data.m_Workstation.m_Entite);
	//AddLine(_TEXT("NumPDTQualiparc"), m_data.m_Workstation.m_NumPDTQualiparc);
	//AddLine(_TEXT("m_NumUCQualiparc"), m_data.m_Workstation.m_NumUCQualiparc);
	//AddLine(_TEXT("Planet"), m_data.m_Workstation.m_Planet);
	//AddLine(_TEXT("Identifiant Planet"), m_data.m_Workstation.m_Identifiant);

	//AddBlankLine();
	//AddBlankLine();

	AddLine(_TEXT("Internet Explorer"));
	AddLine(_TEXT("-----------------"));
	AddLine(_TEXT("Version"), m_data.m_InternetExplorer.m_Version);
	AddLine(_TEXT("IE11 Update Version"), m_data.m_InternetExplorer.m_UpdateVersion);
	AddLine(_TEXT("IE11 KB Number"), m_data.m_InternetExplorer.m_KBNumber);
	AddLine(_TEXT("Vidage Cache"), m_data.m_InternetExplorer.m_ClearCache);
	AddLine(_TEXT("Proxy Script"), m_data.m_InternetExplorer.m_ProxyPac);
	AddLine(_TEXT("Proxy Server"), m_data.m_InternetExplorer.m_ProxyServerEnabled);
	AddLine(_TEXT("Proxy Server Adresse"), m_data.m_InternetExplorer.m_ProxyServer);
	AddLine(_TEXT("Proxy Exceptions"), m_data.m_InternetExplorer.m_ProxyExceptions);
	AddLine(_TEXT("SiteList HKLM"), m_data.m_InternetExplorer.m_SiteList1);
	AddLine(_TEXT("SiteList HKCU"), m_data.m_InternetExplorer.m_SiteList2);
	AddLine(_TEXT("SiteList Current Version"), m_data.m_InternetExplorer.m_CurrentVersion);

	AddBlankLine();
	AddBlankLine();
}

void CDisplayHandler::Display_WorkstationBis()
{
	CString str;

	AddLine(_TEXT("Informations PC"));
	AddLine(_TEXT("---------------"));
	AddLine(_TEXT("ComputerName"), m_data.m_ComputerName);
	AddLine(_TEXT("ComputerDescription"), m_data.m_ComputerDescription);
	AddBlankLine();
	AddLine(_TEXT("Processors"), m_data.m_NumOfProcessors);
	AddLine(_TEXT("Processor architecture"), m_data.m_ProcessorArchitecture);
	AddLine(_TEXT("OS Version"), m_data.m_Version);
	AddLine(_TEXT("Operating System"), m_data.m_OperatingSystem);
	AddLine(_TEXT("Model"), m_data.m_Model);
	AddLine(_TEXT("Processor"), m_data.m_Processor);

	str.Format(_TEXT("Total memory : %s"), m_data.m_TotalMemory);
	AddLine(str);

	AddBlankLine();
	AddBlankLine();
}

void CDisplayHandler::Display_EnvironementVariables()
{
	CString str;
	AddLine(_TEXT("Environment Variables"));
	AddLine(_TEXT("---------------------"));
	for (int c = 0; c != m_data.m_Env.GetCount(); c++)
	{
		AddLine(_TEXT("Env"), m_data.m_Env.GetAt(c));
	}
	AddBlankLine();
	AddBlankLine();
}

void CDisplayHandler::Display_Bios()
{
	CString str;

	AddLine(_TEXT("Informations BIOS"));
	AddLine(_TEXT("-----------------"));
	AddLine(_TEXT("Bios description"), m_data.m_BiosDescription);
	AddLine(_TEXT("Bios manufacturer"), m_data.m_BiosManufacturer);
	AddLine(_TEXT("Bios serial number"), m_data.m_BiosSerialNumber);
	AddLine(_TEXT("Bios version"), m_data.m_BiosVersion);
	AddBlankLine();
	AddBlankLine();
}

void CDisplayHandler::Display_Printer()
{
	CString str;

	AddLine(_TEXT("Informations Imprimantes"));
	AddLine(_TEXT("------------------------"));
	for (int c = 0; c != m_data.m_Printers.GetCount(); c++)
	{
		AddLine(_TEXT("Printer"), m_data.m_Printers.GetAt(c).m_Name);
		AddLine(_TEXT("Printer"), m_data.m_Printers.GetAt(c).m_DriverName);
	}
	AddBlankLine();
	AddBlankLine();
}

void CDisplayHandler::Display_USB()
{
	CString str;
	AddLine(_TEXT("Informations USB"));
	AddLine(_TEXT("----------------"));
	for (int c = 0; c != m_data.m_Usbs.GetCount(); c++)
	{
		AddLine(_TEXT("USB"), m_data.m_Usbs.GetAt(c).m_DeviceID);
	}
	AddBlankLine();
	AddBlankLine();
}

void CDisplayHandler::Display_Video()
{
	CString str;
	AddLine(_TEXT("Informations Vidéo"));
	AddLine(_TEXT("------------------"));
	for (int c = 0; c != m_data.m_Videos.GetCount(); c++)
	{
		AddLine(_TEXT("Video"), m_data.m_Videos.GetAt(c).m_Description);
		AddLine(_TEXT("Video"), m_data.m_Videos.GetAt(c).m_DriverVersion);
	}
	AddBlankLine();
	AddBlankLine();
}

void CDisplayHandler::Display_Disk()
{
	CString str;
	AddLine(_TEXT("Informations Disk"));
	AddLine(_TEXT("-----------------"));
	for (int c = 0; c != m_data.m_Disks.GetCount(); c++)
	{
		AddLine(_TEXT("Disk"), m_data.m_Disks.GetAt(c).m_Name);
		AddLine(_TEXT("Disk"), m_data.m_Disks.GetAt(c).m_Model);
		AddLine(_TEXT("Disk"), m_data.m_Disks.GetAt(c).m_InterfaceType);
	}
	AddBlankLine();
	for (int c = 0; c != m_data.m_DiskDrive.GetCount(); c++)
	{
		AddLine(_TEXT("Disk"), m_data.m_DiskDrive.GetAt(c).m_Antecedent);
		AddLine(_TEXT("Disk"), m_data.m_DiskDrive.GetAt(c).m_Dependent);
	}
	AddBlankLine();
	for (int c = 0; c != m_data.m_DiskLogical.GetCount(); c++)
	{
		AddLine(_TEXT("Disk"), m_data.m_DiskLogical.GetAt(c).m_Antecedent);
		AddLine(_TEXT("Disk"), m_data.m_DiskLogical.GetAt(c).m_Dependent);
	}
	AddBlankLine();
	AddBlankLine();
}

void CDisplayHandler::Display_NetworkCard()
{
	CString str;
	AddLine(_TEXT("Informations Réseau"));
	AddLine(_TEXT("-------------------"));
	for (int c = 0; c != m_data.m_NetworkCards.GetCount(); c++)
	{
		AddLine(_TEXT("Network Card : Index"), m_data.m_NetworkCards.GetAt(c).m_Index);
		AddLine(_TEXT("Network Card : Name"), m_data.m_NetworkCards.GetAt(c).m_Name);
		AddLine(_TEXT("Network Card : AdapterType"), m_data.m_NetworkCards.GetAt(c).m_AdapterType);
		AddLine(_TEXT("Network Card : MACAddress"), m_data.m_NetworkCards.GetAt(c).m_MACAddress);
		AddLine(_TEXT("Network Card : Speed"), m_data.m_NetworkCards.GetAt(c).m_Speed);
		AddLine(_TEXT("Network Card : NetConnectionStatus"), m_data.m_NetworkCards.GetAt(c).m_NetConnectionStatus);
		AddLine(_TEXT("Network Card : NetEnabled"), m_data.m_NetworkCards.GetAt(c).m_NetEnabled);
		AddLine(_TEXT("Network Card : PhysicalAdapter"), m_data.m_NetworkCards.GetAt(c).m_PhysicalAdapter);
	}
	AddBlankLine();
	AddBlankLine();
}

void CDisplayHandler::Display_QFE()
{
	CString str;
	AddLine(_TEXT("Informations QFE"));
	AddLine(_TEXT("----------------"));
	for (int c = 0; c != m_data.m_Qfes.GetCount(); c++)
	{
		str.Format(_TEXT("%s %s %s %s"),
			m_data.m_Qfes.GetAt(c).m_Caption,
			m_data.m_Qfes.GetAt(c).m_Description,
			m_data.m_Qfes.GetAt(c).m_HotFixID,
			m_data.m_Qfes.GetAt(c).m_InstalledOn);
		AddLine(str);
	}
	AddBlankLine();
	AddBlankLine();
}

void CDisplayHandler::Display_AltirisPackages()
{
	CString str;
	AddLine(_TEXT("Informations Altiris"));
	AddLine(_TEXT("--------------------"));
	for (int c = 0; c != m_data.m_AltirisPackages.GetCount(); c++)
	{
		str.Format(_TEXT("%s %d %s"),
			m_data.m_AltirisPackages.GetAt(c).m_Name,
			m_data.m_AltirisPackages.GetAt(c).m_b64bits,
			m_data.m_AltirisPackages.GetAt(c).m_Date.Format(_TEXT("%d/%m/%Y %H:%M:%S")));
		AddLine(str);
	}
	AddBlankLine();
	AddBlankLine();
}

void CDisplayHandler::Display_Applications()
{
	CString str;
	AddLine(_TEXT("Informations Applications"));
	AddLine(_TEXT("-------------------------"));
	for (int c = 0; c != m_data.m_Applications.GetCount(); c++)
	{
		str.Format(_TEXT("%s %s %s"),
			m_data.m_Applications.GetAt(c).m_Name,
			m_data.m_Applications.GetAt(c).m_Version,
			m_data.m_Applications.GetAt(c).m_InstallDate);
		AddLine(str);
	}
	AddBlankLine();
	AddBlankLine();
}
