#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//#include<assert.h>
#include<stdlib.h>
unsigned int reverse_bit(unsigned int value);
//������
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
		tep =!!(value & 1 << i);  //ע�⣡�� �����ƺ�һ��Ϊ1 ������Ϊ2  4  8
		tep1 =!!(value & 1 << j); //�ȵ� ����һ���ͻᵼ�³��� ����ȡ�� ��֤��ֵֻΪ1
		value &= ~(1 << i);
		value &= ~(1 << j);
		value |= tep << j;
		value |= tep1 << i;
	}
	return value;
}

/*
1.��д������
unsigned int reverse_bit(unsigned int value);
��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��

�磺
��32λ������25���ֵ�������и�λ��
00000000000000000000000000011001
��ת�󣺣�2550136832��
10011000000000000000000000000000
���������أ�
2550136832
*/