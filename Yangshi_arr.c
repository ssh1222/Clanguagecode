//#include<stdio.h>
//#include<stdlib.h>
//
////1.��д������
////unsigned int reverse_bit(unsigned int value);
////��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
////
////�磺
////��32λ������25���ֵ�������и�λ��
////00000000000000000000000000011001
////��ת�󣺣�2550136832��
////10011000000000000000000000000000
////���������أ�
////2550136832
//
//unsigned int reverse_bit(unsigned int value)
//{
//	//�������value1�������ȡ��value��ֵ
//	unsigned int value1 = 0;
//	int i = 0;
//	for (i = 0; i < 31; i++)
//	{
//		//�����ȡ25�������е�ֵ,
//		if ((value >> i) & 1)
//		{
//			value1 = value1 | ((value >> i) & 1);
//		}
//		value1 <<= 1;
//	}
//	return value1;
//}		
//int main()
//{
//	//%u�޷��ŵ�ʮ����
//	//%d�з��ŵ�ʮ����
//	printf("%u\n", reverse_bit(25));
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
////2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
//
//int main()
//{
//	int a = 10;
//	int b = 21;
//	double average = 0;
//	if ((a + b) % 2 == 0)
//	{
//		average = (a + b) >> 1;
//	}
//	average = ((a + b) >> 1) + 0.5;
//	printf("%lf\n", average);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
////3.���ʵ�֣�
////һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
////���ҳ�������֡���ʹ��λ���㣩
//
//int main()
//{
//	int i = 0;
//	int arr[] = { 1, 2, 1, 3, 3, 5, 5 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	//�Լ����Լ�����ȵ����Դӵڶ�����ʼ
//	for (i = 1; i < len; i++)
//	{
//		arr[0] = arr[0] ^ arr[i];
//	}
//	printf("%d\n", arr[0]);
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
////��һ���ַ����������Ϊ:"student a am i",
////			���㽫��������ݸ�Ϊ"i am a student".
////			Ҫ��
////			����ʹ�ÿ⺯����
////			ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
//
//void Exchange1(char* left, char* right)
//{
//	char tmp = 0;
//	while (left < right)
//	{
//		tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void Exchange(char arr[])
//{
//	int len = strlen(arr);
//	char* start = arr;
//	char* end = NULL;
//	char* ret = arr;
//	//���������ַ���
//	Exchange1(arr, arr + len - 1);
//	while (*arr)
//	{
//		start = arr;
//		//�ж��Ƿ���һ������
//		while ((*arr != ' ') && (*arr != '\0'))
//		{
//			arr++;
//		}
//		//�ҵ��ո�
//		end = arr - 1;
//		//���򵥸�����
//		Exchange1(start, end);
//		if (*arr == ' ')
//		{
//			arr++;
//		}
//	}
//	printf("%s\n", ret);
//}
//int main()
//{
//	char arr[] = "student a am i";
//	Exchange(arr);
//	system("pause");
//	return 0;
//}