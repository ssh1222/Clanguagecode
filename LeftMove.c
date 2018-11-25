#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

//交换字符串数组中的两个字符
void Swap(char* x, char* y)
{
	char tmp = *x;
	*x = *y;
	*y = tmp; 
}
void LeftMove(char arr[])
{
	int num = 0;
	int len = strlen(arr);
	printf("请输入你想要左旋的个数：");
	scanf("%d", &num);
	//减少左旋次数
	num = num % 4;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < len - 1; j++)
		{
			//交换字符串的首字符和第二个字符，并依次往下交换
			Swap(&arr[j], &arr[j + 1]);
		}
	}
	printf("%s\n", arr);
}
int main()
{
	char arr[] = { "ABCD" };
	LeftMove(arr);
	system("pause");
	return 0;
}
