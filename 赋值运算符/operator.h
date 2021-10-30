#pragma once
//经典做法
#include<string>
class CMyString {

public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);
	
	CMyString& operator= (const CMyString& str) {
		
		//3
		if (&str == this) {
			return *this;
		}

		//4
		delete[]m_pData;
		m_pData = nullptr;

		//5
		char* m_pData = new char[strlen(str.m_pData) + 1];
		strcpy(m_pData, str.m_pData);
		//copy时包括终止符'\0'

		//6
		return *this;
	}

private:
	char* m_pData;
};

//考虑异常安全性 -先new后delete
class CMyString {

public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);

	CMyString& operator= (const CMyString& str) {

		if (&str == this) {
			return *this;
		}

		char* _m_pData = new char[strlen(str.m_pData) + 1];
		strcpy(_m_pData, str.m_pData);
		
		delete[]m_pData;
		m_pData = _m_pData;

		return *this;
	}

private:
	char* m_pData;
};

//考虑异常安全性 -临时对象交换
class CMyString {

public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);

	CMyString& operator= (const CMyString& str) {

		if (&str == this) {
			return *this;
		}
		
		CMyString temp(str);

		char* p = temp.m_pData;
		temp.m_pData = m_pData;
		m_pData = p;

		p = nullptr;

		return *this;
	}

private:
	char* m_pData;
};