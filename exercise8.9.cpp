#include<iostream>
using namespace std;
#include<algorithm>
#include<string>
#if 0
bool isPrime(int num)
{
	int temp = sqrt(num);
	for (int i = 2; i < num; i++)
	{
		if (num%i == 0)
		{
			return false;
		}
	}
	return true;
}
int main() {
	int num,half;
	while (cin >> num)
	{
		half = num / 2;
		for (int i = 0; i < half; i++)
		{
			if (isPrime(half + i) && isPrime(half - i))
			{
				cout << half - i << endl;
				cout << half + i << endl;
				break;
			}
		}
	}
	system("pause");
	return 0;
}
#endif
#if 0



int main() {
	int n;
	while (cin >>n )
	{
		int count = 0;
		while (n)
		{
			if ((n & 1) == 1)
				count++;
			n >>= 1;
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}
#endif // 0

int main() {
	string srd;
	while (cin>>srd)
	{
		cout << srd << endl;
	}
	system("pause");
	return 0;
}