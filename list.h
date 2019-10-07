#pragma once
#include<iostream>
using namespace std;
template<class T>
class List
{
	T date;
	List* Next;
public:
	List(T _data)
		:Next(nullptr)
		,date(_data)
	{	
	}
	List()
		:Next(nullptr)
	{}
	~List()
	{
		
	}
void DeleteList()
	{
		List<T>*  temp = this->Next;
		List<T>*  temp1= this->Next;
		while (temp1!=nullptr)
		{
			temp1 = temp1->Next;
			delete temp;
			temp = temp1;
			cout << "É¾³ýÒ»´Î" << endl;
		}
	}
	
void Printf()
	{
		List* temp=this->Next;
		while (temp != nullptr)
		{
			cout << temp->date << "->";
			temp = temp->Next;
		}
		cout << "nullptr" << endl;;
	}
 void insertHead(T data)
{
	List<T>* temp = new List<T>(data);
	temp->Next = this->Next;
	this->Next = temp;
 }
 
void inserEnd(T data)
{
	List<T>* temp = new List<T>(data);
	List<T>* pCur = this;
	while (pCur->Next != nullptr)
	{
		pCur = pCur->Next;
	}
	pCur->Next = temp;
}

void delNval(T _data)
{
	List<T>* temp = this;
	while (temp->Next != nullptr)
	{
		if (temp->Next->date == _data)
		{
			List<T>* pCur=temp->Next;
			temp->Next = temp->Next->Next;
			delete pCur;
			break;
		}
		temp = temp->Next;
	}
}
};

