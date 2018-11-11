#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//模拟实现strcmp

int Cmp(const char* arr1, const char* arr2)
{
	int i = 0;
	int len = 0;
	size_t len1 = strlen(arr1);
	size_t len2 = strlen(arr2);
	//判断哪个字符串长，使用长的做for循环条件
	if (len1 >= len2)
	{
		len = len1;
	}
	else
	{
		len = len2;
	}
	for (i = 0; i <= len; i++)
	{
		//若果两个字符相等，并且不为'\0',跳出本次循环
		if ((arr1[i] == arr2[i]) && (arr1[i] != '\0'))
		{
			continue;
		}
		//如果目标字符串arr2小于源字符串arr1返回-1
		if (arr1[i] > arr2[i])
		{
			return -1;
		}
		//如果同时到达'\0'，表示两个字符串相等
		if ((arr1[i] == '\0') && (arr2[i] == '\0'))
		{
			return 0;
		}
		//如果目标字符串arr2da于源字符串arr1跳出循环，返回1
		else
		{
			break;
		}			
	}
	return 1;
}
int main()
{
	char arr1[] = "hello world";
	char arr2[] = "hello";
	printf("%d\n", Cmp(arr1, arr2));
	system("pause");
	return 0;
}
另一种方法：
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//5.实现strcmp

char Mystrcmp(const char* dest, const char* src)
{
	while ((*dest != '\0') && (*src != '\0'))
	{
		if (*dest < *src)
		{
			return -1;
		}
		else if (*dest>*src)
		{
			return 1;
		}
		else
		{
			++dest;
			++src;
		}
	}
	if (*dest < *src)
	{
		return -1;
	}
	else if (*dest>*src)
	{
		return 1;
	}
	return 0;
}

int main()
{
	char dest[] = "hello world";
	char src[] = "hello";
	int ret = Mystrcmp(dest, src);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
