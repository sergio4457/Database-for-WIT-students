// Object Oriented Programming Final Project
// Group: Sergio Pina, Patrick Yepmo, Rafael Barbosa

class PayDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PayDlg)

public:
	PayDlg(CWnd* pParent = nullptr);
	virtual ~PayDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_PAY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	DECLARE_MESSAGE_MAP()
public:
	CString text_pay;
	afx_msg void OnEnChangeEditPay();
};
