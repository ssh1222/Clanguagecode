#include<stdio.h>
#include<stdlib.h>

//编写一个程序，可以一直接收键盘字符， 
//如果是小写字符就输出对应的大写字符，
//如果接收的是大写字符，就输出对应的小写字符，
//如果是数字不输出。

int main()
{
	int letter = 0;
	printf("输入一个键盘的字符：");
	//获取一个字符getchar
	letter = getchar();
	if (letter >= 'a' && letter <= 'z')
	{
		//putchar输出一个字符
		putchar(letter - 32);
	}
	else if (letter >= 'A' && letter <= 'Z')
	{
		putchar(letter + 32);
	}
	if (0 <= letter <= 9)
		{
			;//不输出
		}
	printf("\n");
	system("pause");
	return 0;
}

