#pragma once
#include "afxdialogex.h"


// DlgSale 对话框

class DlgSale : public CDialogEx
{
	DECLARE_DYNAMIC(DlgSale)

public:
	DlgSale(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DlgSale();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	int count;
	afx_msg void OnEnChangeEdit1();
	int sale_count;
};
