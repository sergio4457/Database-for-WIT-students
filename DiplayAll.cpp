// Object Oriented Programming Final Project
// Group: Sergio Pina, Patrick Yepmo, Rafael Barbosa
#include "stdafx.h"
#include "Final_Project.h"
#include "DiplayAll.h"
#include "afxdialogex.h"
#include "Final_ProjectDlg.h"
using namespace std;
#include<vector>
#include<string>
#include "witPerson.h"
#include"PayDlg.h"
int index =0;

IMPLEMENT_DYNAMIC(DiplayAll, CDialogEx)

DiplayAll::DiplayAll(CWnd* pParent)
	: CDialogEx(IDD_DIALOG_DISPLAY, pParent)
	, entry(0)
	, dispName(_T(""))
	, dispAdd(_T(""))
	, dispWnum(_T(""))
	, dispRole(_T("Click Next"))
{}

DiplayAll::~DiplayAll(){}

void DiplayAll::DoDataExchange(CDataExchange* point)
{
	CDialogEx::DoDataExchange(point);
	DDX_Text(point, IDC_EDIT_ENTRY, entry);
	DDX_Text(point, IDC_EDIT_NAME, dispName);
	DDX_Text(point, IDC_EDIT_ADDRESS, dispAdd);
	DDX_Text(point, IDC_EDIT_WNUM, dispWnum);
	DDX_Text(point, IDC_EDIT_ROLE, dispRole);
}

BEGIN_MESSAGE_MAP(DiplayAll, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_PAY, &DiplayAll::payButton)
	ON_BN_CLICKED(IDC_BUTTON_DONE, &DiplayAll::Click_Done)
	ON_BN_CLICKED(IIDC_BUTTON_NEXT, &DiplayAll::Click_Next)
END_MESSAGE_MAP()

void DiplayAll::payButton()
{
	PayDlg G_P;
	if (index <= 0) {
		G_P.text_pay = "I nor no";
		G_P.DoModal();
	}
	else {
		G_P.text_pay = dispPersons[index - 1]->payMe().c_str();
		G_P.DoModal();                                   
	}
}
void DiplayAll::Click_Done()
{
	index = 0;
	EndDialog(0);
}

void DiplayAll::Click_Next()
{
		for (int i = 0; i < dispPersons.size(); i++) {
			if (dispPersons[i] == nullptr) { 
				if (i == dispPersons.size() - 1) {
					break;
				}
				delete dispPersons[i]; 
			}
		}
		if (index < dispPersons.size()){
				entry = index+1;
				dispName = (dispPersons[index]->getName()).c_str();
				dispAdd = (dispPersons[index]->getAddress()).c_str();
				dispWnum = (dispPersons[index]->getwNum()).c_str();
				dispRole = (dispPersons[index]->getRole()).c_str();
				UpdateData(0);
				index++;
		}
		else {
			index = 0;
			EndDialog(0);
		}	
}