#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//实现strchr

int Chr(const char* arr1, char c)
{
	int i = 0;
	size_t len = strlen(arr1);
	for (i = len; i > 0; i--)
	{
		//判断如果找到返回该字符
		if (arr1[i] == c)
		{
			return arr1[i];
			break;
		}
	}
	return 0;
}
int main()
{
	char arr1[] = "hello";
	char arr2[100] = { 0 };
	char c = 'e';
	int ret = Chr(arr1, c);
	int len = strlen(arr1);
	if (ret != 0)
	{
		int i = 0;
		for (i = len; i >= 0; --i)
		{
			//找末次第一个相同位
			if (arr1[i] == ret)
			{
				int j = i;
				int k = 0;
				//将剩余字符拷贝到arr2中
				for (; j >= 0; j--)
				{
					arr2[k] = arr1[j];
					k++;
				}
			}
		}
		printf("%s\n", arr2);
	}
	else
	{
		printf("%d\n",ret);
	}
	system("pause");
	return 0;
}