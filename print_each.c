#include<stdio.h>
#include<stdlib.h>

//递归方式实现打印一个整数的每一位 

void Print(int n)
{
	if (n > 9)
	{
		Print(n / 10);
	}
	printf("%d\n", n % 10);
}
int main()
{
	Print(1234);
	system("pause");
	return 0;
}