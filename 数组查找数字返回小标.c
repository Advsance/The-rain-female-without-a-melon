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
				printf("û�������\n");
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
			printf("û���ҵ�\n");
			break;
		}
	}
	system("pause");
	return 0;
}
#if 0
�ö��ֲ��� ���������������ֱ�ʾ�������м�ֵ�����αȽ�
ֵ��ע�����������һ������ֵΪ2����ô�ü����ֵ����Ȼ�������ѭ��
#endif 
