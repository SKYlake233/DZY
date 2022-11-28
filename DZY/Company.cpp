#include "pch.h"
#include "Company.h"

IMPLEMENT_SERIAL(Company, CObject, 1);
Company::Company() {

}
Company::~Company() {

}

CString Company::get_name()
{
	return this->name;
}

void Company::set_name(CString name)
{
	this->name = name;
}

CString Company::get_address()
{
	return this->address;
}

void Company::set_address(CString address)
{
	this->address = address;
}

CString Company::get_phone()
{
	return this->phone;
}

void Company::set_phone(CString phone)
{
	this->phone = phone;
}

void Company::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{	// storing code
		ar << name << address << phone;
	}
	else
	{	// loading code
		ar >> name >> address >> phone;
	}
}

void Company::showComp(CDC* pDC, int x, int y)
{
	CString sOut = name + "   " + address + "    " + phone;
	pDC->TextOut(x, y, sOut);
}
