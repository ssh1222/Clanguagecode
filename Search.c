#include<stdio.h>
#include<stdlib.h>

//1.һ��������ֻ�����������ǳ���һ�Σ�
//�����������ֶ����������Ρ�
//�ҳ����������֣����ʵ�֡�

void Search(int arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		//�����ķ���
		//���ֻ��һ������count=1�����count=1��Ӧ��arr��ֵ
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