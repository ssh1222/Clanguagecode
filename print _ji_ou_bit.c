//#include<stdio.h>
//#include<stdlib.h>
//
////���ʵ������int��32λ������m��n�Ķ����Ʊ���У��ж��ٲ�ͬ�ģ�bit��
////�������ӣ�1999��2299�����Ϊ7
//
//int Print(int n, int m)
//{
//	int count = 0;
//	//��λ�����ͬΪ0����ͬΪ1��
//	int ret = n ^ m;
//	while (ret)
//	{
//		ret = ret & (ret - 1);
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	printf("%d\n", Print(1999, 2299));
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
////��ȡһ�������������������е�ż��λ������λ�� 
////�ֱ�������������С�
//void XuLie(int n)
//{
//	int i = 0;
//	for (i = 31; i > 0; i -= 2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//	printf("\n");
//	for (i = 30; i >= 0;i -= 2)
//	{
//		printf("%d ", (n >> i) & 1);
//	}
//}
//
//int main()
//{
//	XuLie(20);
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//
////дһ���������ز����������� 1 �ĸ��� ,���磺 15 0000 1111 4 �� 1
////����ԭ�ͣ�
////int count_one_bits(unsigned int value)
////{
////	// ���� 1��λ�� 
////}
//int count_one_bits(unsigned int value)
//{
//	int count = 0;
//	for (; value != 0; value >>= 1)
//	{
//		if (value & 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	printf("%d\n", count_one_bits(15));
//	system("pause");
//	return 0;
//}