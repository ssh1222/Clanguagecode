#include<stdio.h>
#include<stdlib.h>

//������A������B�е����ݽ���������һ����

void Fun(char arr1[], char arr2[])
{
	int i = 0;
	for (i=0; i<4; i++)
	{
		//�򵥽���
		int tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
}

int main()
{
	char arr1[] = {"abcd"};
	char arr2[] = {"dcba"};
	Fun(arr1, arr2);
	//����ַ�����%s
	printf("arr1 = %s arr2 = %s", arr1, arr2);
	printf("\n");
	system("pause");
	return 0;
}