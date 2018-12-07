#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define D 10

typedef struct LNode
{
	int startaddress;//起始地址
	int size;//分区大小
	int state;//分区状态
}LNode;

LNode array[D] = { { 0, 128, 0 }, { 300, 256, 0 }, 
     { 600, 512, 0 }, { 1200, 1024, 0 }, { 2400, 512, 0 } };

int n = 5; 
int N = 0;

//初始化LNode
void print()
{
	int i;
	printf("起始地址  分区  状态\n");
	for (i = 0; i < n; i++)
	{
		printf("%4d  %8d  %3d\n", array[i].startaddress, array[i].size, array[i].state);
	}
}

//首次适应算法
void FirstFit()
{
	int i, l = 0, m;
	printf("\n输入请求分配分区的大小：");
	scanf("%d", &m);
	for (i = 0; i < n; i++)
	{
		if (array[i].size < m)
		{
			continue;
		}
		else if (array[i].size == m)
		{
			array[i].state = 1;
			l = 1;
			break;
		}
		else
		{
			array[n].startaddress = array[i].startaddress + m;
			array[n].size = array[i].size - m;
			array[i].size = m; 
			array[i].state = 1;
			l = 1;    
			n++;
			break;
		}
	}
	if (l == 1 || i < n)
	{
		printf("地址成功分配\n\n");
		printf("地址分配成功后的状态：\n");
		print();
	}
	else
		printf("没有可以分配的地址空间\n");
}

//循环首次适应算法
void NextFit()
{
	int i = 0, m, k = 0;
	printf("\n输入请求分配分区的大小：");
	scanf("%d", &m);
	while (N < n)
	{
		if (array[N].size < m)
		{
			N = N + 1;
			if (N/n == 1)
			{
				N = 0; 
				k = 1;
			}
			continue;
		}
		if (array[N].size == m && array[N].state != 1)
		{
			array[N].state = 1;
			i = 1;		
			N++;
			break;
		}
		if (array[N].size > m && array[N].state != 1)
		{
			array[n].startaddress = array[N].startaddress + m;
			array[n].size = array[N].size - m;
			array[N].size = m;
			array[N].state = 1;
			i = 1;	   
			n++;
			N++;
			break;
		}
	}
	if (i == 1)
	{
		printf("地址成功分配\n\n");
		printf("地址分配成功后的状态：\n");
		print();
	}
	else
		printf("没有可以分配的地址空间\n");
}

//最佳适应算法
void BestFit()
{
	int i, t = 0, l = 0, m;
	int a[D];
	printf("\n输入请求分配分区的大小：");
	scanf("%d", &m);
	for (i = 0; i < n; i++)
	{
		a[i] = 0;
		if (array[i].size < m)
		{
			continue;
		}
		else if (array[i].size == m)
		{
			array[i].state = 1;
			l = 1;
			break;
		}
		else
		{
			a[i] = array[i].size - m;
		}
	}
	if (l == 0)
	{
		for (i = 0; i < n; i++)
		{
			if (a[i] != 0)
			{
				t = i;
			}
		}
		for (i = 0; i < n; i++)
		{
			if (a[i] != 0 && a[i] < a[t])
			{
				t = i;
			}
		}
		array[n].startaddress = array[t].startaddress + m;
		array[n].size = array[t].size - m;
		array[t].size = m; 
		array[t].state = 1;
		l = 1;	 
		n++;
	}
	LNode tmp = array[t];
	array[t] = array[n - 1];
	array[n - 1] = tmp;
	for (int i = 0; i < 5; ++i)
	{
		int count = 0;
		for (int j = 0; j < 5 - i - 1; ++j)
		{
			if (array[j].size > array[j + 1].size)
			{
				LNode tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				count = 1;
			}
		}
		if (count == 0)
		{
			break;
		}
	}
	if (l == 1 || i < n)
	{
		printf("地址成功分配\n\n");
		printf("地址分配成功后的状态：\n");
		print();
	}
	else
		printf("没有可以分配的地址空间\n");
}

//最坏适应算法
void WorstFit()
{
	int i, t = 0, l = 0, m;
	int a[D];
	printf("\n输入请求分配分区的大小：");
	scanf("%d", &m);
	for (i = 0; i < n; i++)
	{
		a[i] = 0;
		if (array[i].size < m)
		{
			continue;
		}
		else if (array[i].size == m)
		{
			array[i].state = 1;
			l = 1;    
			break;
		}
		else
		{
			a[i] = array[i].size - m;
		}
	}
	if (l == 0)
	{
		for (i = 0; i < n; i++)
		{
			if (a[i] != 0)
				t = i;
		}
		for (i = 0; i < n; i++)
		{
			if (a[i] != 0 && a[i] > a[t])
				t = i;
		}
		array[n].startaddress = array[t].startaddress + m;
		array[n].size = array[t].size - m;
		array[t].size = m; 
		array[t].state = 1;
		l = 1;	 
		n++;
	}
	LNode tmp = array[t];
	array[t] = array[n - 1];
	array[n - 1] = tmp;
	for (int i = 0; i < 5; ++i)
	{
		int count = 0;
		for (int j = 0; j < 5 - i - 1; ++j)
		{
			if (array[j].size > array[j + 1].size)
			{
				LNode tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				count = 1;
			}
		}
		if (count == 0)
		{
			break;
		}
	}
	if (l == 1 || i < n)
	{
		printf("地址成功分配\n\n");
		printf("地址分配成功后的状态：\n");
		print();
	}
	else
	{
		printf("没有可以分配的地址空间\n");
	}
}

int main()
{
	int k = 0;
	printf("动态分区分配算法：\n");
	while (k != 5)
	{
		printf("**********************\n");
		printf("1.首次适应算法\n");
		printf("2.循环首次适应算法\n");
		printf("3.最佳适应算法\n");
		printf("4.最坏适应算法\n");
		printf("5.退出\n");
		printf("**********************\n");
		printf("请选择算法：");
		scanf("%d", &k);
		switch (k)
		{
		case 1:
			printf("初始状态为：\n");
			print();
			FirstFit();
			continue;
		case 2:
			printf("初始状态为：\n");
			print();
			NextFit();
			continue;
		case 3:
			printf("初始状态为：\n");
			print();
			BestFit();
			continue;
		case 4: printf("初始状态为：\n");
			print();
		    WorstFit();
			continue;
		case 5:
			break;
		default:printf("输入不正确请重新选择！\n");
		}
	}
	system("pause");
	return 0;
}