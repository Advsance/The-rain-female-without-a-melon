#include<iostream>
using namespace std;
#include<vector>
int countRange(const vector<int>& arr, int start, int end);
int getDuplication(const vector<int>& arr)
{
	if (arr.size() == 0)
	{
		return -1;
	 }
	int start = 1;
	int end = arr.size() - 1;
	while (end >= start)
	{
		int middle = ((end - start) >> 1) + start;
		int count = countRange(arr, start, middle);
		if (end == start)
		{
			if (count > 1)
			{
				return start;
			}
			else
			{
				break;
			}
		}
		if (count > (middle - start + 1))
		{
			end = middle;
		}
		else
		{
			start = middle+1;
		}
	}
	return -1; //整数组中没有重复的
}

int countRange(const vector<int>& arr, int start, int end)
{
	int count = 0;
	for (auto& i : arr)
	{
		if (i <= end && i >= start)
		{
			count++;
		}
	}
	return count;
}

bool Find(const vector<vector<int>>& matrix, int number)
{
	int rows = 0;
	int columns = matrix[0].size()-1;
	while (rows<matrix.size()&&columns>=0)
	{
		if (matrix[rows][columns] == number)
		{
			return true;
		}
		if (matrix[rows][columns] > number)
		{
			columns--;
		}
		else
		{
			rows++;
		}
	}
	return false;
}


void mergeArr(int* arr1, int* arr2,int a1size,int a2size)
{
	int end = a2size + a1size - 1;
	a1size = a1size - 1;
	a2size = a2size - 1;
	while (a1size>=0&&a2size>=0)
	{
		if (arr1[a1size] > arr2[a2size])
		{
			arr1[end] = arr1[a1size];
			end--;
			a1size--;
		}
		else
		{
			arr1[end] = arr2[a2size];
			a2size--;
			end--;
		}
	}
	if (a2size >= 0)
	{
		while (a2size >= 0)
		{
			arr1[end] = arr2[a2size];
			end--;
			a2size--;
		}
	}
}

void test()
{
	const vector<int> arr = { 2,3,5,4,3,2,6,7 };
	int a = getDuplication(arr);
	cout << a << endl;
	const vector<vector<int>> arr1 = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
	bool T = Find(arr1, 0);
	cout << T << endl;
}
int main()
{
	int arr1[10] = { 1,2,3,4,5 };
	int arr2[10] = { 2,4,5,8,10 };
	mergeArr(arr1, arr2,5,5);
	for (int i = 0; i < 10; i++)
	{
		cout << arr1[i] << "  " << endl;
	}
	system("pause");
	return 0;
}