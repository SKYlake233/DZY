#pragma once
#include "afxdialogex.h"


// ProdDlgFind 对话框

class ProdDlgFind : public CDialogEx
{
	DECLARE_DYNAMIC(ProdDlgFind)

public:
	ProdDlgFind(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ProdDlgFind();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString name;
};
