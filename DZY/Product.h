#pragma once
/// <summary>
/// ��Ʒ��  �Ҿ�����  ��ǰ����������
/// </summary>
class Product :public CObject
{
	DECLARE_SERIAL(Product)
protected:
	CString company_name;
	CString name;
	int count;
public:
	Product();
	~Product();
	CString get_company_name();
	CString get_name();
	int get_count();
	void set_company_name(CString company_name);
	void set_name(CString name);
	void set_count(int count);
	void Serialize(CArchive& ar);
	void showProd(CDC* pDC, int x, int y);
};

