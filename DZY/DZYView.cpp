
// DZYView.cpp: CDZYView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DZY.h"
#endif

#include "DZYDoc.h"
#include "DZYView.h"
#include"CompDlg.h"
#include"CompDlgFind.h"
#include"ProdDlg.h"
#include"ProdDlgFind.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDZYView

IMPLEMENT_DYNCREATE(CDZYView, CView)

BEGIN_MESSAGE_MAP(CDZYView, CView)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_ADD, &CDZYView::OnAdd)
	ON_COMMAND(ID_UPD, &CDZYView::OnUpd)
	ON_COMMAND(ID_DEL, &CDZYView::OnDel)
	ON_COMMAND(ID_PROD_ADD, &CDZYView::OnProdAdd)
	ON_COMMAND(ID_PROD_DEL, &CDZYView::OnProdDel)
	ON_COMMAND(ID_PROD_UPD, &CDZYView::OnProdUpd)
END_MESSAGE_MAP()

// CDZYView 构造/析构

CDZYView::CDZYView() noexcept
{
	// TODO: 在此处添加构造代码

}

CDZYView::~CDZYView()
{
}

BOOL CDZYView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CDZYView 绘图

void CDZYView::OnDraw(CDC* pDC)
{
	CDZYDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDoc->showCompany(pDC , 10 , 10);
}


// CDZYView 诊断

#ifdef _DEBUG
void CDZYView::AssertValid() const
{
	CView::AssertValid();
}

void CDZYView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDZYDoc* CDZYView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDZYDoc)));
	return (CDZYDoc*)m_pDocument;
}
#endif //_DEBUG


// CDZYView 消息处理程序


void CDZYView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: 在此处添加消息处理程序代码
	// TODO: 在此处添加消息处理程序代码
	CMenu menu;
	menu.LoadMenuW(IDR_MENU1);
	CMenu* subMenu = menu.GetSubMenu(0);
	subMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
}


void CDZYView::OnAdd()
{
	// TODO: 在此添加命令处理程序代码
	CompDlg Dlg;
	int ret = Dlg.DoModal();
	if (ret == IDOK) {
		Company* comp = new Company();
		comp->set_name(Dlg.name);
		comp->set_address(Dlg.address);
		comp->set_phone(Dlg.phone);
		CDZYDoc* pDOC = GetDocument();
		pDOC->addCompany(comp);
		Invalidate();
	}
}


void CDZYView::OnUpd()
{
	// TODO: 在此添加命令处理程序代码
	CompDlgFind* Dlg = new CompDlgFind();
	int ret = Dlg->DoModal();
	if (ret == IDOK) {
		CString name = Dlg->name;
		CDZYDoc* pDoc = GetDocument();
		Company* comp_t = pDoc->findCompany(name);
		if (comp_t != NULL) {
			CompDlg Dlg;
			Dlg.name = comp_t->get_name();
			Dlg.address = comp_t->get_address();
			Dlg.phone = comp_t->get_phone();
			ret = Dlg.DoModal();
			if (ret == IDOK) {
				comp_t->set_name(Dlg.name);
				comp_t->set_address(Dlg.address);
				comp_t->set_phone(Dlg.phone);
				pDoc->updProductCompName(name, Dlg.name);
				Invalidate();
			}
		}
		
	}
}


void CDZYView::OnDel()
{
	// TODO: 在此添加命令处理程序代码
	CompDlgFind* Dlg = new CompDlgFind();
	int ret = Dlg->DoModal();
	if (ret == IDOK) {
		CString name = Dlg->name;
		CDZYDoc* pDoc = GetDocument();
		pDoc->delCompany(name);
		pDoc->delProductCompName(name);
		Invalidate();
	}
}


void CDZYView::OnProdAdd()
{
	// TODO: 在此添加命令处理程序代码
	ProdDlg Dlg;
	int ret = Dlg.DoModal();
	if (ret == IDOK) {
		CString company_name = Dlg.company_name;
		CDZYDoc* pDoc = GetDocument();
		if (pDoc->findCompany(company_name) == NULL) {
			MessageBox(L"error", L"error", 0);
			return;
		}
		Product* prod = new Product();
		prod->set_company_name(company_name);
		prod->set_name(Dlg.name);
		prod->set_count(Dlg.count);
		pDoc->addProduct(prod);
		Invalidate();
	}
}


void CDZYView::OnProdDel()
{
	// TODO: 在此添加命令处理程序代码
	ProdDlgFind Dlg;
	int ret = Dlg.DoModal();
	if (ret == IDOK) {
		CString name = Dlg.name;
		CDZYDoc* pDoc = GetDocument();
		Product* prod = pDoc->findProduct(name);
		if (prod != NULL) {
			pDoc->delProduct(name);
			Invalidate();
		}
		else {
			MessageBox(L"error", L"error", 0);
		}
	}
}


void CDZYView::OnProdUpd()
{
	// TODO: 在此添加命令处理程序代码
	ProdDlgFind Dlg;
	int ret = Dlg.DoModal();
	if (ret == IDOK) {
		CString name = Dlg.name;
		CDZYDoc* pDoc = GetDocument();
		Product* prod = pDoc->findProduct(name);
		if (prod != NULL) {
			ProdDlg PDlg;
			PDlg.name = prod->get_name();
			PDlg.company_name = prod->get_company_name();
			PDlg.count = prod->get_count();
			ret = PDlg.DoModal();
			if (pDoc->findCompany(PDlg.company_name) != NULL) {
				if (ret == IDOK) {
					prod->set_company_name(PDlg.company_name);
					prod->set_name(PDlg.name);
					prod->set_count(PDlg.count);
					Invalidate();
					return;
				}
			}
			else {
				MessageBox(L"不存在公司名", L"error", 0);
			}
		}
		else {
			MessageBox(L"不存在商品", L"error", 0);
		}
	}
}
