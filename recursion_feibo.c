#include<stdio.h>
#include<stdlib.h>

//递归实现求第n个斐波那契数。 
//斐波那契数是1,1,2,3,5...
//规律：前两两项之和等于后一项即n = (n - 1) + (n - 2)

int FeiBo(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	return FeiBo(n - 1)+FeiBo(n - 2);
}
int main()
{
	printf("%d\n", FeiBo(5));
	system("pause");
	return 0;
}