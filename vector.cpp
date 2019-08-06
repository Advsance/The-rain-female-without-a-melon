#include <iostream>
#include<algorithm>
using namespace std;
#include<vector>
#include<string>
#if 0


void test(vector<int> t)
{
	t.push_back(1);
	t.push_back(2);
	vector<int>::iterator it = t.begin();
	while (it!=t.end()) 
	{
		cout << *it << endl;
		it++;
	}
	it = t.begin();
	while (it!=t.end()) {
		*it = 520;
		it++;
	}
	it = t.begin();
	while (it != t.end())
	{
		cout << *it << endl;
		it++;
	}
	return ;
}
void VectorPrintf(vector<int> t) {
	vector<int>::iterator it = t.begin();
	while (it != t.end())
	{
		cout << *it << endl;
		it++;
	}
	return;
}
void test2(vector<int> t) {
	int a[] = { 1,2,3,4 };
	vector<int>	e(a, a + sizeof(a) / sizeof(int));
	VectorPrintf(e);
	vector<int>::iterator pos = find(e.begin(),e.end());
	return;
}
int main() 
{
	vector<int> t;
//	test(t);
	test2(t);
	system("pause");
	return 0;
}
#endif
int main()
{
	string A("adsfa");
	string B(A);
	cout << B<< endl;
	cout << A << endl;
	system("pause");
	return 0;
}