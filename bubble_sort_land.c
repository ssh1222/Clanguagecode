#include<stdio.h>
#include<stdlib.h>

//冒泡排序
//降序排列

//交换两个变量的值
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void bubble_sort(int arr[], int size)
{
	//bound边界
	//形成连个区间[bound,size],[i,bound]
	int bound = 0;
	int i = 0;
	for(bound = 0; bound < size; bound++)
	{
		for(i = 0; i < bound ; i++)
		{
			//判断前后两个数的大小，进行排序
			if(arr[i] < arr[i + 1])
			{
				swap(&arr[i], &arr[i+1]);
			}
		}
	}
}
int main()
{
	int i = 0;
	int arr[] = {5, 1 ,2};
	//求数组的长度
	int len = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, len);
	for(i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}