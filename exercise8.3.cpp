#if 0
#include<iostream>
using namespace std;
#include<string>
bool PalindromeString(string str) {
	size_t begin=0;
	size_t end=str.size()-1;
	while (begin <= end)
	{
		if (str[begin] != str[end])
		{
			return false;
		}
		begin++;
		end--;
	}
	return true;
}
class Solution {
public:
	int StrToInt(string str) {
		int i;
		if (str[0] = '-')
		{
			i = -1;
		}
		if (str[0] = '+')
		{
			i = 1;
		}
		int sum = 0;
		int temp = 0;
		for (int y = 1; y < str.size();i++)
		{
			if ('0' = < str[y] <= '9')
			{
				temp = str[y];
			}
			else
				return 0;
			if (int x = y + 1; x < str.size();)
			{
				sum = sum * 10 + temp;
			}
		}
		return sum * i;
	}
};
void test()
{
	string strA,strB,strtemp;
	getline(cin, strA);
	getline(cin, strB);
	size_t count = 0;
	for (int i = 0; i <= strA.size(); i++)
	{
		strtemp = strA;
		strtemp.insert(i, strB);
		if (PalindromeString(strtemp))
			count++;
	}
	cout << count << endl;
}
int main() {
	//test();
	string b = "231";
	Solution a;
	int x = a.StrToInt(b);
	cout << x << endl;
	system("pause");
	return 0;
}
#endif