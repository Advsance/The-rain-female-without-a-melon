#pragma once
#include <mutex>
template<class T>
class  Auto_ptr {

private:
	T* _ptr;

public:
	
	Auto_ptr(T* ptr)
		:_ptr(ptr)
	{	
	
	}

	Auto_ptr(Auto_ptr<T>& ptr)
	{
		_ptr = ptr;
		ptr._ptr = nullptr;
	}
	
	T&	operator * ()
	{
		return *_ptr;
	}

	T* operator ->()
	{
		return _ptr;
	 }
	
	Auto_ptr<T>& operator= (Auto_ptr<T>const ap)
	{
		if (this != &ap)
		{
			if (_ptr)
			{
				delete _ptr;
				_ptr = ap._ptr; 
				ap._ptr == nullptr; 
			}
		}

		return this;
	}

	~Auto_ptr()
	{
		if (_ptr)
		{
			delete _ptr;
		}
	}
};

template <class T>
class un_ptr {

private:
	T* _ptr;

	un_ptr(un_ptr<T>&const _ptr) = delete;
	un_ptr<T> & operator = (un_ptr<T>&const prt) = delete;

public:
	un_ptr(T* ptr)
		:_ptr(ptr)
	{

	}

	~un_ptr()
	{
		if (_ptr)
			delete _ptr;
	}

	T*	operator -> ()
	{
		return _ptr;
	}

	T& operator * ()
	{
		return *_ptr;
	}
};



template <class T>
class Shared_ptr {

private:
	T* _ptr;
	mutex* _mutex;
	int* _count;
public:
	Shared_ptr(T* pt ==nullptr)
		:_ptr(ptr)
		,_mutex(new mutex)
		,_count(new int(1))
	{
		
	}

	Shared_ptr(Shared_ptr<T>& ptr)
	{
		_ptr = ptr._ptr;
		_mutex = ptr._mutex;
		_count = ptr._count;
		add();
	}

	Shared_ptr<T>& operator = (Shared_ptr<T>&const ptr)
	{
		res();
		_ptr = ptr._ptr;
		_mutex = ptr._mutex;
		_count = ptr._count;
		add();

		return *this;
	}

	~Shared_ptr()
	{
		res();
	}

	T* operator *()
	{
		return _ptr;
	}

	T& operator ->()
	{
		return *_ptr;
	}
private:
	void add()
	{
		_mutex->lock();
		*_count++;
		_mutex->unlock();
	}

void res()
	{
		bool deleteflag = false;
		_mutex->lock();
		*_count--;
		if (*_count == 0)
			deleteflag = true;
		_mutex->unlock();

		if (deleteflag)
		{
			if(_ptr)
			delete _ptr;
			delete _count;
			delete _mutex;
		}
	}

};


