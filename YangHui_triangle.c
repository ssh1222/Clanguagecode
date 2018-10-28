#include<stdio.h>
#include<stdlib.h>

#define N 11

//3.在屏幕上打印杨辉三角。
//1
//1 1
//1 2 1
//1 3 3 1

int main()
{
	int i = 0;
	int j = 0;
	int tge[N][N];
	//先打印每一行的第一个和最后一个；
	for (i = 0; i < N; i++)
	{
		tge[i][0] = 1;
		tge[i][i] = 1;
	}
	//打印中间部分
	for (i = 2; i < N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			tge[i][j] = tge[i - 1][j - 1] + tge[i - 1][j];
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < 2 * (N - i); j++)
		{
			printf(" ");
		}
		for (j = 0; j <= i; j++)
		{
			printf("%4d", tge[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return;
}