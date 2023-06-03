
// MFCApplication2.h: основной файл заголовка для приложения MFCApplication2
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMFCApplication2App:
// Сведения о реализации этого класса: MFCApplication2.cpp
//

class CMFCApplication2App : public CWinAppEx
{
public:
	CMFCApplication2App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication2App theApp;
