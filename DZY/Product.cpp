#include "pch.h"
#include "Product.h"
IMPLEMENT_SERIAL(Product, CObject, 1);

Product::Product()
{
}

Product::~Product()
{
}

CString Product::get_company_name()
{
	return this->company_name;
}

CString Product::get_name()
{
	return this->name;
}

int Product::get_count()
{
	return this->count;
}

void Product::set_company_name(CString company_name)
{
	this->company_name = company_name;
}

void Product::set_name(CString name)
{
	this->name = name;
}

void Product::set_count(int count)
{
	this->count = count;
}

void Product::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		ar << company_name << name << count;
	}
	else
	{	// loading code
		ar >> company_name >> name >> count;
	}
}

void Product::showProd(CDC* pDC, int x, int y)
{
	// TODO: 在此处添加实现代码.
	CString count_s;
	count_s.Format(L"%d", count);
	CString sOut = company_name + "   " + name + "    " + count_s;
	pDC->TextOut(x, y, sOut);
}
