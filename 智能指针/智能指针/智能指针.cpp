#include <iostream>
#include "auto_ptr.h"
#include <string>
using namespace std;


template <class T>
class Shared_ptr {
private:
	T* _ptr;
	int* _count;
	mutex _pMutex;
	void add_count()
	{
			_pMutex->lock();
			*_count++;
			_pMutex->unlock();
	}

	void Release()
	{
		bool detection = false;
		_pMutex->lock();
		_count--;
		if (_count == 0)
		{
			delete _ptr;
			delete _count;
			detection = true;
		}
		_pMutex->unlock();
		
		if (detection == true)
			delete _pMutex;
	}

public:
	Shared_ptr(T* ptr = nullptr)
		:_ptr(ptr)
		, _count(new int(1))
		, _pMutex(new mutex)

	{}

	~Shared_ptr()
	{
		Release();
	}

	Shared_ptr(Shared_ptr<T>& ptr)
	{
		add_count();
		_ptr = ptr._ptr;
	}
	
	Shared_ptr & operator = (Shared_ptr<T>& ptr)
	{
		add_count();
		_ptr = ptr;
		return *this;
	}

	T& operator * ()
	{
		return *_ptr;
	}

	T* operator -> ()
	{
		return _ptr;
	}
};

string* test()
{
	string* a = new string("hello world");
	
	cout << *a<< endl;
	
	Auto_ptr<string> p(a);

	cout << *p << endl;

	Auto_ptr<string> p2(p);

//	cout << *p << endl;    // 此句代码崩溃 因为p中的指针以及被置为空
	p = p2;
//	cout << *p2 << endl;  // 此句代码崩溃因为p2的资源已经交给了p;
	cout << *p << endl;
	return a;
}

void test1() 
{
	int a = 1;
	int b = 2;
	a = a + b;
}

void test2()
{
	string*  a = new string("hello world");
	shared_ptr<string> a1(a);
	shared_ptr<string> a2(a);
	cout << *a1 << endl;
}


#include <mysql.h>


int main()
{
	mysql_init(NULL);

	mutex a;
	a.lock();
//
	a.unlock();
//    std::cout << *a; // 在使用智能指针后 *a 无法打印 因为在栈退出的时候会释放Auto_ptr 的对象
	                 // 在析构的时候顺带把 堆上的内存也析构调了.
}
