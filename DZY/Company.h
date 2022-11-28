#pragma once
/// <summary>
/// 公司类  含有公司名称 地址等属性
/// </summary>
class Company :public CObject
{
	DECLARE_SERIAL(Company)
protected:
	CString name;
	CString address;
	CString phone;

public:
	Company();
	~Company();

	//功能函数
	CString get_name();
	void set_name(CString name);
	CString get_address();
	void set_address(CString address);
	CString get_phone();
	void set_phone(CString phone);
	virtual void Serialize(CArchive& ar);
	void showComp(CDC* pDC, int x, int y);
};

