#include<stdio.h>
#include<stdlib.h>

//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832

unsigned int reverse_bit(unsigned int value)
{
	//定义变量value1，保存获取的value的值
	unsigned int value1 = 0;
	int i = 0;
	for (i = 0; i < 31; i++)
	{
		//正向获取25二进制中的值,
		if ((value >> i) & 1)
		{
			value1 = value1 | ((value >> i) & 1);
		}
		value1 <<= 1;
	}
	return value1;
}		
int main()
{
	//%u无符号的十进制
	//%d有符号的十进制
	printf("%u\n", reverse_bit(25));
	system("pause");
	return 0;
}