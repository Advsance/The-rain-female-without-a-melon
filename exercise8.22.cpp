#include<iostream>
using namespace std;
#include<time.h>
#define BUFFSIZE 100

void printfe(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "     ";
	}
}
void Insertsort(int* arr, int n)  //≤Â»Î≈≈–Ú
{
	int i, j;
	int temp;
	for (i = 1; i < n; i++)
	{
		temp = arr[i];
		for (j = i; temp < arr[j - 1] && j>0; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = temp;
	}
}
void fun(int* arr, int n)   //√∞≈∆≈≈–Ú
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i-1; j++)
		{
			if (arr[j + 1] <= arr[j])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main()
{
	srand(time(NULL));
	int arr[BUFFSIZE];
	for (int i = 0; i < BUFFSIZE; i++)
	{
		arr[i] = rand() % 7000 + 1;
	}	
	Insertsort(arr, BUFFSIZE);
	fun(arr, BUFFSIZE);
	printfe(arr, BUFFSIZE);
	system("pause");
	return 0;
}


struct A { 
unsigned a : 19;
unsigned b : 11;
unsigned c : 3;
unsigned d : 3;
//char index; 
};

int main1()
{
	A A1;
	unsigned d =3000000000;
	cout << sizeof(A1) << endl;
	cout << sizeof(d) << endl;
	cout << d << endl;
	system("pause");
	return 0;
}