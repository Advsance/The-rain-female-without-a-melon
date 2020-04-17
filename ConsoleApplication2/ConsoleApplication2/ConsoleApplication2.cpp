// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <thread>
#include <mutex>
using namespace std;
/*
int main()
{
	double a = 12.3123;
	int b = static_cast<int> (a);
	cout << b;
	
	long p1 = reinterpret_cast<long> (&a);
	cout << endl;
	cout << p1 << endl;;

	const int count = 100;
	int* p2 = const_cast<int*> (&count);
	*p2 = 12;
	cout << *p2 << endl;
	cout << count << endl;
}
*/

void fun2(int a)
{
	if (a == 0)
		throw "哈哈哈";
}

void fun(int a)
{
	fun2(a);
	cout << "hellworld";
	if (a == 3)
		throw 3;
}

int main()
{
	try {
		while (1)
		{
			int a;
			cin >> a;
			fun(a);
		}
	}
	catch (const char* a)
	{
		cout << a << endl;
	}

	catch (int a)
	{
		cout << a << endl;
	}
}