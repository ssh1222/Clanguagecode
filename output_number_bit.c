#include<stdio.h>
#include<stdlib.h>

//дһ���������ز����������� 1 �ĸ��� ,���磺 15 0000 1111 4 �� 1
//����ԭ�ͣ�
//int count_one_bits(unsigned int value)
//{
//	// ���� 1��λ�� 
//}
int count_one_bits(unsigned int value)
{
	int count = 0;
	for (; value != 0; value >>= 1)
	{
		if (value & 1)
		{
			count++;
		}
	}
	return count;
}
int main()
{
	printf("%d\n", count_one_bits(15));
	system("pause");
	return 0;
}