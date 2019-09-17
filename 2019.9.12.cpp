#include<iostream>
using namespace std;

void test1()
{
	int N;
	while (cin >> N)
	{
		int n1 = 1;
		int n2 = 1;
		int temp;
		for (int i = 1; i < N; i++)
		{
			temp = n1 + n2;
			n2 = n1;
			n1 = temp;
		}
		cout << n1 << endl;
	}
}

void bubbing(int* arr,int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j+1]);
		}
	}
}

void InsertSort(int* arr, int size)
{
	int temp;
	int end;   //定义一个待排数字前一个的位置,光用一个i的话无法表示
	for (int i = 0; i < size; i++)
	{
		temp = arr[i];
		end = i - 1;   
		while (end >= 0 && temp < arr[end])
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = temp;
	}
}

void ADjustDown(int* arr, int pRoot,int size)
{
	int child = pRoot * 2 + 1;
//	while (child < size&&child + 1 < size)  有问题如果只有一个左孩子那么循环进不去
	while(child<size)
	{
		if (child + 1 <size && arr[child] < arr[child+1])
		{
			child += 1;
		}
		if (arr[pRoot] < arr[child])
		{
			swap(arr[pRoot], arr[child]);
			pRoot = child;
			child = child * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

void HeapSort(int* arr, int size)
{
	int pRoot = ((size - 2) / 2);
	while (pRoot >= 0)
	{
		ADjustDown(arr, pRoot, size);
		pRoot--;
	}
	pRoot = size - 1;
	while (pRoot)
	{
		swap(arr[0], arr[pRoot]);
		ADjustDown(arr, 0, pRoot);
		pRoot -= 1;
	}
	
}
//选择排序 第一个位置放最大的 然后在最后挑到最后的位置
void ChooseSort(int * arr, int size)
{
	int max;
	for (int i = 0; i < size; i++)
	{
		max = 0;
		for (int j = 1; j < size - i-1 ; j++)
		{
			if (arr[j] > arr[max])
				swap(arr[max], arr[j]);
		}
		if (arr[size-i-1]<arr[max])
		{
			swap(arr[size-i-1],arr[max]);
		}
	}
}

void QuikSortS(int* arr, int left, int right)
{
	int i = left,
		j = right;
	if (left > right)
		return;
	while (i < j)
	{
		while (arr[j] > arr[left] && i < j)
			j--;
		while (arr[i] < arr[left] && i < j)
			i++;
		if (i < j)
			swap(arr[j], arr[i]);
	}
	swap(arr[left], arr[i]);
	QuikSortS(arr,left, i - 1);
	QuikSortS(arr,i + 1,right );
}

void QuikSort(int* arr, int size)
{
	QuikSortS(arr, 0, size - 1);
}

void Print(int* arr, int size)
{
	for (int i=0; i < size; i++)
	{
		cout << arr[i]<<"  ";
	}
}
int main()
{
	int arr[10] = { 1,3,4,2,0,8,9,7,5,6 };
//	bubbing(arr, 10);
//	InsertSort(arr, 10);
//	HeapSort(arr, 10);
//	ChooseSort(arr, 10);
	QuikSort(arr,10);
	Print(arr, 10);
	system("pause");
	return 0;
}