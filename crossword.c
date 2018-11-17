#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//完成猜字游戏

void Game() 
{
	int n = 0;
	printf("请玩家输入：");
	//电脑产生随机数
	int num = 0;
	srand((unsigned) time(0));
	num = rand() % 100 + 1;
	//判断玩家是否猜中
	while (1)
	{
		//玩家输入
		scanf("%d", &n);
		if (n < num)
		{
			printf("你猜小了，请重新输入：");
			continue;
		}
		else if (n == num)
		{
			printf("恭喜你猜中了！");
		}
		else
		{
			printf("你猜大了，请重新输入：");
			continue;
		}
		break;
	}
	
}
int main()
{
	//进入游戏
    printf("猜字游戏现在开始!\n");
	Game();
	printf("\n");
	system("pause");
	return 0;
}
