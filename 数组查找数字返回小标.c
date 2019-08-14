#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main4() {
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int right = sizeof(arr)/sizeof(int);
	int left=0;
	int middle;
	int find;
	scanf("%d", &find);
	while (1)
	{
		middle = (left + right) / 2;
		if (find == arr[middle])
		{
			printf("%d", middle);
			break;
		}
		if (left == middle)
		{
			if (arr[right] == find)
			{
				printf("%d", right);
			}
			else
			{
				printf("没有这个数\n");
				break;
			}
		}
		if (arr[middle]>find)
		{
			right = middle;
		}
		if (arr[middle] < find)
		{
			left = middle;
		}
		if (left == right)
		{
			printf("没有找到\n");
			break;
		}
	}
	system("pause");
	return 0;
}
#if 0
用二分查找 将数组左右用数字表示起来找中间值，依次比较
值得注意的是如果最后一个区间值为2，那么得检测右值，不然会出现死循环
#endif 
