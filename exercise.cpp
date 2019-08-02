#if 0
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
int main() {
	int n;
	cin >> n;
	vector<int> A;
	A.resize(3 * n);
	for (int i = 0; i < 3 * n; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	long int sum = 0;
	for (int i = n; i < 3 * n - 1; i += 2)
	{
		sum += A[i];
	}
	cout << sum << endl;
	system("pause");
}
#endif
#include <iostream>
#include<string>
using namespace std;
int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	int temp[256] = { 0 };
	for (int i = 0; i < str2.size(); i++)
	{
		temp[str2[i]]++;
	}
	string put;
	for (int i = 0; i < str1.size(); i++)
	{
		if (temp[str1[i]] == 0)
		{
			put.push_back(str1[i]);
		}
	}
	cout << put << endl;
}
#include<vector>
int test()
{
	int n, num = 0;
	vector<int> A;
	cin >> n;
	A.resize(n + 1);
	A[n] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	int i = 0;
	while (i < n)
	{//Ôö¼Ó
		if (A[i] < A[i + 1])
		{
			while (i < n&&A[i] <= A[i + 1])
				i++;
			num++;
			i++;
		}
		if (A[i] > A[i + 1])
		{
			while (i < n &&A[i] >= A[i + 1])
				i++;
			num++;
			i++;
		}
		if (i < n&&A[i] == A[i + 1])
			i++;
	}
	cout << num;
	return 0;
}
#include<algorithm>
int test1() {
	string A;
	getline(cin, A);
	reverse(A.begin(), A.end());
	auto start = A.begin();
	while (start != A.end())
	{
		auto end = start;
		while (end != A.end() && * end != ' ')
		{
			end++;
		}
		reverse(start, end);
		if (end != A.end())
		{
			start = end + 1;
		}
		else
			start = end;
	}
	cout << A << endl;
}