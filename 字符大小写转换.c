#include<stdio.h>
int main0()
{
	while (1)
	{
		printf("��������Ҫת������ĸ\n");
		char ch = getchar();
		if(ch>=97&&ch<=122)
		printf("%c\n",ch-32 );
		if(ch>=65&&ch<=90)
		printf("%c\n", ch + 32);
	}
	return 0;
}