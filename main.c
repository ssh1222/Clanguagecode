#define _CRT_SECURE_NO_WARNING
#include<stdio.h>
#include<stdlib.h>

//������������С���

int main()
{
int x = 0;
	int y = 0;
	int z = 0;
	int t = 0;
	printf("��������������:");
	scanf("%d %d %d", &x, &y, &z);
	if(x < y)
	{
		t = y;
		y = x;
		x = t;
	}
	if(y < z)
	{
		t = z;
		z = y;
		y = t;
	}
	if(x < y)
	{
		t = y;
		y = x;
		x = t;
	}




	printf("%d %d %d\n", x, y, z);




	system("pause");




	return 0;




}