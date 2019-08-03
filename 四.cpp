#include <iostream>
using namespace  std;
//检测数组是否存在 且传进来的长度是否正常
//检测数组里面的值是否符合要求 
//进行交换

bool  duplicate(int arr[], int length, int* back)
{
	if (arr == nullptr || length<=0) 
	{
		return false;
	}
	for (int i = 0; i < length; i++)
	{
		if (arr[i] < 0 || arr[i]> length-1)
		{
			return false;
		}
	}
	for (int i = 0; i < length; ++i)
	{
		while (arr[i] != i)
		{
			if (arr[i] == arr[arr[i]])
			{
				*back = arr[i];
				return true;
			}
			int temp = arr[i];
			arr[i] = arr[temp];
			arr[temp] = temp;
		}
	}
//	return false;
}

bool duplicate1(int arr[],int length ,int* duplication)
{
	if (arr == nullptr || length <= 0)
	{
		return false;
	}
	for (int i = 0; i < length; i++)
	{
		if (arr[i]<0 || arr[i]>length - 1)
			return false;
	}
	for (int i = 0; i < length; i++)
	{
		while (arr[i]!=i)
		{
			if (arr[i] == arr[arr[i]])
			{
				*duplication = arr[i];
				return true;
			}
			int temp = arr[i];
			arr[i] = arr[arr[i]];
			arr[temp] = temp;
		}
	}
	return false;
}
// 2 3 4 2 5 3 6
int main() {
	int arr[] = { 1,2,3,4,};
	int C = 1;
	int* re=&C;
	int *it = &arr[0];
	//bool r= duplicate(arr, 10, re);
	for (int i = 1; i < 220000; i++)
	{
		cout <<*it << endl;
		it++;
	}
	cout << *re << endl;
	system("pause");
	return 0;
}