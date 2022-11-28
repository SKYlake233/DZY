#pragma once
#include "afxdialogex.h"


// CompDlg 对话框

class CompDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CompDlg)

public:
	CompDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CompDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_COMP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString address;
	afx_msg void OnEnChangeEditPhone();
	CString phone;
};
