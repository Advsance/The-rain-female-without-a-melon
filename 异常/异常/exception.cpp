#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#if 0
void Testfunc() {
	try {
		FILE* pf = fopen("1qwed.txt", "rb");
		if (nullptr == pf)
			throw 1;
		cout << "�򿪳ɹ�" << endl;
		fclose(pf);
	}
	catch (int i)
	{
		cout << "�����쳣" << endl;
	}
}
void test2() {
	int *p = new int[10];
	try
	{
		Testfunc();//����������쳣��Ҫ�Ը�������쳣���в���
	}
	catch (char err)  
	{
		cout << err << endl;
	}
	cout << "test2" << endl;
	delete[] p;
}
int main() {
	//Testfunc(); ������˴˾�������
	try
	{
		Testfunc();
	}
	catch (int err)  //�������Ͳ���,������ڲ����λ�ü���������
//	catch(char err)  //���Ͳ�ƥ�����
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
//	catch (int a)   //�þ����һ����˼��һ���ģ����ÿ��Կ�����ֱ�Ӱ��������ֱ�Ӵ�����
	catch(const int& a)//���Ʒ���ֵ �ȴ���һ������ Ȼ�� �ڽ��з��� 
	{                  // �ڱ�catch�󣬶�������
		cout << &a << endl;
	}
	catch (...)  //���Ͳ�ȷ���ķ�ʽ��������������в���
	{
		cout << "δ֪�쳣" << endl;
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
	cout << "�쳣�Ѿ��׳�" << endl; //���׳��쳣֮�� һ�µĴ��붼Ҫ������ִ��
	fclose(pf);
}

void test2() {
	int *p = new int[10];	
	
	//Testfunc�׳����쳣���Ͳ�֪��
	//���������������������֮����ڴ�й¶
	try {
		Testfunc();//����������쳣��Ҫ�Ը�������쳣���в���
	}
	catch (...)    //���в�������������,��ҪĿ����Ϊ���ͷ���Դ�ȵ�
		           //�൱����һ���쳣���������� ������������ int�Ϳ��Խ���
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