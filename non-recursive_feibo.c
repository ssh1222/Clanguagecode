#include<stdio.h>
#include<stdlib.h>

//非递归实现斐波那契数

int FeiBo(int n)
{
	int i = 0;
	int ret = 0;
	int n1 = 1;
	int n2 = 1;
	if (n == 1 || n == 2)
	{
		return 1;
	}
	for (i = 2; i < n; ++i)
	{
		ret = n2 + n1;
		n1 = n2;
		n2 = ret;
	}
	return ret;
}

int main()
{
	printf("%d\n", FeiBo(5));
	system("pause");
	return 0;
}