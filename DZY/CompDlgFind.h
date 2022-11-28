#pragma once
#include "afxdialogex.h"


// CompDlgFind 对话框

class CompDlgFind : public CDialogEx
{
	DECLARE_DYNAMIC(CompDlgFind)

public:
	CompDlgFind(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CompDlgFind();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FIND };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString name;
};
