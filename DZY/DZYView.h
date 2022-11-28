
// DZYView.h: CDZYView 类的接口
//

#pragma once


class CDZYView : public CView
{
protected: // 仅从序列化创建
	CDZYView() noexcept;
	DECLARE_DYNCREATE(CDZYView)

// 特性
public:
	CDZYDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CDZYView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnAdd();
	afx_msg void OnUpd();
	afx_msg void OnDel();
	afx_msg void OnProdAdd();
	afx_msg void OnProdDel();
	afx_msg void OnProdUpd();
};

#ifndef _DEBUG  // DZYView.cpp 中的调试版本
inline CDZYDoc* CDZYView::GetDocument() const
   { return reinterpret_cast<CDZYDoc*>(m_pDocument); }
#endif

