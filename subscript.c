#include<stdio.h>
#include<stdlib.h>

//д����������������������в�����Ҫ�����֣� �ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�

int main()
{
	//��һ����������
	int arr[] = { 1, 2, 3, 4, 5 };
	//�ж�������Ԫ�ص�����
	int to_find = 4;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int mid = 0;
	//�ж��Ƿ���ҵ���Ҫ������
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
		printf("�±�Ϊ ��%d\n", mid);
	}
	else
	{
		printf("%d\n", -1);
	}
	system("pause");
	return 0;
}

