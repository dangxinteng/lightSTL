#pragma once
#include<iostream>
#include<string.h>
class CString
{
	char * m_pData;
public:
	CString(const char& ch, int n = 1);
	CString(const char* str);
	CString(const char* str, int n);
	CString(const CString& cstr);
	CString(const CString& cstr, int nIndex, int n);
	CString(const char* str1, const char* str2);
	CString(const CString& cstr, const char* str);
	CString& operator=(const CString& cstr);
	CString& operator=(const char* str);
	CString& operator+=(const CString& cstr);
	CString& operator+=(const char* str);

	CString& MakeLower();
	CString& MakeUpper();
	CString& MakeReverse();
	int Find(const char* strSub, int iStart = 0) const;
	int Find(const char& ch, int iStart = 0) const;
	CString Mid(int iFirst, int nCount) const;
	CString Mid(int iFirst) const;
	CString Left(int nCount) const;
	CString Right(int nCount) const;
	int Delete(int nIndex, int nCount = 1);

	CString()
	{
		m_pData = new char[1];
		*m_pData = '\0';
	}
	~CString()
	{
		delete[]m_pData;
	}
	const char* GetData() const
	{
		return m_pData;
	}
	char* GetData()
	{
		return m_pData;
	}
	int GetLength() const
	{
		return strlen(m_pData);
	}
	operator const char*()const
	{
		return m_pData;
	}
	CString operator+(const CString& cstr) const
	{
		return CString(m_pData, cstr.m_pData);
	}
	CString operator+(const char* str) const
	{
		return CString(m_pData, str);
	}
	friend bool operator>(const CString& cstr1, const CString& cstr2)
	{
		return strcmp(cstr1.m_pData, cstr2.m_pData) > 0;
	}
	friend bool operator>(const CString& cstr, const char* str)
	{
		return strcmp(str, cstr.m_pData) > 0;
	}
	friend bool operator>(const char* str, const CString& cstr)
	{
		return strcmp(str, cstr.m_pData) > 0;
	}
	friend bool operator>=(const CString& cstr1, const CString& cstr2)
	{
		return strcmp(cstr1.m_pData, cstr2.m_pData) >= 0;
	}
	friend bool operator>=(const CString& cstr, const char* str)
	{
		return strcmp(str, cstr.m_pData) >= 0;
	}
	friend bool operator>=(const char* str, const CString& cstr)
	{
		return strcmp(str, cstr.m_pData) >= 0;
	}
	friend bool operator<(const CString& cstr1, const CString& cstr2)
	{
		return strcmp(cstr1.m_pData, cstr2.m_pData) < 0;
	}
	friend bool operator<(const CString& cstr, const char* str)
	{
		return strcmp(str, cstr.m_pData) < 0;
	}
	friend bool operator<(const char* str, const CString& cstr)
	{
		return strcmp(str, cstr.m_pData) < 0;
	}
	friend bool operator<=(const CString& cstr1, const CString& cstr2)
	{
		return strcmp(cstr1.m_pData, cstr2.m_pData) <= 0;
	}
	friend bool operator<=(const CString& cstr, const char* str)
	{
		return strcmp(str, cstr.m_pData) <= 0;
	}
	friend bool operator<=(const char* str, const CString& cstr)
	{
		return strcmp(str, cstr.m_pData) <= 0;
	}
	friend bool operator==(const CString& cstr1, const CString& cstr2)
	{
		return strcmp(cstr1.m_pData, cstr2.m_pData) == 0;
	}
	friend bool operator==(const CString& cstr, const char* str)
	{
		return strcmp(str, cstr.m_pData) == 0;
	}
	friend bool operator==(const char* str, const CString& cstr)
	{
		return strcmp(str, cstr.m_pData) == 0;
	}
	friend bool operator!=(const CString& cstr1, const CString& cstr2)
	{
		return strcmp(cstr1.m_pData, cstr2.m_pData) != 0;
	}
	friend bool operator!=(const CString& cstr, const char* str)
	{
		return strcmp(str, cstr.m_pData) != 0;
	}
	friend bool operator!=(const char* str, const CString& cstr)
	{
		return strcmp(str, cstr.m_pData) != 0;
	}
	friend  std::ostream & operator <<(std::ostream& out, const CString &cstr)
	{//������ת�������Ͳ��ô˺�����
		const char* p = cstr.GetData();
		out << p;
		return out;
	}
};

