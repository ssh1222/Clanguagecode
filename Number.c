#include<stdio.h>
#include<stdlib.h>

#define Y 1

//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Զ�����ˮ��
//���ʵ�֡�

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
	//���Ǯ�����򵽵�����ƿ
	sum += n / Y;
	//���ݹ��������Ի�������ˮ
	int number = Number(sum);
	//�����͵���ˮ��
	for (int i = 0; i < number; i++)
	{
		sum1 = sum1 + sum;
		sum = sum / 2;
	}
	//���ܹ��ȵ���ˮ��
	sum = sum1 + sum;
	printf("%d\n", sum);
}
int main()
{
	SteamWater(20);
	system("pause");
	return 0;
}
