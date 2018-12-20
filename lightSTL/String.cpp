#define _CRT_SECURE_NO_WARNINGS
#include "String.h"

CString::CString(const char& ch, int n)
{
	if (n < 0)
		n = 0;
	m_pData = new char[n + 1];
	memset(m_pData, ch, n);
	m_pData[n] = '\0';
}
CString::CString(const char* str)
{
	int nLen = strlen(str);
	m_pData = new char[nLen + 1];
	strcpy(m_pData, str);
}
CString::CString(const char* str, int n)
{
	if (n < 0)
		n = 0;
	int strLen = strlen(str);
	if (n > strLen)
		n = strLen;
	m_pData = new char[n + 1];
	memcpy(m_pData, str, n);
	m_pData[n] = '\0';
}
CString::CString(const CString& cstr)
{
	int nLen = cstr.GetLength();
	m_pData = new char[nLen + 1];
	strcpy(m_pData, cstr.m_pData);
}
CString::CString(const CString& cstr, int nIndex, int n)
{
	int cstrLen = strlen(cstr.m_pData);
	if (nIndex > cstrLen)
		nIndex = cstrLen;
	if (nIndex < 0)
		nIndex = 0;
	if (n < 0)
		n = 0;
	if (n > cstrLen - nIndex)
		n = cstrLen - nIndex;
	m_pData = new char[n + 1];
	memcpy(m_pData, cstr.m_pData + nIndex, n);
	m_pData[n] = '\0';
}
CString::CString(const char* str1, const char* str2)
{
	int nLen1 = strlen(str1);
	int nLen2 = strlen(str2);
	char* pNew = new char[nLen1 + nLen2 + 1];
	memcpy(pNew, str1, nLen1);
	memcpy(pNew + nLen1, str2, nLen2);
	pNew[nLen1 + nLen2] = '\0';
	m_pData = pNew;
}
CString::CString(const CString& cstr, const char* str)
{
	int nLen1 = strlen(cstr.m_pData);
	int nLen2 = strlen(str);
	char* pNew = new char[nLen1 + nLen2 + 1];
	memcpy(pNew, cstr.m_pData, nLen1);
	memcpy(pNew + nLen1, str, nLen2);
	pNew[nLen1 + nLen2] = '\0';
	delete[]cstr.m_pData;
	m_pData = pNew;
}
CString& CString::operator=(const CString& cstr)
{
	delete[]m_pData;
	int nLen = cstr.GetLength();
	m_pData = new char[nLen + 1];
	strcpy(m_pData, cstr.m_pData);
	return *this;
}
CString& CString::operator=(const char* str)
{
	delete[]m_pData;
	int nLen = strlen(str);
	m_pData = new char[nLen + 1];
	strcpy(m_pData, str);
	return *this;
}
CString& CString::operator+=(const CString& cstr)
{
	int nLen1 = strlen(m_pData);
	int nLen2 = strlen(cstr.m_pData);
	char* pNew = new char[nLen1 + nLen2 + 1];
	memcpy(pNew, m_pData, nLen1);
	memcpy(pNew + nLen1, cstr.m_pData, nLen2);
	pNew[nLen1 + nLen2] = '\0';
	delete[]m_pData;
	m_pData = pNew;
	return *this;
}
CString& CString::operator+=(const char* str)
{
	int nLen1 = strlen(m_pData);
	int nLen2 = strlen(str);
	char* pNew = new char[nLen1 + nLen2 + 1];
	memcpy(pNew, m_pData, nLen1);
	memcpy(pNew + nLen1, str, nLen2);
	pNew[nLen1 + nLen2] = '\0';
	delete[]m_pData;
	m_pData = pNew;
	return *this;
}
CString & CString::MakeLower()
{
	char* p = m_pData;
	while (*p != '\0')
	{
		if (*p >= 'A' && *p <= 'Z')
			*p ^= 32;
		p++;
	}
	return *this;
}
CString & CString::MakeUpper()
{
	char* p = m_pData;
	while (*p != '\0')
	{
		if (*p >= 'a' && *p <= 'z')
			*p ^= 32;
		p++;
	}
		
	return *this;
}

CString & CString::MakeReverse()
{
	char* p = m_pData;
	char* q = m_pData + strlen(m_pData);
	while(p < --q)
	{
		char ch = *p;
		*p = *q;
		*q = ch;
		p++;
	}
	return *this;
}

int CString::Find(const char * strSub, int iStart) const
{
	int nLen = strlen(m_pData);
	if (strcmp(strSub, "") == 0)
		return -1;
	if (iStart >= nLen)
		return -1;
	if (iStart < 0)
		iStart = 0;
	char* p = strstr(m_pData + iStart, strSub);
	if (!p)
		return -1;
	return p - m_pData;
}

int CString::Find(const char& ch, int iStart) const
{
	int nLen = strlen(m_pData);
	if (iStart >= nLen)
		return -1;
	if (iStart < 0)
		iStart = 0;
	char* p = strchr(m_pData + iStart, ch);
	if (!p)
		return -1;
	return p - m_pData;
}

CString CString::Mid(int iFirst, int nCount) const
{
	return CString(*this, iFirst, nCount);
}

CString CString::Mid(int iFirst) const
{
	return CString(*this, iFirst, strlen(this->m_pData) + 1);
}

CString CString::Left(int nCount) const
{
	return CString(*this, 0, nCount);
}

CString CString::Right(int nCount) const
{
	if (nCount < 0)
		nCount = 0;
	int nLen = strlen(m_pData);
	return CString(*this, nLen - nCount, nCount);
}

int CString::Delete(int nIndex, int nCount)
{
	int nLen = strlen(m_pData);
	if (nIndex < 0)
		nIndex = 0;
	if (nIndex > nLen)
		nIndex = nLen;
	if (nCount < 0)
		nCount = 0;
	if (nCount > nLen - nIndex)
		nCount = nLen - nIndex;
	int nRepeat = nLen - nIndex - nCount;
	if (nRepeat > 0)
	{
		char* des = m_pData + nIndex;
		char* src = des + nCount;
		while (nRepeat)
		{
			*des++ = *src++;
			nRepeat--;
		}
		m_pData[nLen - nCount] = '\0';
	}
	else
		m_pData[nIndex] = '\0';
	return nCount;
}
