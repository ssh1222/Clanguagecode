#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//求出0~999之间的水仙花数并输出
//水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身
//如:153＝1^3＋5^3＋3^3，则153是一个“水仙花数” 
//分别求出百位、十位、个位，在求和
int main()
{
	int hundred = 0;
	int decade = 0;
	int unit = 0;
	int i = 0;
	//水仙花数指三位数，直接排除0~99，从100开始
	for (i = 100; i < 1000; i++)
	{
		//百位
		hundred = i / 100;
		//十位
		decade = (i / 10) % 10;
		//个位
		unit = i % 10;
		if (i == pow(hundred, 3) + pow(decade, 3) + pow(unit, 3))
		{
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}