#include<stdio.h>
#include<stdlib.h>

//�ǵݹ�ʵ��n�Ľ׳�

int Factor(int n)
{
	int i = 0;
	int sum = 1;
	if (n == 0)
	{
		return 1;
	}
	for (i = 1; i <= n; i++)
	{
		sum *= i;
	}
	return sum;
}
int main()
{
	printf("%d\n", Factor(5));
	system("pause");
	return 0;
}