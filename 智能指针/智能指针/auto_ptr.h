#pragma once
#include <thread>
#include <mutex>
template <class T>
class Auto_ptr
{
private:
	T* _ptr;

public:
	Auto_ptr(T* ptr = nullptr)
		:_ptr(ptr)
	{}

	~Auto_ptr()
	{
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}
	}

	Auto_ptr(Auto_ptr& ptr)
		:_ptr(ptr._ptr)
	{
		ptr._ptr = nullptr;
	}

	Auto_ptr & operator = (Auto_ptr& ptr)
	{
		if (this != &ptr)
		{
			if (_ptr)
			{
				delete _ptr;
			}
			_ptr = ptr._ptr;
			ptr._ptr = nullptr;
		}
		return *this;
	}
	
	T & operator * ()
	{
		return *_ptr;
	}

	T * operator -> ()
	{
		return _ptr;
	}
};

template <class T>
class Unique_ptr
{
private:
	T* _str;
	
public:
	Unique_ptr(T* str = nullptr)
		:_str(str)
	{}

	T& operator * ()
	{
		return *_str;
	}

	T* operator -> ()
	{
		return _str;
	}

	Unique_ptr & operator = (Unique_ptr<T> & ptr) = delete;
	Unique_ptr(Unique_ptr<T>& ptr) = delete;
};


