#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//��Sn=a+aa+aaa+aaaa+aaaaa���е�ǰ����֮��

//Sn������һ������1~n�η��ĺ�
int Fun(int n)
{
	int i = 0;
	double Sn = 0;
	for (i = 1; i <= n; i++)
	{
		//��n��i�η�������Sn
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