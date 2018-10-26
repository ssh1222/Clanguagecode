#include<stdio.h>
#include<stdlib.h>

//写代码可以在整型有序数组中查找想要的数字， 找到了返回下标，找不到返回 - 1.（折半查找）

int main()
{
	//定一个整形数组
	int arr[] = { 1, 2, 3, 4, 5 };
	//判断数组中元素的总数
	int to_find = 4;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int mid = 0;
	//判断是否查找到想要的数字
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (to_find < arr[mid])
		{
			right = mid - 1;
		}
		else if (to_find > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			break;
		}
	}
	if (left <= right)
	{
		printf("下表为 ：%d\n", mid);
	}
	else
	{
		printf("%d\n", -1);
	}
	system("pause");
	return 0;
}

