#include<iostream>
#include<vector>
using namespace std;
#include<stack>
void PrintCirle(vector<vector<int>>& arr,  int stant,vector<int>& re);
void PrintRowCol(vector<vector<int>>& arr)
{
	int stant = 0;
	vector<int> re;
	while ((arr.size() > (2 * stant)) && (arr[0].size() > (2 * stant)))
	{
		PrintCirle(arr, stant,re);
		stant++;
	}
	
}

void PrintCirle(vector<vector<int>>& arr, int stant,vector<int>& re)
{
	size_t max_x = arr[0].size()-1-stant ;
	size_t max_y = arr.size() - 1-stant;
	for (int i = stant; i <= max_x; i++)
	{
		re.push_back(arr[stant][i]) ;
	}
	if (stant < max_y)
	{
		for (int i = stant + 1; i <= max_y; i++)
		{
			re.push_back(arr[i][max_x] );
		}
	}
	if (stant < max_x&&stant < max_y)
	{
		for (int i = max_x - 1; i >= stant; i--)
		{
			re.push_back(arr[max_y][i]);
		}
	}
	if (stant < max_x&&stant < max_y -1)
	{
		for (int i = max_y - 1; i >= stant + 1; --i)
		{
			re.push_back( arr[i][stant]);
		}
	}

}
int main()
{
	vector<vector<int>> arr = { {1,2,3,4,5},{12,13,14,12,11} };
	//cout << sizeof(arr) << endl;
//	PrintCirle(arr, 0);
	PrintRowCol(arr);
//	Print();
	system("pause");
}




//最小栈的封装
class Solution {
	stack<int> base;
	stack<int> min1;
public:
	void push(int value) {
		base.push(value);
		if (min1.empty() || min1.top() > value)
		{
			min1.push(value);
		}
		else
		{
			min1.push(min1.top());
		}
	}
	void pop() {
		if (!base.empty())
		{
			base.pop();
			min1.pop();
		}
	}
	int top() {
		return base.top();
	}
	int min() {
		return min1.top();
	}
};