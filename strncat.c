#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//2.ģ��ʵ��strncat

void* Mystrncat(char* dest, const char* src, size_t n)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;
	size_t i = 0;
	while (*++dest != '\0');
	for (i = 0; i < n; i++)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return ret;
}
int main()
{
	char dest[100] = "abcdef";
	char src[] = "123456";
	int n = 0;
	printf("����������ƴ�ӵ��ַ�������");
	scanf("%d", &n);
	Mystrncat(dest, src, n);
	printf("%s\n", dest);
	system("pause");
	return 0;
}