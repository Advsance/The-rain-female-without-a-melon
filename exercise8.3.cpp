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
	test();
	system("pause");
	return 0;
}