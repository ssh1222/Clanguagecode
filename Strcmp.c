#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ģ��ʵ��strcmp

int Cmp(const char* arr1, const char* arr2)
{
	int i = 0;
	int len = 0;
	size_t len1 = strlen(arr1);
	size_t len2 = strlen(arr2);
	//�ж��ĸ��ַ�������ʹ�ó�����forѭ������
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
		//���������ַ���ȣ����Ҳ�Ϊ'\0',��������ѭ��
		if ((arr1[i] == arr2[i]) && (arr1[i] != '\0'))
		{
			continue;
		}
		//���Ŀ���ַ���arr2С��Դ�ַ���arr1����-1
		if (arr1[i] > arr2[i])
		{
			return -1;
		}
		//���ͬʱ����'\0'����ʾ�����ַ������
		if ((arr1[i] == '\0') && (arr2[i] == '\0'))
		{
			return 0;
		}
		//���Ŀ���ַ���arr2da��Դ�ַ���arr1����ѭ��������1
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
��һ�ַ�����
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//5.ʵ��strcmp

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
