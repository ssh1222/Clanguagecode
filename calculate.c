#include<stdio.h>
#include<stdlib.h>

//计算1/1-1/2+1/3-...+1/99-1/100的值

int main()
{
	float den = 0;
	float sum = 1;
	int sign = 1;
	for (den = 2; den <= 100; den++)
	{
		//因为这是个累加的过程
		//sum将运算结果再赋给sum
		sum = sum - (1/den)*sign;
		sign = sign*(-1);	
	}
	//输出float型变量用'%f'
	printf("%f\n", sum);
	system("pause");
	return 0;
}