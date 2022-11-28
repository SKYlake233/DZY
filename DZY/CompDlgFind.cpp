// CompDlgFind.cpp: 实现文件
//

#include "pch.h"
#include "DZY.h"
#include "afxdialogex.h"
#include "CompDlgFind.h"


// CompDlgFind 对话框

IMPLEMENT_DYNAMIC(CompDlgFind, CDialogEx)

CompDlgFind::CompDlgFind(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_FIND, pParent)
	, name(_T(""))
{

}

CompDlgFind::~CompDlgFind()
{
}

void CompDlgFind::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
}


BEGIN_MESSAGE_MAP(CompDlgFind, CDialogEx)
END_MESSAGE_MAP()


// CompDlgFind 消息处理程序
