#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Game();
void meuns(){
	printf("===================\n");
	printf("=====请输入选择====\n");
	printf("1.开始游戏\n");
	printf("2.结束游戏\n");
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
			printf("输入有误\n");
		}
	}
	}
void Game() {
	srand((unsigned int) time(0));
	int Random_Numb = rand() % 100 + 1;
	printf("请输入所猜的数字；\n");
	int temp ,time=0;
	while (1)
	{
		scanf("%d", &temp);
		if (temp == Random_Numb)
		{
			time++;
			printf("猜对了，一共猜了%d次\n", time);
			return;
		}
		if (temp > Random_Numb)
		{
			printf("猜大了\n");
			++time;
		}
		if(temp<Random_Numb)
		{
			printf("猜小了\n");
			++time;
		}
	}
}
int main() {
	char password[30] = { 0 };
	printf("请输入密码：\n");
	int i;
	for (i = 1; i <= 3; i++)
	{
		scanf("%s", password);
		if (0 == strcmp(password, "zhanglinsong"))   //strcmp函数用于比较两个字符串 相同返回0；
		{
			break;
		}
		else
		{
			printf("密码错误重新输入，还剩%d次机会\n", 3 - i);
		}
	}
	if (i >= 4)
	{
		printf("登录失败\n");
		return 0;
	}
	if (i < 4)
	{
		printf("登陆成功\n");
	}
	
	
	meuns();
	system("pause");
	return 0;
}
#if 0
生成随机数 rand()  头文件 <stdilb.h>
www.cplusplus.com
返回的值为 0 到 RAND_MAX(根据库不同值不同 一般32767)
每次生成的随机数的序列都相同, 伪随机
可以改变随机种子的值从而改变随机值 通过srand改变
srand(0);随机种子给值给常数的话 生成的随机种子值还是相同
计算机时间戳 long int time_t 从1970年1月1号0点0分作为基准时刻
结束于 
#endif  