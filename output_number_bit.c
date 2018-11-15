#include<stdio.h>
#include<stdlib.h>

//写一个函数返回参数二进制中 1 的个数 ,比如： 15 0000 1111 4 个 1
//程序原型：
//int count_one_bits(unsigned int value)
//{
//	// 返回 1的位数 
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