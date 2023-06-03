// someForm.cpp: файл реализации
//

#include "pch.h"
#include "MFCApplication2.h"
#include "someForm.h"
#include <utility>



// someForm

IMPLEMENT_DYNCREATE(someForm, CFormView)

someForm::someForm()
	: CFormView(IDD_someForm)
{

}

someForm::~someForm()
{
}

void someForm::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(someForm, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &someForm::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &someForm::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &someForm::OnBnClickedButton3)
END_MESSAGE_MAP()


// Диагностика someForm

#ifdef _DEBUG
void someForm::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void someForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// Обработчики сообщений someForm


void someForm::OnBnClickedButton1()
{
	LPCTSTR filter =
		_T("TXT (*.txt)| *.txt|");
	CFileDialog dlgFile(TRUE, _T("txt"), NULL, OFN_OVERWRITEPROMPT, filter, AfxGetMainWnd());
	try {
		if (IDOK == dlgFile.DoModal()) {
			CStdioFile file(dlgFile.GetPathName(), CFile::modeRead | CFile::typeText);
			bool succ{ false };
			CString buff;
			while (file.ReadString(buff)) {
				int nTokenPos = 0;
				CString strToken = buff.Tokenize(_T(" "), nTokenPos);

				
				
				while (!strToken.IsEmpty())
				{
					if (!strToken.IsEmpty() && strToken != "\n") {
						words.Add(strToken);
						TRACE(_T("%s \n"), strToken);

					}
					strToken = buff.Tokenize(_T(" "), nTokenPos);

					
				}
				succ = true;
			}
			if (!succ) {
				AfxMessageBox(_T("empty file"));
			}
			else {
				for (int i = 0; i < words.GetSize(); i++) {
					//TRACE(_T("%d", words.GetThisClass));
					TRACE(_T("%s \n"), words[i]);
				}
			}

		}
	}
	catch (CFileException* e) {
		TRACE(_T("File could not be opened, cause = %d\n"),
			e->m_cause);
		e->Delete();
	}

}

//synonyms
void someForm::OnBnClickedButton2()
{
	LPCTSTR filter =
		_T("TXT (*.txt)| *.txt|");
	CFileDialog dlgFile(TRUE, _T("txt"), NULL, OFN_OVERWRITEPROMPT, filter, AfxGetMainWnd());
	TRACE(_T("suka 1 %d \n", 1));
	try {
		if (IDOK == dlgFile.DoModal()) {
			CStdioFile file(dlgFile.GetPathName(), CFile::modeRead | CFile::typeText);
			bool succ{ false };
			CString buff;
			CStringArray buffArr;
			while (file.ReadString(buff)) {
				buffArr.Add(buff);
				succ = true;
				TRACE(_T("%s \n"),buff);
			}
			if (!succ) {
				AfxMessageBox(_T("empty file"));
			}
			else {
				for (int i = 0; i < buffArr.GetSize(); i++) {
					//TRACE(_T("%d", words.GetThisClass));
					
					int nTokenPos = 0;
					CString strToken = buffArr[i].Tokenize(_T(" "), nTokenPos);

					map.addMainWord(strToken);
					
					while (!strToken.IsEmpty())
					{
						
						strToken = buffArr[i].Tokenize(_T(" "), nTokenPos);
						
						if (!strToken.IsEmpty() && strToken != "\n") {
							
							TRACE(_T("%s \n"), strToken);
							map.addSynonym(strToken);
						}
					}
				}
			}

			

		}
			
	}
	catch (CFileException* e) {
		TRACE(_T("File could not be opened, cause = %d\n"),
			e->m_cause);
		e->Delete();
	}
}

//save
void someForm::OnBnClickedButton3()
{
	if (words.GetSize() == 0 || map.isEmpty()) {
		AfxMessageBox(_T("choose files before saving"));
		return;
	}
	LPCTSTR filter =
		_T("TXT (*.txt)| *.txt|");
	CFileDialog dlgFile(FALSE, _T("txt"), _T("Untitled.txt"), OFN_OVERWRITEPROMPT, filter, AfxGetMainWnd());

	try {
		if (IDOK == dlgFile.DoModal()) {
			CStdioFile file(dlgFile.GetPathName(), CFile::modeCreate | CFile::modeWrite | CFile::typeText);
			bool succ{ false };
			CString buff;
			
				succ = true;

				for (int i = 0; i < words.GetSize(); i++) {
					file.WriteString(map.getRndSynonym(words[i]));
					file.WriteString(_T(" "));
					
				}
				
				

			
			
		}

	}
	catch (CFileException* e) {
		TRACE(_T("File could not be opened, cause = %d\n"),
			e->m_cause);
		e->Delete();
	}
}
