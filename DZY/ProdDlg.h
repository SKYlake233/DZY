#pragma once
#include "afxdialogex.h"


// ProdDlg 对话框

class ProdDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ProdDlg)

public:
	ProdDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ProdDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_PROD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString company_name;
	CString name;
	int count;
};
