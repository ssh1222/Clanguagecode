#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

//�����ַ��������е������ַ�
void Swap(char* x, char* y)
{
	char tmp = *x;
	*x = *y;
	*y = tmp; 
}
void LeftMove(char arr[])
{
	int num = 0;
	int len = strlen(arr);
	printf("����������Ҫ�����ĸ�����");
	scanf("%d", &num);
	//������������
	num = num % 4;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < len - 1; j++)
		{
			//�����ַ��������ַ��͵ڶ����ַ������������½���
			Swap(&arr[j], &arr[j + 1]);
		}
	}
	printf("%s\n", arr);
}
int main()
{
	char arr[] = { "ABCD" };
	LeftMove(arr);
	system("pause");
	return 0;
}
