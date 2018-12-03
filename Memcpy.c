#include<stdio.h>
#include<stdlib.h>

//模拟实现memcpy
//从源src所指的内存地址的起始位置开始拷贝n个字节
//到目标dest所指的内存地址的起始位置中

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
另一种方法：
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//实现memcpy

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