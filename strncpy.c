#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//1.ģ��ʵ��strncpy

void* Mystrncpy(char* dest, char* src, size_t n)
{
	char* ret = dest;
	size_t i = 0;
	for (i = 0; i < n; i++)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return ret;
}
int main()
{
	char src[] = "abcdef";
	char dest[100] = { 0 };
	int n = 0;
	printf("���������븴���ַ��ĸ�����");
	scanf("%d", &n);
	Mystrncpy(dest, src, n);
	printf("%s\n", dest);
	system("pause");
	return 0;
}

