#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Game();
void meuns(){
	printf("===================\n");
	printf("=====������ѡ��====\n");
	printf("1.��ʼ��Ϸ\n");
	printf("2.������Ϸ\n");
	int choice=0;
	while (1)
	{
		scanf("%d", &choice);
		if (choice == 1)
		{
			Game();
		}
		else if (choice == 2)
		{
			printf("good bye\n");
			return;
		}
		if (choice != 1 || choice != 2)
		{
			printf("��������\n");
		}
	}
	}
void Game() {
	srand((unsigned int) time(0));
	int Random_Numb = rand() % 100 + 1;
	printf("���������µ����֣�\n");
	int temp ,time=0;
	while (1)
	{
		scanf("%d", &temp);
		if (temp == Random_Numb)
		{
			time++;
			printf("�¶��ˣ�һ������%d��\n", time);
			return;
		}
		if (temp > Random_Numb)
		{
			printf("�´���\n");
			++time;
		}
		if(temp<Random_Numb)
		{
			printf("��С��\n");
			++time;
		}
	}
}
int main() {
	char password[30] = { 0 };
	printf("���������룺\n");
	int i;
	for (i = 1; i <= 3; i++)
	{
		scanf("%s", password);
		if (0 == strcmp(password, "zhanglinsong"))   //strcmp�������ڱȽ������ַ��� ��ͬ����0��
		{
			break;
		}
		else
		{
			printf("��������������룬��ʣ%d�λ���\n", 3 - i);
		}
	}
	if (i >= 4)
	{
		printf("��¼ʧ��\n");
		return 0;
	}
	if (i < 4)
	{
		printf("��½�ɹ�\n");
	}
	
	
	meuns();
	system("pause");
	return 0;
}
#if 0
��������� rand()  ͷ�ļ� <stdilb.h>
www.cplusplus.com
���ص�ֵΪ 0 �� RAND_MAX(���ݿⲻֵͬ��ͬ һ��32767)
ÿ�����ɵ�����������ж���ͬ, α���
���Ըı�������ӵ�ֵ�Ӷ��ı����ֵ ͨ��srand�ı�
srand(0);������Ӹ�ֵ�������Ļ� ���ɵ��������ֵ������ͬ
�����ʱ��� long int time_t ��1970��1��1��0��0����Ϊ��׼ʱ��
������ 
#endif  