#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>

void FundSecoud()
{
	int n;
	vector<int> arr;
	int temp;
	long long sum ;
	while (cin >> n)
	{
		sum = 0;
		for (int i = 0; i < 3 * n; i++)
		{
			cin >> temp;
			arr.push_back(temp);
		}
		sort(arr.begin(), arr.end());
		for (int i = 0; i < n  ; i++)
		{
			sum += arr[arr.size() - (2 + i * 2)];
		}
		cout << sum << endl;
		arr.clear();
	}
}

#include<string>
void DelstrAToB()
{
	int hash[256] = { 0 };
	string B ;
	string A ;
	getline(cin, A);
	getline(cin, B);
	for (int i = 0; i < B.size(); i++)
	{
		hash[B[i]]++;
	}
	for (int i = 0; i < A.size(); i++)
	{
		if (hash[A[i]])
		{

		}
		else
		{
			cout << A[i];
		}
	}
}

int main2()
{
	DelstrAToB();
	system("pause");
	return 0;
}