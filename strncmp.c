#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//3.模拟实现strncmp

int Mystrncmp(const char* dest,const char* src, size_t n)
{
	assert(dest != NULL);
	assert(src != NULL);
	int count = 0;
	while (count!=n)
	{
		if (*dest > *src)
		{
			return 1;
		}
		if (*dest < *src)
		{
			return -1;
		}
		dest++;
		src++;
		count++;
	}
	return 0;
	printf("%d\n", 0);
}
int main()
{
	char dest[] = "hello bit";
	char src[] = "hello world";
	int n = 0;
	printf("请输入你想比较字符的个数：");
	scanf("%d", &n);
	printf("%d\n", Mystrncmp(dest, src, n));
	system("pause");
	return 0;
}
