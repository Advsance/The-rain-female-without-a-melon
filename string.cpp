#include<iostream>
#include<string>
using namespace std;
#ifdef A

int a = 1;
void Fun();
void Fun1()
{
	int array[] = { 1,2,3,4,5,6 };
	for (auto& e : array)
		e = 2;
	for (auto e : array)
		cout << e << endl;
}
void Fun()
{
	cout << a<<"哈哈"<<endl;
}
namespace B1
{
    int	A = 10;
	namespace N1
	{
	int	B = 1;
	}
}
int C = 12;
using namespace B1;
int main() {
	int a = 12;
	cout << a <<"  a=" << ::a << "   " << B1::A << "    " << B1::N1::B << endl << endl;
	cout << N1::B<<endl;x
	cin >> a;
	cout << a << endl;
	Fun();
	int d[10] = { 0 };
	int (&ar)[10] = d ;
	ar[2] = 100;
	Fun1();
	system("pause");
}

#endif
# if 0
int a;
int& A = a;
int main2()
{
	::A = 10;
	const int& q = 12;
	int a = 20;
	int x = a;
	cout << "A=" << ::a << "   q=" << a<< endl;
	system("pause");
	return 0;
}
int main() {
	string A("");
	string B("sssss");
	//cout <<B.at(11) << endl;
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int sadffsd : arr) {
		printf("%d\n", sadffsd);
	}
	char swe[10] = "2wqdasd";
	for (auto s : swe) {
		cout << s << endl;
	}
	cout << A.npos << endl;
	system("pause");
	return 0;
}

#endif

void test1(string A);
void test2(string A);
void test3(string A);
void test4(string A);
void test5(string A);
void test6(string A);
namespace N {

}


void test1(string A) {
	cout <<A.size() << endl;
	cout << A.length() << endl;
	cout << A.capacity() << endl;
	cout << A << endl;
}
//关于resize的用法
void test2(string A) {
	cout << "test2测试打印：" << endl;
	A.clear();
	cout << A.size() << endl;
	cout << A.length() << endl;
	cout << A.capacity() << endl;
	cout << A << endl;
	A.resize(5, 's');
	cout << A.size() << endl;
	cout << A.length() << endl;
	cout << A.capacity() << endl;
	cout << A << endl;
}
void test3(string A) {
	cout << "3" << endl;
	A.reserve();
	cout << A[2] << endl;//数组下标从0开始；如果超过边界 触发断言
	cout << A.length() << endl;
	cout << A.capacity() << endl;
	cout << A << endl;
}
void test4(string A) {
	for (size_t i = 0; i < A.size(); i++)
		cout << A[i] << endl;
	
	string::iterator it = A.begin();
	while (it != A.end())
	{
		cout <<*it << endl;
		it++;
	}
	for (auto ch : A)
	{
		cout << ch << endl;
	}
}
void  test5(string A) {
	A.push_back('a');//只能插一个字符 字符串插不了；
	A.append(" my");
	A +=" name";
	cout << A << endl;
	cout << A.c_str() <<"      " << A.size() <<endl;
	int i = A.rfind('e'); //没有找到返回-1；如果用size_t打印出来则是一个非常大的整数
	cout << i << endl;
	string B;
	B = A.substr(i, A.size() - i);//从i的位置截取字符 截取n个
	cout << B << endl;

	B = A.substr(2);
	cout << B << endl;
	B = A.substr(2, 2);
	cout << B << endl;

}
void test6(string A) {
	string url("https://www.baidu.com/?tn=80035161_1_dg");
	size_t start = url.find("://");//如果没有找到返回-1
	cout << url << endl;
	cout << start << endl;
	if (start == string::npos) {
		cout << "invalid url" << endl;
		return;
	}
	start += 3;
	size_t finish = url.find('/', start);
	string address = url.substr(start, finish - start);
	cout << address << endl;
	//删除协议前缀
	start = url.find("://");
	url.erase(0, start + 3);
	cout << url << endl;
}
class Solution {
public:
	string ReverseString(string str) {
		if (str.empty()) {
			return 0;
			size_t start = 0;
			size_t end = str.size()-1;//不能忘记字符串 从0开始
			while (start < end) {
				swap(str[start], str[end]);
				start++;
				end--;
			}  
			return str;
		}    
	 }
};
void ReverseString(string str) {
	if (str.empty()) {
		return ;
	}
		size_t start = 0;
		size_t end = str.size() - 1;//不能忘记字符串 从0开始
		while (start < end) {
			swap(str[start], str[end]);
			start++;
			end--;
		}
		cout << str << endl;
	
}
void GetEndWorldSize() {
	string str;
	while (getline(cin, str)) {
		size_t pos;
		cout << str.size() - (str.rfind(' ') + 1) << endl;
		return;
	}	
}
int mainstring() {
	string A;
	cout << "默认长度为：  " << A.size() << endl;
	cout << "默认capacity为：  " << A.capacity() << endl; //实际上为16
	A = "aasdasd";
	cout << A << endl;
	//cout << "test1测试：" << endl;
	string B("hello world");
	//test1(B);
	//test2(B);
	//test3(B);
	//test4(B);//便利string类的三种方式
//	test5(B);  //字符串插入删除  截取的几种方式  find substr 等
//	test6(B);//获取一段字符串中的一段内容
   // ReverseString(B); //逆置字符串
	GetEndWorldSize();
	system("pause");
	return 0;
}