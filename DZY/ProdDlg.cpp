// ProdDlg.cpp: 实现文件
//

#include "pch.h"
#include "DZY.h"
#include "afxdialogex.h"
#include "ProdDlg.h"


// ProdDlg 对话框

IMPLEMENT_DYNAMIC(ProdDlg, CDialogEx)

ProdDlg::ProdDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_PROD, pParent)
	, company_name(_T(""))
	, name(_T(""))
	, count(0)
{

}

ProdDlg::~ProdDlg()
{
}

void ProdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, company_name);
	DDX_Text(pDX, IDC_EDIT2, name);
	DDX_Text(pDX, IDC_EDIT3, count);
}


BEGIN_MESSAGE_MAP(ProdDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &ProdDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// ProdDlg 消息处理程序


void ProdDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
