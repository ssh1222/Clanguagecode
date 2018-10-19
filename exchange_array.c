#include<stdio.h>
#include<stdlib.h>

//将数组A和数组B中的内容交换（数组一样大）

void Fun(char arr1[], char arr2[])
{
	int i = 0;
	for (i=0; i<4; i++)
	{
		//简单交换
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
	//输出字符串用%s
	printf("arr1 = %s arr2 = %s", arr1, arr2);
	printf("\n");
	system("pause");
	return 0;
}