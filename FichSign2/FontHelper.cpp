#include "stdafx.h"
#include "FontHelper.h"


CFontHelper::CFontHelper()
{
}


CFontHelper::~CFontHelper()
{
}

void CFontHelper::CreateFont()
{
	m_font.DeleteObject();

	m_font.CreateFont(
		16,                        // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_NORMAL,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		_TEXT("Consolas"));        // lpszFacename
}
