#include<stdio.h>
#include<stdlib.h>

//1.��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832

unsigned int reverse_bit(unsigned int value)
{
	//�������value1�������ȡ��value��ֵ
	unsigned int value1 = 0;
	int i = 0;
	for (i = 0; i < 31; i++)
	{
		//�����ȡ25�������е�ֵ,
		if ((value >> i) & 1)
		{
			value1 = value1 | ((value >> i) & 1);
		}
		value1 <<= 1;
	}
	return value1;
}		
int main()
{
	//%u�޷��ŵ�ʮ����
	//%d�з��ŵ�ʮ����
	printf("%u\n", reverse_bit(25));
	system("pause");
	return 0;
}