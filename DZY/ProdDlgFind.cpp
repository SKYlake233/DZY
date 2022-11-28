// ProdDlgFind.cpp: 实现文件
//

#include "pch.h"
#include "DZY.h"
#include "afxdialogex.h"
#include "ProdDlgFind.h"


// ProdDlgFind 对话框

IMPLEMENT_DYNAMIC(ProdDlgFind, CDialogEx)

ProdDlgFind::ProdDlgFind(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, name(_T(""))
{

}

ProdDlgFind::~ProdDlgFind()
{
}

void ProdDlgFind::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
}


BEGIN_MESSAGE_MAP(ProdDlgFind, CDialogEx)
END_MESSAGE_MAP()


// ProdDlgFind 消息处理程序
