// DlgSale.cpp: 实现文件
//

#include "pch.h"
#include "DZY.h"
#include "afxdialogex.h"
#include "DlgSale.h"


// DlgSale 对话框

IMPLEMENT_DYNAMIC(DlgSale, CDialogEx)

DlgSale::DlgSale(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, name(_T(""))
	, count(0)
	, sale_count(0)
{

}

DlgSale::~DlgSale()
{
}

void DlgSale::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, name);
	DDX_Text(pDX, IDC_EDIT2, count);
	DDX_Text(pDX, IDC_EDIT1, sale_count);
}


BEGIN_MESSAGE_MAP(DlgSale, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &DlgSale::OnEnChangeEdit1)
END_MESSAGE_MAP()


// DlgSale 消息处理程序


void DlgSale::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
