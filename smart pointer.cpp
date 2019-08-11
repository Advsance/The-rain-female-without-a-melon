#include <iostream>
using namespace std;
#if 0
namespace bite {
	
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}
		auto_ptr()
		{                      // raii
			if (_ptr)
			{
				delete _ptr;
			}
		}
		T& operator* ()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
	private:
		T* _ptr;
	};
}
template<class T>
class SmartPtr {
public:
	SmartPtr(T* ptr = nullptr)
		: _ptr(ptr) {}

	~SmartPtr()
	{
		if (_ptr)
			delete _ptr;
	}
//	T* _ptr; /* Ҳ�ɸ�Ϊ˽�е� ���Ϊ˽����ô�÷����������е�temp���÷�����ͬ��
	         /*   ���Ǹо�û��Ҫ����������Ļ���ÿ�ζ�Ҫ��� . �������ֶ��ͷ����� */
private:
	T* _ptr;
};

class test {
public: 
	int* a =new(int);
	~test()
	{
		delete a;
	}
};
void fun() {
	test f;
	test x=f;
}

void fun1(int* temp) {
	
	SmartPtr<int> sp(temp);
	temp[1]= 10;
//	sp._ptr[1] = 10;
}
int  main() {
	int* temp = new int[100];
	 fun1(temp);
	 delete temp;
	return 0;
}

#endif
#if 0
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr = nullptr)
		:_ptr(ptr)
	{}
	~SmartPtr()
	{                     
		if (_ptr)
		{
			delete _ptr;
		}
	}
	T& operator* ()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
	T* operator[](int n)
	{
		return _ptr + n;
	}
private:
	T* _ptr;
};
class Data {
public:
	Data() {
		cout << "���캯������" << endl;
	}
	int _year;
	int _month;
	int _day;
};
void fun1(SmartPtr<Data> tp) {
	SmartPtr<Data> ti(tp);
}
int main() {
	SmartPtr<int> sp(new int[100]);
	*sp[1] = 1;
	*sp[12] = 10;
	cout << *sp[19] << ' ' << *sp[12] << endl;
	SmartPtr<Data> tp(new Data);
	tp->_month = 8;
	tp.operator->()->_year=1;
	cout << tp->_year << endl;
	cout << tp->_month << endl;
	SmartPtr<int> sp(new int);
	fun1(tp);	
	system("pause");
	return 0;
}
#endif


