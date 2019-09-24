#include<iostream>
#include<vector>
//����һ���ַ���
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

void reverseWord(string& s) //�ַ�����ת
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
	reverseOneWord(s, 0, s.find(' ') - 1);  // find ���û�ҵ��᷵��һ��-1; Ӧ��Ϊһ��size_t���͵�����
	reverseOneWord(s, 0, s.find(' ') - 1);
	int start = 0;
	int end = s.find(' ')-1;
	while (start < end && end > 0)
	{
		reverseOneWord(s, start, end);
		start = end + 2;
		end = s.find(' ', start)-1;  //start����ʼѰ��
	}
	//��ʱ�������һ���ַ����Ѿ�����
	reverseOneWord(s, start, s.size() - 1);
	cout << s << endl;

}

//�ַ������
/* ���ݿ����ȵ��Ŵ棬�������ӷ���Щ��Ȼ���Ŵ�ӡ����   */
void charmuit(string& a, string& s)
{

}

//�ַ������
/*  ��Ϊ������������λ�� ��Ϊ�Ƚϴ������λ��+1 */
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
һ�������У�����һ������֮�⣬ÿ�����ֶ����������ҳ������

˼·: ��������㣬�������֮�󣬽����Ϊ0��
�������: �Ƚ��������������ÿһλ���������λ��ͬ ��ô��Ϊ 0���������ͬ ��ô��Ϊ1��
�����������໥������
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
��������������������ͬ�ģ�ֻ��һ�������ǲ�ͬ���ҵ������
˼·: ����Щ��������32λ��ÿһλ�϶���1��0��������ӣ����Ϊ���ı�������ô
�����������һλ�Ͼ���0�����������ô����1
*/

void Threesingledog(vector<int> arr)
{
	int sum=0, count=0; //sumΪ��ӡֵ��count���ڼ���
	for (int i = 0; i < 32; i++)  //�ӵ�һλ��ʼ����
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

//�绰�������

/*



*/

namespace _tmp
{
	string numLetter[] = { "abc", "def", "ghi", "jil", "mno", "pqrs", "tuv", "wxyz" };
}
void dealLetterCombinations(string &digits, size_t pos, vector<string> &alldata)
{
	static string res = digits; //û�����˼��ֻ��Ϊ���е�sizeֵ�ô�С�� ֱ�Ӷ���
	//res ��ôres[]�Ĳ������޷����
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