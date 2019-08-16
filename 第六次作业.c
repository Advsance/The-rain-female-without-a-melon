#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
 
void test6_1()
{
	int a;
	scanf("%d", &a);
	for (int i = 1; i <= a; i++)
	{
		for (int y = 1; y <= i; y++)
		{
			printf("%d*%d=%d    ", i, y, i*y);
		}
		printf("\n");
	}
}
void test6_2(int* a, int*b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main8()
{
	test6_1();
	int a = 2; int b = 3;
	test6_2(&a,&b);
	printf("a=%d,b=%d", a, b);
	system("pause");
	return 0;
}