#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ʵ��strchr

int Chr(const char* arr1, char c)
{
	int i = 0;
	size_t len = strlen(arr1);
	for (i = len; i > 0; i--)
	{
		//�ж�����ҵ����ظ��ַ�
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
			//��ĩ�ε�һ����ͬλ
			if (arr1[i] == ret)
			{
				int j = i;
				int k = 0;
				//��ʣ���ַ�������arr2��
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