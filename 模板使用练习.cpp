#include<iostream>
using namespace std;
class Time
{
public:
	Time();
	~Time();
	void time(int a=1, int b=2, int c=3) {
		hour = a;
		min = b;
		second = c;
		cout << a <<"   "<< b << "    " << c << endl;
	}
   
private:
	int hour;
	int min;
	int second;
};

Time::Time()
{
}

Time::~Time()
{
}

class   Date
{
public:
	Date(int year, int  month, int day)
	{
		this->_year = year;
		_month = month;
		_day = day;

	}
	~  Date();
	void Printf()
	{
		cout << "_year=   " << _year     << "   month=  " << _month    << "   _day=  " << _day   << endl;
		a.time();
	}
private:
	int _year;
	int _month;
	int _day;
	Time a;
};



  Date::~  Date()
{
}

  template<typename T>
  T Add(T left, T right)
  {
	  cout << typeid(T).name() << endl;
	  return left + right;
  }


  template<typename T , typename T1>
  T Add1(T left, T1 right)
  {
	  cout << typeid(T).name() <<endl
		  << typeid(T1).name()<< endl;
	  return  right + left +10000;
  }
  int Add1(int left, int right)
  {
	  return  right + left + left;
  }
  int  main5() {
	  Date a(1, 2, 30);
	  a.Printf();
	  Date a2(a);
	  a2.Printf();
	  cout << "Ä£°å£º£º" << endl;
	  cout << Add1(1, 3.2) << endl;
	  cout << Add1(2.1, 2) << endl;
	  cout << Add1<int>(2, 2.1) << endl;
	  system("pause");
	  return 0;
  }