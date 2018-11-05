//#include<stdio.h>
//#include<stdlib.h>
//
////编程实现两个int（32位）整形m和n的二进制表达中，有多少不同的（bit）
////输入例子：1999和2299，输出为7
//
//int Print(int n, int m)
//{
//	int count = 0;
//	//按位异或：相同为0，不同为1；
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
////获取一个数二进制序列中所有的偶数位和奇数位， 
////分别输出二进制序列。
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
////写一个函数返回参数二进制中 1 的个数 ,比如： 15 0000 1111 4 个 1
////程序原型：
////int count_one_bits(unsigned int value)
////{
////	// 返回 1的位数 
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