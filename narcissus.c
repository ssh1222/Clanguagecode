#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//���0~999֮���ˮ�ɻ��������
//ˮ�ɻ�������ָһ����λ�������λ���ֵ�������ȷ�õ��ڸ�������
//��:153��1^3��5^3��3^3����153��һ����ˮ�ɻ����� 
//�ֱ������λ��ʮλ����λ�������
int main()
{
	int hundred = 0;
	int decade = 0;
	int unit = 0;
	int i = 0;
	//ˮ�ɻ���ָ��λ����ֱ���ų�0~99����100��ʼ
	for (i = 100; i < 1000; i++)
	{
		//��λ
		hundred = i / 100;
		//ʮλ
		decade = (i / 10) % 10;
		//��λ
		unit = i % 10;
		if (i == pow(hundred, 3) + pow(decade, 3) + pow(unit, 3))
		{
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}