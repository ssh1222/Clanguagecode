#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//编写代码模拟三次密码输入的场景。 
//最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，
//可以重新输入，最多输入三次。三次均错，则提示退出程序。

int main()
{
	int i = 0;
	for (i = 1; i < 4; ++i)
	{
		char password[] = { 0 };
		printf("请输入密码：");
		scanf("%s", password);
		//比较字符串的内容是否相同，需要比较每一个字符，都相等才相等
		//字符串也能比较到小
		//依次取两个字符串相应的字符，如果两个字符能比较出大小，字符串大小也就确定了
		//如果两个字符比较不出大小，依次取下一个字符比较
		//简称“字典序”
		if (strcmp(password, "1222") == 0)
		{
			printf("登录成功!\n");
			break;
		}
	}
	if (i == 4)
	{
		printf("三次登陆失败，禁止登录！\n");
	}
	system("pause");
	return 0;
}