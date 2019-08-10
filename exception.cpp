#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#if 0
void Testfunc() {
	try {
		FILE* pf = fopen("1qwed.txt", "rb");
		if (nullptr == pf)
			throw 1;
		cout << "打开成功" << endl;
		fclose(pf);
	}
	catch (int i)
	{
		cout << "发生异常" << endl;
	}
}
void test2() {
	int *p = new int[10];
	try
	{
		Testfunc();//里面可能有异常，要对该里面的异常进行捕获
	}
	catch (char err)  
	{
		cout << err << endl;
	}
	cout << "test2" << endl;
	delete[] p;
}
int main() {
	//Testfunc(); 如果加了此句代码崩溃
	try
	{
		Testfunc();
	}
	catch (int err)  //按照类型捕获,代码会在捕获的位置继续往下走
//	catch(char err)  //类型不匹配崩溃
	{
		cout <<"main:" <<err<< endl;
	}
	system("pause");
}
#endif // 0
#if 0
void testc() {
	int a = 10;
	cout << &a << endl;
	throw a;
}
int main() {
	try {
		testc();
	}
 // catch(...)
//	catch (int a)   //该句和下一句意思是一样的，引用可以看完是直接把这个变量直接传过来
	catch(const int& a)//类似返回值 先创建一个对象 然后 在进行返回 
	{                  // 在被catch后，对象被销毁
		cout << &a << endl;
	}
	catch (...)  //类型不确定的方式下用这个方法进行捕获
	{
		cout << "未知异常" << endl;
	}
	system("pause");
	return 0;
}
#endif
#if 0
void Testfunc() {
	FILE* pf = fopen("1qwed.txt", "rb");
	if (nullptr == pf)
		throw 1;
	cout << "异常已经抛出" << endl; //在抛出异常之后 一下的代码都要不会再执行
	fclose(pf);
}

void test2() {
	int *p = new int[10];	
	
	//Testfunc抛出的异常类型不知道
	//而且若不处理代码会崩溃，之后会内存泄露
	try {
		Testfunc();//里面可能有异常，要对该里面的异常进行捕获
	}
	catch (...)    //进行捕获并且再往出抛,主要目的是为了释放资源等等
		           //相当于上一个异常继续往出抛 在主函数中用 int就可以接收
	{
		delete[] p;
		throw;
	}		
}
int main() {
	try {
		test2();
	}
	catch (int err)
	{
		cout << err<< endl;  
	}
	system("pause");
	return 0;
}
#endif


#if 0
void test2() {
	int *p = new int[10];
	
	delete[] p;
}
int main() {	
	test2();	
	system("pause");
}

#endif

void fun() throw();
void fun1() throw(int, char);

#endif