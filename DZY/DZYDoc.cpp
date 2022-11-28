
// DZYDoc.cpp: CDZYDoc 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DZY.h"
#endif

#include "DZYDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDZYDoc

IMPLEMENT_DYNCREATE(CDZYDoc, CDocument)

BEGIN_MESSAGE_MAP(CDZYDoc, CDocument)
END_MESSAGE_MAP()


// CDZYDoc 构造/析构

CDZYDoc::CDZYDoc() noexcept
{
	// TODO: 在此添加一次性构造代码

}

CDZYDoc::~CDZYDoc()
{
}

BOOL CDZYDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CDZYDoc 序列化

void CDZYDoc::Serialize(CArchive& ar)
{

	compObjs->Serialize(ar);
	prodObjs->Serialize(ar);

	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CDZYDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CDZYDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CDZYDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}
#endif // SHARED_HANDLERS

// CDZYDoc 诊断

#ifdef _DEBUG
void CDZYDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDZYDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

void CDZYDoc::addCompany(Company* comp)
{
	compObjs->Add(comp);
	SetModifiedFlag();
}

void CDZYDoc::updCompany(Company* prod)
{
	for (int i = 0; i < compObjs->GetCount(); i++)
	{
		Company* comp_t = (Company*)compObjs->GetAt(i);
		if (comp_t->get_name() == prod->get_name()) {
			comp_t->set_name(prod->get_name());
			comp_t->set_address(prod->get_address());
			comp_t->set_phone(prod->get_phone());
			//修改产品中的信息
			SetModifiedFlag();
			break;;
		}
	}
	SetModifiedFlag();
}

void CDZYDoc::delCompany(CString name)
{
	for (int i = 0; i < compObjs->GetCount(); i++)
	{
		Company* comp_t = (Company*)compObjs->GetAt(i);
		if (comp_t->get_name() == name) {
			compObjs->RemoveAt(i);
			delete(comp_t);
			SetModifiedFlag();
			return;
		}
	}
	SetModifiedFlag();
}

void CDZYDoc::showCompany(CDC* pDC, int x, int y)
{
	for (int i = 0; i < compObjs->GetCount(); i++)
	{
		Company* comp_t = (Company*)compObjs->GetAt(i);
		comp_t->showComp(pDC, x, y);
		for (int j = 0; j < prodObjs->GetCount(); j++)
		{

			Product* prod_t = (Product*)prodObjs->GetAt(j);
			if (prod_t->get_company_name() == comp_t->get_name()) {
				prod_t->showProd(pDC, x + 200, y);
				y += 20;
			}
		}
		y += 10;
	}
}

void CDZYDoc::delProduct(CString name)
{
	for (int i = 0; i < prodObjs->GetCount(); i++)
	{
		Product* prod_t = (Product*)prodObjs->GetAt(i);
		if (prod_t->get_name() == name) {
			prodObjs->RemoveAt(i);
			delete(prod_t);
			SetModifiedFlag();
			return;
		}
	}
	SetModifiedFlag();
}

Product* CDZYDoc::findProduct(CString name)
{
	for (int i = 0; i < prodObjs->GetCount(); i++)
	{
		Product* prod_t = (Product*)prodObjs->GetAt(i);
		if (prod_t->get_name() == name) {
			return prod_t;
			break;
		}
	}
	return NULL;
}

Company* CDZYDoc::findCompany(CString name)
{
	for (int i = 0; i < compObjs->GetCount(); i++)
	{
		Company* comp_t = (Company*)compObjs->GetAt(i);
		if (comp_t->get_name() == name) {
			return comp_t;
			break;
		}
	}
	return NULL;
}

void CDZYDoc::addProduct(Product* prod)
{
	prodObjs->Add(prod);
	SetModifiedFlag();
}

void CDZYDoc::updProduct(Product* prod)
{
	for (int i = 0; i < compObjs->GetCount(); i++)
	{
		Product* prod_t = (Product*)compObjs->GetAt(i);
		if (prod_t->get_name() == prod->get_name()) {
			prod_t->set_company_name(prod->get_company_name());
			prod_t->set_count(prod->get_count());
			SetModifiedFlag();
			break;
		}
	}
}

void CDZYDoc::updProductCompName(CString before, CString now) {
	for (int i = 0; i < prodObjs->GetCount(); i++)
	{
		Product* prod_t = (Product*)prodObjs->GetAt(i);
		if (prod_t->get_company_name() == before) {
			prod_t->set_company_name(now);
		}
	}
	SetModifiedFlag();
}

void CDZYDoc::delProductCompName(CString company_name)
{
	for (int i = 0; i < prodObjs->GetCount(); i++)
	{
		Product* prod_t = (Product*)prodObjs->GetAt(i);
		if (prod_t->get_company_name() == company_name) {
			prodObjs->RemoveAt(i);
		}
	}
	SetModifiedFlag();
}

// CDZYDoc 命令
