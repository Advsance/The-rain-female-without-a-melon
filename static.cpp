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
	m.insert(pair<string, string>("����", "����"));
	m.insert(make_pair("����","������"));  // stl �ṩ�ķ���
	m.insert(make_pair("�ɽ�", "��ʱ��"));

	cout <<  m["�ɽ�"] << endl;
	cout << m.size() << endl;
	cout << m["�ֳ尡"] << endl; //���������   �ᴴ��һ��("�ֳ尡"��"")�ļ�ֵ��Ȼ���ӡ
	cout << m.size() << endl;    //��ӡ�Ľ��Ϊ4 ˵����һ�䴴����"�ֳ尡"�����ֵ��
	m.insert(make_pair("����", "������1"));
	cout << m.size() << endl;
	cout << m["����"] << endl;
	for (auto& e : m)
	{
		cout << e.first << "---->" << e.second << endl;
	}
	auto  ret = m.find("�ŷ�");  //���û�ҵ���ôret��������λ�ÿ϶���m.end��λ����
	if (ret == m.end())
	{
		cout << "����" << endl;
	}
	system("pause");
}



int main() {
	multimap<string, string> m; //��map������  key�����ظ�
	m.insert(pair<string, string>("����", "����"));
	m.insert(make_pair("����", "������"));  // stl �ṩ�ķ���
	m.insert(make_pair("�ɽ�", "��ʱ��"));

//	cout << m["�ɽ�"] << endl;
	cout << m.size() << endl;
//	cout << m["�ֳ尡"] << endl; //���������   �ᴴ��һ��("�ֳ尡"��"")�ļ�ֵ��Ȼ���ӡ
	cout << m.size() << endl;    //��ӡ�Ľ��Ϊ4 ˵����һ�䴴����"�ֳ尡"�����ֵ��
	m.insert(make_pair("����", "������1"));
	cout << m.size() << endl;
//	cout << m["����"] << endl;
	for (auto& e : m)
	{
		cout << e.first << "---->" << e.second << endl;
	}
	auto  ret = m.find("�ŷ�");  //���û�ҵ���ôret��������λ�ÿ϶���m.end��λ����
	if (ret == m.end())
	{
		cout << "����" << endl;
	}
	system("pause");
}

#include"Dtree.hpp"
#include<set>
// set: ���� & ȥ��  ��������ֹ���
int main()
{
	int arr[] = {1,2,3,0,9,6,24,1};
	set<int> s(arr, arr + sizeof(arr) / sizeof(arr[0]));
	for (auto e : s)
	{
		cout << e << endl;
	}

//	set<pair<string, string>> s;  //��ֵ��Ҳ���� ������û��Ҫ  ��Ϊ��map�Ϳ�����ɸù��� 
//multiset   key�����ظ� �� ���ҿ��Բ���һ�����ֳ����˶��ٴ�
	multiset<int> ss(arr, arr + sizeof(arr) / sizeof(arr[0]));
	for (auto e : ss)
	{
		cout << e << endl;
	}
	system("pause");
}
