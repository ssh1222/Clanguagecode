#include<stdio.h>
#include<stdlib.h>

//����Ļ�����һ�������ε�ͼ��

void PrintLine(int blank_count, int star_count)
{
	int i = 0;
	for (i = 1; i <= blank_count; i++)
	{
		printf(" ");
	}
	for (i = 1; i <= star_count; i++)
	{
		printf("*");
	}
	printf("\n");
}

void PrintDiamond(int n)
{
	//������ʮ�ֶԳƵģ��������һ��Ϊn
	int i = 0;
	//����n�������������Σ��ϰ벿�֡��м䲿�֡��°벿��
	//�ϰಿ��
	for (i = 1; i < n; i++)
	{
		PrintLine(n - i, 2 * i - 1);
	}
	//�м䲿��
	PrintLine(0, 2 * n - 1);
	//�°벿��
	for (i = n - 1; i > 0; i--)
	{
		PrintLine(n - i, 2 * i - 1);
	}
}

//����ͼ����' '��'*'��ɣ����ϵ��´�ӡ����������
int main()
{
	//����һ�����κ���
	PrintDiamond(7);
	system("pause");
	return 0;
}
