#include<stdio.h>
#include<stdlib.h>

//��дһ������n^k��ʹ�õݹ�

int Fun(int n, int k)
{
	if(n < 1)
	{
		return 0;
	}
	else if (k == 1)
	{
		return n;
	}
	else
	{
		return n*Fun(n, k - 1);
	}
}
int main()
{
	int ret = Fun(5,5);
	printf("%d\n", ret);
	system("pause");
	return 0;
}