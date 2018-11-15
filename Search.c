#include<stdio.h>
#include<stdlib.h>

//1.一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个数字，编程实现。

void Search(int arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		//计数的方法
		//如果只有一个数，count=1，输出count=1对应的arr的值
		int count = 0;
		for (int j = 0; j < len; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
		}
		if (count == 1)
		{
			printf("%d ", arr[i]);
		}
	}
	printf("\n");
}
int main()
{
	int arr[] = { 1, 2, 3, 7, 4, 1, 2, 4, 5, 7, 6, 5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Search(arr,len);
	system("pause");
	return 0;
}