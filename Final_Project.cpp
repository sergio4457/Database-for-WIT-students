// Object Oriented Programming Final Project
// Group: Sergio Pina, Patrick Yepmo, Rafael Barbosa
#include "stdafx.h"
#include "Final_Project.h"
#include "Final_ProjectDlg.h"
#include <string>
#include <vector>
#include <fstream>
using namespace std;
#include"dialog_add_person.h"
#include "witPerson.h"
#include "witFaculty.h"
#include "witStudent.h"
#include "witStaff.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CFinalProjectApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

CFinalProjectApp::CFinalProjectApp()
{	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;   }

CFinalProjectApp theApp;

BOOL CFinalProjectApp::InitInstance()
{
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);
	CWinApp::InitInstance();
	CShellManager *pShellManager = new CShellManager;
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	vector<WITPerson*>Mainpersons;			
	CFinalProjectDlg dlg;                   
	
	ifstream fin("witPersonFile.txt"); 

	string temp_name, temp_add, temp_num, temp_role, temp_rate, temp_hours;
	while (getline(fin, temp_name), getline(fin, temp_add),
		getline(fin, temp_num), getline(fin, temp_role),
		getline(fin, temp_rate), getline(fin, temp_hours)) {

		if (temp_role == "Student") {
			WITStudent *pFile = new WITStudent(temp_name, temp_add, temp_num, temp_rate, temp_hours);
			Mainpersons.push_back(pFile);
		}
		else if (temp_role == "Staff") {
			WITStaff *pFile = new WITStaff(temp_name, temp_add, temp_num, temp_rate, temp_hours);
			Mainpersons.push_back(pFile);
		}
		else if (temp_role == "Faculty") {
			WITFaculty *pFile = new WITFaculty(temp_name, temp_add, temp_num, temp_rate);
			Mainpersons.push_back(pFile);
		}
		else {
			dlg.text_disp = "Error while opening file";
			dlg.DoModal();
		}
	}
	
	dlg.persons = Mainpersons;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();

	if (nResponse == IDOK) 
	{
		ofstream fout("witPersonFile.txt"); 
		for (int i = 0; i < dlg.persons.size(); i++) {
			if (dlg.persons[i] == nullptr) { 
				if (i == dlg.persons.size() - 1) {
					break;
				}
			}
			else {
				fout << *(dlg.persons[i]);
			}
		}
	}
	else if (nResponse == IDCANCEL){}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
		TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	if (pShellManager != nullptr)
	{	delete pShellManager;	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif
	return FALSE;
}