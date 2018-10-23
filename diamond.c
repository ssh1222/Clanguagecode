#include<stdio.h>
#include<stdlib.h>

//在屏幕上输出一个像菱形的图案

void PrintLine(int blank_count, int star_count)
{
	int i = 0;
	for (i = 1; i <= blank_count; i++)
	{
		printf(" ");
	}
	for (i = 1; i <= star_count; i++)
	{
		printf("*");
	}
	printf("\n");
}

void PrintDiamond(int n)
{
	//菱形是十字对称的，定义最长的一行为n
	int i = 0;
	//根据n来划分整个菱形：上半部分、中间部分、下半部分
	//上班部分
	for (i = 1; i < n; i++)
	{
		PrintLine(n - i, 2 * i - 1);
	}
	//中间部分
	PrintLine(0, 2 * n - 1);
	//下半部分
	for (i = n - 1; i > 0; i--)
	{
		PrintLine(n - i, 2 * i - 1);
	}
}

//菱形图案由' '和'*'组成，重上到下打印这两个符号
int main()
{
	//定义一个菱形函数
	PrintDiamond(7);
	system("pause");
	return 0;
}
