#include <iostream>
using namespace std;
#if 0
int fun(int n)
{
	if (n < 3)                        //ÔËÓÃµÝ¹é¼ÆËã
		return 1;
	return fun(n - 1) + fun(n - 2);
}
int main() {
	int month;
	while (cin >> month) {
		int first = 1;
		int second = 1;
		int result = 2;
		int temp;
		for (int i = 0; i < month - 3; i++)
		{
			temp = result;
			result = result + second;
			first = second;
			second = temp;
		}
		cout << result << endl;
	}
	return 0;
}
#endif