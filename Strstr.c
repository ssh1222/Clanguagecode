#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//模拟实现strstr
//strstr表示查找一个字符串是否是另一个字符串的子集

int StrStr(const char* arr1, const char* arr2)
{
	int i = 0;
	int len = strlen(arr2);
	for (i = 0; i <= len; i++)
	{
		if (arr1[i] == arr2[i])
		{
			if (((arr1[i] == ' ') || (arr1[i] == '\0'))
				 && (arr2[i] == '\0'))
			{
				return 1;
			}
		}
	}
	return 0;
}
int Str(const char* arr1, const char* arr2)
{
	int i = 0;
	int len = strlen(arr1);
	for (i = 0; i < len; i++)
	{
		if (arr1[i] == arr2[0])
		{
			return StrStr(&arr1[i],arr2);
		}
	}
	return 0;
}

int main()
{
	char arr1[] = "hello world";
	char arr2[] = "world";
	int ret = Str(arr1,arr2);
	if (ret == 1)
	{
		printf("%s\n",arr2);
	}
	else
	{
		printf("没有找到！\n");
	}

	system("pause");
	return 0;
}

另一种方法：
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//实现strstr

char Mystrcmp(const char* p, const char* src)
{
	assert(p != NULL);
	assert(src != NULL);
	while ((*p != '\0') && (*src != '\0'))
	{
		if (*p < *src)
		{
			return -1;
		}
		else if (*p < *src)
		{
			return 1;
		}
		else
		{
			++p;
			++src;
		}
	}
	return 0;
}

//查找子字符串不考虑字符串的长度
const char* Mystrstr(const char*dest, const char*src)
{
	assert(dest != NULL);
	assert(src != NULL);
	const char* p = dest;
	for (; *p != '\0'; ++p)
	{
		if (Mystrcmp(p, src) == 0)
		{
			return p;
		}
	}
	return NULL;
}
int main()
{
	char dest[] = "hello world";
	char src[] = "hello";
	const char* p=Mystrstr(dest, src);
	printf("%p\n", dest);
	printf("%p\n", p);
	system("pause");
	return 0;
}