#include<iostream>
using namespace std;
#include<string>

int fun()
{
	static int a = 0;
	int b = 0;
	a++, b++;
	return a + b;
}
int fun1(int a)
{
	static int i = 1;
	return i = i * a;
}
int main()
{
	string a,ss;
	for (int i = 0; i < 10; i++)
	{
		a += 'a';
	}
	cout << a<<endl;
	cout << a[10] << endl;
	system("pause");
}


#include<map>

int main() {
	map<string, string> m;
	m.insert(pair<string, string>("武松", "行者"));
	m.insert(make_pair("李逵","黑旋风"));  // stl 提供的方法
	m.insert(make_pair("松江", "及时雨"));

	cout <<  m["松江"] << endl;
	cout << m.size() << endl;
	cout << m["林冲啊"] << endl; //如果不存在   会创建一个("林冲啊"，"")的键值对然后打印
	cout << m.size() << endl;    //打印的结果为4 说明上一句创建了"林冲啊"这个键值对
	m.insert(make_pair("李逵", "黑旋风1"));
	cout << m.size() << endl;
	cout << m["李逵"] << endl;
	for (auto& e : m)
	{
		cout << e.first << "---->" << e.second << endl;
	}
	auto  ret = m.find("张飞");  //如果没找到那么ret迭代器的位置肯定在m.end的位置上
	if (ret == m.end())
	{
		cout << "不在" << endl;
	}
	system("pause");
}



int main() {
	multimap<string, string> m; //和map的区别  key可以重复
	m.insert(pair<string, string>("武松", "行者"));
	m.insert(make_pair("李逵", "黑旋风"));  // stl 提供的方法
	m.insert(make_pair("松江", "及时雨"));

//	cout << m["松江"] << endl;
	cout << m.size() << endl;
//	cout << m["林冲啊"] << endl; //如果不存在   会创建一个("林冲啊"，"")的键值对然后打印
	cout << m.size() << endl;    //打印的结果为4 说明上一句创建了"林冲啊"这个键值对
	m.insert(make_pair("李逵", "黑旋风1"));
	cout << m.size() << endl;
//	cout << m["李逵"] << endl;
	for (auto& e : m)
	{
		cout << e.first << "---->" << e.second << endl;
	}
	auto  ret = m.find("张飞");  //如果没找到那么ret迭代器的位置肯定在m.end的位置上
	if (ret == m.end())
	{
		cout << "不在" << endl;
	}
	system("pause");
}

#include"Dtree.hpp"
#include<set>
// set: 排序 & 去重  完成这两种功能
int main()
{
	int arr[] = {1,2,3,0,9,6,24,1};
	set<int> s(arr, arr + sizeof(arr) / sizeof(arr[0]));
	for (auto e : s)
	{
		cout << e << endl;
	}

//	set<pair<string, string>> s;  //键值对也可以 ，但是没必要  因为，map就可以完成该功能 
//multiset   key可以重复 ， 而且可以查找一个数字出现了多少次
	multiset<int> ss(arr, arr + sizeof(arr) / sizeof(arr[0]));
	for (auto e : ss)
	{
		cout << e << endl;
	}
	system("pause");
}
