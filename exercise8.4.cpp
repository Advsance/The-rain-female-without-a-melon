#include<iostream>
using namespace std;
#include<string>
#if 0
class Solution {
public:
	int StrToInt(string str) {
		if (str.empty())
			return 0;
		int i=1;
		if (str[0] == '-')
		{
			i = -1;
			str[0] = '0';//如果前面有符号就可以保证后面的操作不会收到影响
		}
		if (str[0] == '+')
		{
			i = 1;
			str[0] = '0';
		}
		int sum = 0;
		int temp = 0;
		for (int y = 0; y < str.size(); y++)
		{
			if ('0' <= str[y]&&str[y] <= '9')
			{
				temp = str[y] - '0';
			}
			else
			{
				temp = 0;
				break;
			}
			sum = sum * 10 + temp;
			
		}
		return sum * i;
	}
};
int main() {
	string A = "j1232";
	Solution B;
	int s = B.StrToInt(A);
	cout << s << endl;
	system("pause");
	return 0;
}
#endif
#include<vector>
#if 0
int main()
{
	int w, h, res = 0;
	cin >> w >> h;
	vector<vector<int>> a;
	a.resize(w);
	for (auto& s : a)
		s.resize(h, 1);
	for (int i = 0; i < w; i++)
	{
		for (int y = 0; y < h; y++)
		{
			if (a[i][y] == 1)
			{
				res++;
				if((i+2)<w)
				a[i + 2][y] = 0;
				if ((y+2)<h)
				{
					a[i][y + 2] = 0;
				}
			}
		}
	}
	cout << res;
}
#endif