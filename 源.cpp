#include<iostream> 
using namespace std;
#include <stack>
#include<string>
#include<vector>
class Date {
public:
	Date(int year = 100)
		:_year(year)
	{
		_year = year;
		cout << "constructor" << endl;
	}
	int _year;
	int _sun;
	void fun(int year) {
		_year = year;
	}
	Date operator+(const Date& b) {
		return _year + b._year;
	}
	
	Date(const Date& d) {
		_sun = 31;
		_year = d._year;
	}
	~Date() {
		cout << "destructor" << endl ;
	}
	
		Date& operator=(const Date&b) {
			 _year = b._year;
			 return *this;
		}

		void print1() {
			cout << "非const" << endl;
	}
		void print2()const {
			cout << "const" << endl;
		}
	
};
	Date operator==(Date&a, Date&b) {
		return a._year + b._year;
	}
	void test() {
		Date A(1);
		Date b(A);
		cout << A._year << endl;
		cout << A._sun << endl;
		cout << b._year << endl;
		cout << b._sun << endl;
	}
	void test1() {
		Date a(2);
		Date b(3);
		Date c;
		c = a + b;
		cout <<c._year<< endl;
	}
	void test2() {
		Date A;
		const Date B;
		A.print1();
		A.print2();
	//	B.print1();
		B.print2();
	}
#if 0
int main() {
//	test2();
	stack<int> A;
	string f;
	vector<int> fff;
	fff.push_back(3);
	fff.push_back(3);
	fff.push_back(3);
	fff.clear();
//	cout << fff[1] << endl;
	
	system("pause");
	return 0;
}

#endif
class Solution {
public:
	/**
	 *  奇数位上都是奇数或者偶数位上都是偶数
	 *  输入：数组arr，长度大于2
	 *  len：arr的长度
	 *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
	 */
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		stack<int> temp1, temp2;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] % 2 == 0)
			{
				temp2.push(arr[i]);
			}
			else
			{
				temp1.push(arr[i]);
			}
		}
		len = arr.size();
		arr.clear();
		int temp;
		for (int i = 0; i < len; i++)
		{
			if (!temp2.empty() && (!(i % 2)))
			{
				temp = temp2.top();
				arr.push_back(temp);
				temp2.pop();
				continue;
			}
			else if (!temp1.empty())
			{
				temp = temp1.top();
				arr.push_back(temp);
				temp1.pop();
				continue;
			}
			if (!temp1.empty())
			{
				temp = temp1.top();
				arr.push_back(temp);
				temp1.pop();
				continue;
			}
			if (!temp2.empty())
			{
				temp = temp2.top();
				arr.push_back(temp);
				temp2.pop();
				continue;
			}
		}
	}
};

int main() {
	vector<int> arr;
	int i,temp;
	for (i = 0; i < 101; i++)
	{
		temp = rand() % 100 + 1;
		arr.push_back(temp);
	}
	Solution a;
	a.oddInOddEvenInEven(arr,9);
	for (i = 1; i < 101; i++)
	{
		cout << arr[i] << endl;
		i++;
	}
	system("pause");
}