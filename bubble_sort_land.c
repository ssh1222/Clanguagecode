#include<stdio.h>
#include<stdlib.h>

//ð������
//��������

//��������������ֵ
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void bubble_sort(int arr[], int size)
{
	//bound�߽�
	//�γ���������[bound,size],[i,bound]
	int bound = 0;
	int i = 0;
	for(bound = 0; bound < size; bound++)
	{
		for(i = 0; i < bound ; i++)
		{
			//�ж�ǰ���������Ĵ�С����������
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
	//������ĳ���
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