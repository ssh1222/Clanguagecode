#include<stdio.h>
#include<stdlib.h>

#define N 11

//3.����Ļ�ϴ�ӡ������ǡ�
//1
//1 1
//1 2 1
//1 3 3 1

int main()
{
	int i = 0;
	int j = 0;
	int tge[N][N];
	//�ȴ�ӡÿһ�еĵ�һ�������һ����
	for (i = 0; i < N; i++)
	{
		tge[i][0] = 1;
		tge[i][i] = 1;
	}
	//��ӡ�м䲿��
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