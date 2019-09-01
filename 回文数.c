#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//#include<assert.h>
#include<stdlib.h>
unsigned int reverse_bit(unsigned int value);
//回文数
int main11()
{
unsigned int  n, sn = 2;
	scanf("%u", &n);
	int  tmp, sum = 0;
	for (int i = 0; i<32;n/=sn,i++)
	{
		tmp = n% sn;
		sum = tmp + sum * sn;
	}
	printf("%u",sum );
	system("pause");
}

int main8() {
	int p=reverse_bit(25);
	printf("%u",p);
	system("pause");
}
unsigned int reverse_bit(unsigned int value) {
	int tep,tep1;
	int j, i;
	for (i = 0, j = 31; i < j; i++, j--) {
		tep =!!(value & 1 << i);  //注意！！ 在左移后不一定为1 还可能为2  4  8
		tep1 =!!(value & 1 << j); //等等 这样一来就会导致出错 两次取反 保证了值只为1
		value &= ~(1 << i);
		value &= ~(1 << j);
		value |= tep << j;
		value |= tep1 << i;
	}
	return value;
}

/*
1.编写函数：
unsigned int reverse_bit(unsigned int value);
这个函数的返回值value的二进制位模式从左到右翻转后的值。

如：
在32位机器上25这个值包含下列各位：
00000000000000000000000000011001
翻转后：（2550136832）
10011000000000000000000000000000
程序结果返回：
2550136832
*/