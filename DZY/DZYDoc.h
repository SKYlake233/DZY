
// DZYDoc.h: CDZYDoc 类的接口
//


#pragma once
#include"Company.h"
#include"Product.h"


class CDZYDoc : public CDocument
{
protected: // 仅从序列化创建
	CDZYDoc() noexcept;
	DECLARE_DYNCREATE(CDZYDoc)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CDZYDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CObArray* compObjs = new CObArray();
	CObArray* prodObjs = new CObArray();

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	//Company  operations
	void addCompany(Company* comp);
	void updCompany(Company* comp);
	void delCompany(CString name);
	void showCompany(CDC* pDC, int x, int y);
	bool checkCompany(CString name);
	Company* findCompany(CString name);
	//product oprations
	void addProduct(Product* prod);
	void updProduct(Product* prod);
	void delProduct(CString prod);
	Product* findProduct(CString name);
	void updProductCompName(CString before, CString now);
	void delProductCompName(CString company_name);
	bool checkProduct(CString name);
};
