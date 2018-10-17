#include<stdio.h>
#include<stdlib.h>

//求两个数的最大公约数

int max_common_divisor(int x, int y)
{
	int i = 1;
	int max = 0;
	while(i <= x && i <= y)
	{
		if(x % i == 0 && y % i == 0)
		{
			max = i;
		}
		++i;
	}
	return max;
}
int main()
{
	int max = max_common_divisor(6, 9);
	printf("%d\n", max);
	system("pause");
	return 0;
}