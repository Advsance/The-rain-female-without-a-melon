#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define DASICVALUE 16
#define COUNTCAPA(size) (((size) / DASICVALUE + 1) * DASICVALUE)
class String {
public:
	String(const char* data = " ")
		:m_cap(DASICVALUE)
	{
		if (nullptr == data)
		{
			data = "";
		}

		m_size = strlen(data);
		m_cap = COUNTCAPA(m_size);
		m_data = new char[m_cap];
		strcpy(m_data, data);
	}

	String(const String& c)
	{
		m_size = c.m_size;
		m_cap = c.m_cap;

		m_data = new char[m_cap];
		strcpy(m_data, c.m_data);
	}

   void  operator = (const char* std)
	{
		m_size = strlen(std);
		m_cap = COUNTCAPA(m_size);
		m_data = new char[m_cap];

		strcpy(m_data, std);		
	}

	void operator = (const String& std)
	{
		m_size = std.m_size;
		m_cap = std.m_cap;
		m_data = new char[m_cap];

		strcpy(m_data, std.m_data);
	}

	

	const size_t size()
	{
		return m_size;
	}

	const char* c_str()
	{
		return m_data;
	}

	const size_t cap()
	{
		return m_cap - 1;
	}

	bool append(const char* str)
	{
		Dilatation(strlen(str));
		char* temp = m_data+m_size;
		strcpy(m_data+m_size, str);
		return true;
	}

	bool resize(size_t size, const char ch= '\0')
	{
		if (size < m_size)
		{
			m_size = size;
			m_data[size] = '\0';
		}
		else
		{
			Dilatation(size);
			{
				for (int i = m_size; m_size < m_size + size; i++)
				{
					m_data[i] = ch;
				}
			}
		}
		return true;
	}

	bool reserve(size_t  size)
	{
		if (m_cap < size)
		{
			m_data = (char*)realloc(m_data, size);
		}
	}

//由于这个在类内所以 << 第一个参数默认为this  那么只能传一个os 这
// 导致只能 写为  String<<cout;
	void operator << (ostream & os)
	{
		int i;

		for (i = 0; i < m_size; i++)
		{
			os << m_data[i];
		}

		
	}

	friend	void operator << (ostream& os, String& s);
	friend  void operator >> (istream& is, String& s);
	~String()
	{
		if (m_data)
		{
			delete[] m_data;
			m_data = nullptr;
		}
		m_cap = 0;
	}
private:
	char* m_data;
	size_t m_size;
	size_t m_cap;

	void Dilatation(size_t size)
	{
		if ((m_cap - 1 - m_size) < size)
		{
			m_cap = size + m_size;
			m_cap = COUNTCAPA(size);
			char* temp = new char[m_cap];
			strcpy(temp, m_data);
			delete[] m_data;
			m_data = temp;
		}
	}
};


// 这样一来就可以实现cout << String;
	void operator << (ostream& os, String& s) 
	{
		int i;

		for (i = 0; i < s.m_size; i++)
		{
			os << s.m_data[i];
		}

	}

	void operator >> (istream& is, String& s)
	{
		// 小心再char后面使用了(), 写为new char(1024) 
		char* temp = new char[1024];
		is.getline(temp, 1024);

		s.Dilatation(strlen(temp));
		s.m_size = strlen(temp);
		s.m_data = (char*)malloc(s.m_cap);
		if (s.m_data)
		{
			strcpy(s.m_data, temp);
			delete[] temp;
		}
	}