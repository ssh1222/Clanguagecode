#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define D 10

typedef struct LNode
{
	int startaddress;//��ʼ��ַ
	int size;//������С
	int state;//����״̬
}LNode;

LNode array[D] = { { 0, 128, 0 }, { 300, 256, 0 }, 
     { 600, 512, 0 }, { 1200, 1024, 0 }, { 2400, 512, 0 } };

int n = 5; 
int N = 0;

//��ʼ��LNode
void print()
{
	int i;
	printf("��ʼ��ַ  ����  ״̬\n");
	for (i = 0; i < n; i++)
	{
		printf("%4d  %8d  %3d\n", array[i].startaddress, array[i].size, array[i].state);
	}
}

//�״���Ӧ�㷨
void FirstFit()
{
	int i, l = 0, m;
	printf("\n���������������Ĵ�С��");
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
		printf("��ַ�ɹ�����\n\n");
		printf("��ַ����ɹ����״̬��\n");
		print();
	}
	else
		printf("û�п��Է���ĵ�ַ�ռ�\n");
}

//ѭ���״���Ӧ�㷨
void NextFit()
{
	int i = 0, m, k = 0;
	printf("\n���������������Ĵ�С��");
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
		printf("��ַ�ɹ�����\n\n");
		printf("��ַ����ɹ����״̬��\n");
		print();
	}
	else
		printf("û�п��Է���ĵ�ַ�ռ�\n");
}

//�����Ӧ�㷨
void BestFit()
{
	int i, t = 0, l = 0, m;
	int a[D];
	printf("\n���������������Ĵ�С��");
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
		printf("��ַ�ɹ�����\n\n");
		printf("��ַ����ɹ����״̬��\n");
		print();
	}
	else
		printf("û�п��Է���ĵ�ַ�ռ�\n");
}

//���Ӧ�㷨
void WorstFit()
{
	int i, t = 0, l = 0, m;
	int a[D];
	printf("\n���������������Ĵ�С��");
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
		printf("��ַ�ɹ�����\n\n");
		printf("��ַ����ɹ����״̬��\n");
		print();
	}
	else
	{
		printf("û�п��Է���ĵ�ַ�ռ�\n");
	}
}

int main()
{
	int k = 0;
	printf("��̬���������㷨��\n");
	while (k != 5)
	{
		printf("**********************\n");
		printf("1.�״���Ӧ�㷨\n");
		printf("2.ѭ���״���Ӧ�㷨\n");
		printf("3.�����Ӧ�㷨\n");
		printf("4.���Ӧ�㷨\n");
		printf("5.�˳�\n");
		printf("**********************\n");
		printf("��ѡ���㷨��");
		scanf("%d", &k);
		switch (k)
		{
		case 1:
			printf("��ʼ״̬Ϊ��\n");
			print();
			FirstFit();
			continue;
		case 2:
			printf("��ʼ״̬Ϊ��\n");
			print();
			NextFit();
			continue;
		case 3:
			printf("��ʼ״̬Ϊ��\n");
			print();
			BestFit();
			continue;
		case 4: printf("��ʼ״̬Ϊ��\n");
			print();
		    WorstFit();
			continue;
		case 5:
			break;
		default:printf("���벻��ȷ������ѡ��\n");
		}
	}
	system("pause");
	return 0;
}