#include<stdio.h>
#include<stdlib.h>

//�ݹ�ʵ�����n��쳲��������� 
//쳲���������1,1,2,3,5...
//���ɣ�ǰ������֮�͵��ں�һ�n = (n - 1) + (n - 2)

int FeiBo(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	return FeiBo(n - 1)+FeiBo(n - 2);
}
int main()
{
	printf("%d\n", FeiBo(5));
	system("pause");
	return 0;
}