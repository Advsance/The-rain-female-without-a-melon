#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main00() {
	char password[30] = {0};
	printf("���������룺\n");
	int i;
	for ( i = 1; i <= 3; i++)
	{   
		scanf("%s", password);
		if (0==strcmp(password, "zhanglinsong"))   //strcmp�������ڱȽ������ַ��� ��ͬ����0��
		{
			break;
	    }
		else
		{
			printf("��������������룬��ʣ%d�λ���\n",3-i);
		}
	}
	if (i >= 4)
	{
		printf("��¼ʧ��\n");
	}
	if (i < 4)
	{
		printf("��½�ɹ�\n");
	}
	system("pause");
	return 0;
}