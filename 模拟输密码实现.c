#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main00() {
	char password[30] = {0};
	printf("请输入密码：\n");
	int i;
	for ( i = 1; i <= 3; i++)
	{   
		scanf("%s", password);
		if (0==strcmp(password, "zhanglinsong"))   //strcmp函数用于比较两个字符串 相同返回0；
		{
			break;
	    }
		else
		{
			printf("密码错误重新输入，还剩%d次机会\n",3-i);
		}
	}
	if (i >= 4)
	{
		printf("登录失败\n");
	}
	if (i < 4)
	{
		printf("登陆成功\n");
	}
	system("pause");
	return 0;
}