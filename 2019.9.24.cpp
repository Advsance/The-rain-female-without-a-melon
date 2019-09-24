#include<iostream>
#include<vector>
//逆序一段字符串
#include <string>
using namespace std;

void reverseOneWord(string &s,int left,int right)
{
	while (left < right)
	{
		swap(s[left], s[right]);
		left++;
		right--;
	}
}

void reverseWord(string& s) //字符串翻转
{
	int start = 0;
	int end = s.size() - 1;
	while (start < end)
	{
		swap(s[start], s[end]);
		start++;
		end--;
	}
}

void test1()
{
	string s("hello world haha");
	reverseWord(s);
	cout << s << endl;
}

void test2()
{
	string s("hello world haha");
	reverseOneWord(s, 0, s.find(' ') - 1);  // find 如果没找到会返回一个-1; 应该为一个size_t类型的数据
	reverseOneWord(s, 0, s.find(' ') - 1);
	int start = 0;
	int end = s.find(' ')-1;
	while (start < end && end > 0)
	{
		reverseOneWord(s, start, end);
		start = end + 2;
		end = s.find(' ', start)-1;  //start处开始寻找
	}
	//此时除了最后一个字符都已经逆序
	reverseOneWord(s, start, s.size() - 1);
	cout << s << endl;

}

//字符串相乘
/* 数据可以先倒着存，处理会更加方便些，然后倒着打印就行   */
void charmuit(string& a, string& s)
{

}

//字符串相加
/*  因为两个数相加最大位数 就为比较大的数的位数+1 */
void charadd(string& a, string& s)
{
	char m_data[10000] = {('0'-'0')};
	string a1(a.rbegin(), a.rend());
	string s1(s.rbegin(), s.rend());
	size_t size = a1.size() > s1.size() ? s1.size() : a1.size();
	int tempa, tempb, temp ,i;
	for (i = 0; i < size; i++)
	{
		temp = (a1[i] - '0') + (s1[i] - '0')+ m_data[i];
		m_data[i] = temp % 10;
		m_data[i + 1] = temp / 10;
	}
	string temps;
	if (a1.size() != s1.size())
	{
		if (a1.size() > s1.size())
		{
			 temps=a1;
		}
		if (s1.size() > a1.size())
			 temps=s1;
	}
	if (a1.size() != s1.size())
	{
		for (; i < size; i++)
		{
			temp = temps[i] + m_data[i];
			m_data[i] = temp % 10;
			m_data[i + 1] = temp / 10;
		}
	}
	for (; i>= 0; i--)
	{
		cout << m_data[i];
	}
}

/*
一个数组中，除了一个数字之外，每个数字都是两个，找出这个数

思路: 用异或运算，两次异或之后，结果变为0；
异或运算: 比较输入的两个数的每一位，如果该两位相同 那么就为 0；如果不相同 那么就为1；
所以两个数相互抵消了
*/

void singledog(vector<int> arr)
{
	int re=0;
	for (int i = 0; i < arr.size(); i++)
	{
		re ^= arr[i];
	}
	cout << re << endl;
}

/*
数组中有三个数字是相同的，只有一个数字是不同的找到这个数
思路: 将这些整数看成32位，每一位上都是1和0，竖着相加，如果为三的倍数，那么
这个数字在这一位上就是0，如果不是那么就是1
*/

void Threesingledog(vector<int> arr)
{
	int sum=0, count=0; //sum为打印值，count用于计数
	for (int i = 0; i < 32; i++)  //从第一位开始遍历
	{
		for (int j = 0; j < arr.size(); j++)
		{
			count += arr[j] >> i & 1;
		}
		if (count % 3)
		{
			sum = sum | (1 << i);
		}
		count = 0;
	}
	cout << sum << endl;
}

//电话号码组合

/*



*/

namespace _tmp
{
	string numLetter[] = { "abc", "def", "ghi", "jil", "mno", "pqrs", "tuv", "wxyz" };
}
void dealLetterCombinations(string &digits, size_t pos, vector<string> &alldata)
{
	static string res = digits; //没别的意思，只是为了中的size值得大小够 直接定义
	//res 那么res[]的操作将无法完成
	if (pos < digits.size())
	{
		for (auto &i : _tmp::numLetter[digits[pos] - '2'])
		{
			res[pos] = i;
			dealLetterCombinations(digits, pos + 1, alldata);
		}
	}
	else
	{
		alldata.push_back(res);
	}
}

vector<string> letterCombinations(string digits)
{
	vector<string> res;
	dealLetterCombinations(digits, 0, res);
	return res;
}

int main() {
	string digits("23");
	vector<string> data;
	data=letterCombinations(digits);
	for (auto& i : data)
	{
		cout << i << endl;
	}
	system("pause");
	return 0;
}