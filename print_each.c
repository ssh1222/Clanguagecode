#include<stdio.h>
#include<stdlib.h>

//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ 

void Print(int n)
{
	if (n > 9)
	{
		Print(n / 10);
	}
	printf("%d\n", n % 10);
}
int main()
{
	Print(1234);
	system("pause");
	return 0;
}