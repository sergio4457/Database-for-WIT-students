// Object Oriented Programming Final Project
// Group: Sergio Pina, Patrick Yepmo, Rafael Barbosa

#include "stdafx.h"
#include "Final_Project.h"
#include "PayDlg.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(PayDlg, CDialogEx)

PayDlg::PayDlg(CWnd* pParent)
	: CDialogEx(IDD_DIALOG_PAY, pParent)
	, text_pay(_T(""))
{}

PayDlg::~PayDlg(){}

void PayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PAY, text_pay);
}

BEGIN_MESSAGE_MAP(PayDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_PAY, &PayDlg::OnEnChangeEditPay)
END_MESSAGE_MAP()

void PayDlg::OnEnChangeEditPay(){}