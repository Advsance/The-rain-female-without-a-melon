#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main20() {
	int a[10] = {0}, total = 0, book[10], num;
	for (a[1] = 1; a[1] <= 9; a[1]++)
	{
		for (a[2] = 1; a[2] <= 9; a[2]++)
		{
			for (a[3] = 1; a[3] <= 9; a[3]++)
			{
				for (a[4] = 1; a[4] <= 9; a[4]++)
				{
					for (a[5] = 1; a[5] <= 9; a[5]++)
					{
						for (a[6] = 1; a[6] <= 9; a[6]++)
						{
							for (a[7] = 1; a[7] <= 9; a[7]++)
							{
								for (a[8] = 1; a[8] <= 9; a[8]++)
								{
									for (a[9] = 1; a[9] <= 9; a[9]++)
									{
										for (int i = 0; i < 10; i++)
										{
											book[i] = 0;
										}
										for (int i = 0; i < 10; i++)
										{
											book[a[i]] = 1;
										}
										num = 0;
										for (int i = 1; i < 10; i++)
										{
											num += book[i];
										}
										if ((num == 9) && a[1] * 100 + a[2] * 10 + a[3] + a[4] * 100 + a[5] * 10 + a[6] == a[7] * 100 + a[8] * 10 + a[9])
										{
											total++;
											printf("%d%d%d+%d%d%d=%d%d%d\n", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("Ò»¹²%d×é", total/2);
	system("pause");
	return 0;
}
void fun(int* a, int* b) {
	int C = *a;
	*a = *b;
	*b = C;
	printf("%d\n", *a);
}

int main555() {
	int a = 1, b = 2;
	fun(&a , &b);
	printf("a=%d    b=%d", a, b);
	system("pause");
	return 0;
}