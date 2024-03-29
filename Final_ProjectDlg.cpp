// Object Oriented Programming Final Project
// Group: Sergio Pina, Patrick Yepmo, Rafael Barbosa
#include "stdafx.h"
#include "Final_Project.h"
#include "Final_ProjectDlg.h"
#include "afxdialogex.h"
#include <afxtaskdialog.h>
#include <vector>
#include<string>
using namespace std;
#include "witPerson.h"
#include "witFaculty.h"
#include "witStaff.h"
#include "witStudent.h"
#include "dialog_add_person.h"
#include "StudentStaffInput.h"
#include "FacultyInput.h"
#include "DiplayAll.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif
	protected:
	virtual void DoDataExchange(CDataExchange* pDX); 

protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX){}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{	CDialogEx::DoDataExchange(pDX);		}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

CFinalProjectDlg::CFinalProjectDlg(CWnd* pParent )
	: CDialogEx(IDD_FINAL_PROJECT_DIALOG, pParent)
	, text_disp(_T("Welcome"))
{	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);		}

void CFinalProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DISP_TEXT, text_disp);
}

BEGIN_MESSAGE_MAP(CFinalProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD_PERSON, &CFinalProjectDlg::OnBnClickedButtonAddPerson)
	ON_BN_CLICKED(IDC_BUTTON_DISPLAY, &CFinalProjectDlg::OnBnClickedButtonDisplay)
END_MESSAGE_MAP()

BOOL CFinalProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	SetIcon(m_hIcon, TRUE);		
	SetIcon(m_hIcon, FALSE);	
	return TRUE; 
}

void CFinalProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{	CDialogEx::OnSysCommand(nID, lParam);	}
}

void CFinalProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{	CDialogEx::OnPaint();	}
}

HCURSOR CFinalProjectDlg::OnQueryDragIcon()
{	return static_cast<HCURSOR>(m_hIcon);	}

void CFinalProjectDlg::OnBnClickedButtonAddPerson()
{
	dialog_add_person addPerson_dlg;
	if (addPerson_dlg.DoModal() == IDOK)
	{
		switch (addPerson_dlg.addPerson_option) {
		case 0: {
			
			FacultyInput addFaculty;
			if (addFaculty.DoModal() == IDOK) { 
				
				CT2CA csteTostr_NAME(addFaculty.Fname);
				string name(csteTostr_NAME);

				CT2CA csteTostr_Add(addFaculty.Faddress);
				string address(csteTostr_Add);

				CT2CA csteTostr_num(addFaculty.FWnum);
				string wNum(csteTostr_num);

				CT2CA csteTostr_sal(addFaculty.FSalary);
				string salary(csteTostr_sal);

				WITFaculty *FacultyTemp = new WITFaculty(name, address,wNum,salary);
				persons.push_back(FacultyTemp);
				text_disp = "Faculty Added";
				UpdateData(0);
			}
			else {
				text_disp = "Faculty NOT Added";
				UpdateData(0);
			}
			break;
		}
		case 1: {
			Student_Staff addSS_dlg;
			if (addSS_dlg.DoModal() == IDOK) { 
				CT2CA csteTostr_NAME(addSS_dlg.inName);
				string name(csteTostr_NAME);
				
				CT2CA csteTostr_Add(addSS_dlg.inADD);
				string address(csteTostr_Add);
				
				CT2CA csteTostr_num(addSS_dlg.inWnum);
				string wNum(csteTostr_num);
				
				CT2CA csteTostr_sal(addSS_dlg.inSalary);
				string salary(csteTostr_sal);

				CT2CA csteTostr_hour(addSS_dlg.inHourWorked);
				string wHours(csteTostr_hour);
				
				WITStaff *staffTemp = new WITStaff(name, address, wNum, salary, wHours);
				persons.push_back(staffTemp);
				text_disp = "Staff Added";
				UpdateData(0);
			}
			else {
				text_disp = "Staff NOT Added";
				UpdateData(0);
			}
			break;
		}
		case 2: {
			Student_Staff addSS_dlg;
			if (addSS_dlg.DoModal() == IDOK) { 
				CT2CA csteTostr_NAME(addSS_dlg.inName);
				string name(csteTostr_NAME);

				CT2CA csteTostr_Add(addSS_dlg.inADD);
				string address(csteTostr_Add);

				CT2CA csteTostr_num(addSS_dlg.inWnum);
				string wNum(csteTostr_num);

				CT2CA csteTostr_sal(addSS_dlg.inSalary);
				string salary(csteTostr_sal);

				CT2CA csteTostr_hour(addSS_dlg.inHourWorked);
				string wHours(csteTostr_hour);
				
				WITStudent *studentTemp = new WITStudent(name,address,wNum,salary,wHours); 
				persons.push_back(studentTemp);
				text_disp = "Student added";
				UpdateData(0);
			}
			else{
				text_disp = "Student NOT added";
				UpdateData(0);
			}
			break;
		}
		default:
			break;
		};
	}
}

void CFinalProjectDlg::OnBnClickedButtonDisplay()
{
	DiplayAll display_dlg;
	display_dlg.dispPersons = persons;
	display_dlg.DoModal();
}