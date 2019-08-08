// DispPay.cpp : implementation file
//

#include "stdafx.h"
#include "Final_Project.h"
#include "DispPay.h"
#include "afxdialogex.h"


// DispPay dialog

IMPLEMENT_DYNAMIC(DispPay, CDialogEx)

DispPay::DispPay(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_PAY, pParent)
	, text_pay(_T(""))
{

}

DispPay::~DispPay()
{
}

void DispPay::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PAY, text_pay);
}


BEGIN_MESSAGE_MAP(DispPay, CDialogEx)
END_MESSAGE_MAP()


// DispPay message handlers
