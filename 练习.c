#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define student 10
#define book 1001
int mai11n() {
	int a,b;
	scanf("%d", &a);
	//b = sqrt(a);
	b = a*0.5 ;
	int max=1;
	for (int i = 1; i <= b; i++)
	{
		if (0==(a%i))
		{
			printf("%d\t",i);
			max = i;
		}
	}
	printf("最大公约数为%d", max);
	system("pause");
}

int main1113() {
	long int a, c, b, d;
	scanf("%d%d", &a, &c);
	for (long int i = 1; i <= a; i++)
	{
		b = a % i;
		if (b == 0)
		{


			for (long int o = 1; o <= c; o++)
			{
				d = c % o;
				if (d == 0)
				{


					if (i == o)
					{
						printf("公约数为%d",i);
					}
				}
			}
		}
	}
		system("pause");
	
}

void print(int A)
{
	for (int i = 1; i <= A; i++)
	{
		printf("*");
	}
	printf("\n");
}

int main22() {
	int a = 10;
	for (int i = 1; i <= 10; i++)
	{
		print(i);
	}
	for (int i = a; i >=0 ; i--)
	{
		print(i);
	}

	system("pause");
}

void fun(int i)
{
	int a, b, c;
	a = i /100;
	b = (i-a*100)/10;
	c = i-a*100- b * 10;
	if (i==(a*a*a+b*b*b+c*c*c))
	{
		printf("%d\n", i);
	}
}


int mai222n() {
	for (int i=100;i<999;i++)
	{
		fun(i);
	
	}

	system("pause");
}

void fun11(int* a, int*b)
{
	int *c;
	c = *a;

	*a =*b;
	*b =c;
	printf("%d %d",*a,*b);
}
	
int main11()
{
	int a = 1,
	b = 2;
	 fun11(&a,&b);
	printf("a=%d b=%d", a, b);
	system("pause");
}


//木桶排序法  啊哈 算法
int main木桶() {
	int arr[book] = { 0 };
	int t;
	for (int i = 0;i< student; i++)
	{
		scanf("%d",&t);
		arr[t]++;
	}
	for (int i = book-1;i>=0 ; i--)
	{
		for (int y = 0; y < arr[i]; y++)
		{
			printf("%d\t", i);
		}
	}
	system("pause");
}

struct Student
{
	char name[21];
	int score;
};

int main33() {
	struct Student arr[100] ,t;
	int i, n, j;
	printf("总人数：");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("第%d人名字",i+1);
		scanf("%s", arr[i].name);
		printf("成绩：");
		scanf("%d",&arr[i].score);
		//scanf("%s", arr[i].name);
	}
	printf("输入结果打印\n");
	for (int i = 0; i < n; i++)
	{
		printf("姓名为%s 成绩为%d\n", arr[i].name, arr[i].score);
	}
	for (int y = n-1; y >0; y--)
	{
		for (int i = 0; i < y; i++)
		{
			if (arr[i].score>arr[i+1].score)
			{

				t = arr[i+1];
				arr[i + 1] = arr[i];
				arr[i] = t;
			}
		}
	}
	printf("\n\n\n按照升序排列如下\n");

	for (int i = 0; i < n; i++)
	{
		printf("姓名为%s 成绩为%d\n", arr[i].name, arr[i].score);
	}
	system("pause");
}