#pragma once
#include <map>
#include "SynonymMap.h"


// представление формы someForm

class someForm : public CFormView
{
	DECLARE_DYNCREATE(someForm)

private:
	CStringArray words;
	SynonymMap map;
protected:
	someForm();           // защищенный конструктор, используемый при динамическом создании
	virtual ~someForm();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_someForm };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();

};


