#include<stdio.h>
#include<stdlib.h>

//����1/1-1/2+1/3-...+1/99-1/100��ֵ

int main()
{
	float den = 0;
	float sum = 1;
	int sign = 1;
	for (den = 2; den <= 100; den++)
	{
		//��Ϊ���Ǹ��ۼӵĹ���
		//sum���������ٸ���sum
		sum = sum - (1/den)*sign;
		sign = sign*(-1);	
	}
	//���float�ͱ�����'%f'
	printf("%f\n", sum);
	system("pause");
	return 0;
}