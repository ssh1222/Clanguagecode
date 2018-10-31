//#include<stdio.h>
//#include<stdlib.h>
//
////1.编写函数：
////unsigned int reverse_bit(unsigned int value);
////这个函数的返回值value的二进制位模式从左到右翻转后的值。
////
////如：
////在32位机器上25这个值包含下列各位：
////00000000000000000000000000011001
////翻转后：（2550136832）
////10011000000000000000000000000000
////程序结果返回：
////2550136832
//
//unsigned int reverse_bit(unsigned int value)
//{
//	//定义变量value1，保存获取的value的值
//	unsigned int value1 = 0;
//	int i = 0;
//	for (i = 0; i < 31; i++)
//	{
//		//正向获取25二进制中的值,
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
//	//%u无符号的十进制
//	//%d有符号的十进制
//	printf("%u\n", reverse_bit(25));
//	system("pause");
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
////2.不使用（a + b） / 2这种方式，求两个数的平均值。
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
////3.编程实现：
////一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
////请找出这个数字。（使用位运算）
//
//int main()
//{
//	int i = 0;
//	int arr[] = { 1, 2, 1, 3, 3, 5, 5 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	//自己与自己是相等的所以从第二个开始
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
////有一个字符数组的内容为:"student a am i",
////			请你将数组的内容改为"i am a student".
////			要求：
////			不能使用库函数。
////			只能开辟有限个空间（空间个数和字符串的长度无关）。
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
//	//逆序整个字符串
//	Exchange1(arr, arr + len - 1);
//	while (*arr)
//	{
//		start = arr;
//		//判断是否是一个单词
//		while ((*arr != ' ') && (*arr != '\0'))
//		{
//			arr++;
//		}
//		//找到空格
//		end = arr - 1;
//		//逆序单个单词
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