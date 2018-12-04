#include<stdio.h>
#include<stdlib.h>

#define Y 1

//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以多少汽水。
//编程实现。

int Number(int n)
{
	int i = 0;
	int count = 0;
	while (n / 2 != 0)
	{
		n = n / 2;
		count++;
	}
	return count;
}
void SteamWater(int n)
{
	int sum = 0;
	int sum1 = 0;
	//求金钱可以买到的所有瓶
	sum += n / Y;
	//根据规则计算可以换多少汽水
	int number = Number(sum);
	//计算多和的汽水数
	for (int i = 0; i < number; i++)
	{
		sum1 = sum1 + sum;
		sum = sum / 2;
	}
	//求总共喝的汽水数
	sum = sum1 + sum;
	printf("%d\n", sum);
}
int main()
{
	SteamWater(20);
	system("pause");
	return 0;
}
