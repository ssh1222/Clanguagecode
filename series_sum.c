#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//求Sn=a+aa+aaa+aaaa+aaaaa数列的前五项之和

//Sn看成求一个数从1~n次方的和
int Fun(int n)
{
	int i = 0;
	double Sn = 0;
	for (i = 1; i <= n; i++)
	{
		//将n求i次方并付给Sn
		Sn += pow(n, i);
	}
	return Sn;
}

//int main()
//{
//	printf("Sn= %d\n", Fun(5));
//	system("pause");
//	return 0;
//}