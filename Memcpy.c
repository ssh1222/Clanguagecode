#include<stdio.h>
#include<stdlib.h>

//ģ��ʵ��memcpy
//��Դsrc��ָ���ڴ��ַ����ʼλ�ÿ�ʼ����n���ֽ�
//��Ŀ��dest��ָ���ڴ��ַ����ʼλ����

void MemCpy(const char* src, char* dest, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	printf("%s\n", dest);
}
int main()
{
	char src[] = "hello world";
	char dest[1024] = { 0 };
	int n = 5;
	MemCpy(src, dest, n);
	system("pause");
	return 0;
}
��һ�ַ�����
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//ʵ��memcpy

void* Mymemcpy(void* dest, const void* src, size_t num)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* ret = dest;
	for (size_t i = 0; i < num; i++)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}
int main()
{
	char dest[10] = { 0 };
	char src[] = "abcdef";
	Mymemcpy(dest, src, sizeof(src));
	printf("%s\n", dest);
	system("pause");
	return 0;
}