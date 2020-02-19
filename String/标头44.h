#pragma once
#include<string.h>
class SString {
public:
	SString(const char* str = "")
	{
		if (nullptr == str)
		{
			str = "";
		}

		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	const char* c_str()
	{
		return _str;
	}

private:
	char* _str;

};