#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//队列的数组实现
int mainf() {
	int q[101] = {0,6,3,1,7,5,8,9,2,4};
	int head = 1, tail = 10;
	while (head<tail)
	{
		printf("%d ", q[head]);
		head++;
		q[tail] = q[head];
		tail++;
		head++;
	}
	system("pause");
	return 0;
}


//结构体队列实现
struct queue
{
	int data[100];
	int head;
	int tail;
}*x;
int main2() 
{
	struct queue q ;
//	struct queue* x=&q;
	x = &q;
	x->head = 0;
	x->tail = 0;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &x->data[x->tail]);
		x->tail++;
	}
	while (x->head<x->tail)
	{
		printf("%d", x->data[x->head]);
		x->head++;
		x->data[x->tail] = x->data[x->head];
		x->tail++;
		x->head++;
	}


	system("pause");
}

#if 0


int main(){
	struct queue q;
	//	struct queue* x=&q;
	x = &q;
	x->head = 0;
	x->tail = 0;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &x->data[x->tail]);
		x->tail++;
	}
	while (q.head<q.tail)
	{
		printf("%d", q.data[q.head]);
		q.head++;
		q.data[q.tail] = q.data[q.head];
		q.head++, q.tail++;
	}
	system("pause");
}
#endif


int a[101], n;

void quicksork(int left, int right)
{
	int i, j, t, temp;
	if (left > right)
		return;
	temp = a[left];
	i = left;
	j = right;
	while (i != j)
	{
		while (a[j] >= temp && i < j)
			j--;
		while (a[i] <= temp && i < j)
			i++;
		if (i < j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[left] = a[i];
	a[i] = temp;
	quicksork(left, i - 1);
	quicksork(i + 1, right);
}

int main()
{
	int i,j,k;
	srand((unsigned int)time(0));
	for (i = 1; i < 101; i++)
	{
		a[i] = rand() % 100 + 1;
	}
	quicksork(1, 101);
	for (i = 1; i < 101; i++)
	{
		printf("%d\n", a[i]);
	}
	system("pause");
}
