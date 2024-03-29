// Object Oriented Programming Final Project
// Group: Sergio Pina, Patrick Yepmo, Rafael Barbosa
#ifndef FACULTYINPUT_H
#define FACULTYINPUT_H
#include <string>
#include "stdafx.h"
using namespace std;

class FacultyInput : public CDialogEx
{
	DECLARE_DYNAMIC(FacultyInput)
public:
	FacultyInput(CWnd* pParent = nullptr); 
	virtual ~FacultyInput();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FACULTY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX); 
	DECLARE_MESSAGE_MAP()
public:
	CString Fname;
	CString Faddress;
	CString FWnum;
	CString FSalary;
};
#endif