// CompDlg.cpp: 实现文件
//

#include "pch.h"
#include "DZY.h"
#include "afxdialogex.h"
#include "CompDlg.h"


// CompDlg 对话框

IMPLEMENT_DYNAMIC(CompDlg, CDialogEx)

CompDlg::CompDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_COMP, pParent)
	, name(_T(""))
	, address(_T(""))
	, phone(_T(""))
{

}

CompDlg::~CompDlg()
{
}

void CompDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_name, name);
	DDX_CBString(pDX, IDC_COMBO_address, address);
	DDX_Text(pDX, IDC_EDIT_PHONE, phone);
}


BEGIN_MESSAGE_MAP(CompDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_PHONE, &CompDlg::OnEnChangeEditPhone)
END_MESSAGE_MAP()


// CompDlg 消息处理程序


void CompDlg::OnEnChangeEditPhone()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
