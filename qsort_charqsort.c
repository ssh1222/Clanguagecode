//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include<string.h>
//
//#define MINE_COUNT 10
//#define ROW 9
//#define COL 9
//
////实现扫雷
//
////对于mine_map，使用'0'表示不是地雷，使用'1'表示是地雷
//char mine_map[ROW + 2][COL + 2];
////对于show_map,使用'*',表示未打开的方块，对于打开的，用具体的数字表示
//char show_map[ROW + 2][COL + 2];
//
////初始化（mine_map,show_map），布置雷盘
//void Init(char mine_map[ROW + 2][COL + 2], char show_map[ROW + 2][COL + 2])
//{
//	//分别将两个数组里的值设置没'0'和'*'
//	memset(mine_map, '0', (ROW + 2)*(COL + 2));
//	memset(show_map, '*', (ROW + 2)*(COL + 2));
//	//srand直接对time使用可能会丢失数据，因为新版本里time_t是64,
//	//而srand接受32位的unsigned int,所以会丢失数据。
//	srand((unsigned)time(0));
//	int mine_count = MINE_COUNT;
//	while (mine_count > 0)
//	{
//		//随机产生10个地雷
//		int row = rand() % ROW + 1;
//		int col = rand() % COL + 1;
//		if (mine_map[row][col] == '0')
//		{
//			mine_map[row][col] = '1';
//		}
//		--mine_count;
//	}
//}
//
////打印地图
//void DisplayMap(char map[ROW + 2][COL + 2])
//{
//	printf("     ");
//	int row = 0;
//	int col = 0;
//	for (col = 1; col <= COL; ++col)
//	{
//		printf("%d ", col);
//	}
//	printf("    ");
//	printf("\n");
//	printf("    ——————————");
//	printf("\n");
//	for (row = 1; row <= ROW; ++row)
//	{
//		printf(" %d | ", row);
//		for (col = 1; col <= COL; ++col)
//		{
//			printf("%c ", map[row][col]);
//		}
//		printf("\n");
//	}
//}
////统计row，col周围地雷的个数，并将结果更新到show_map中
//void UpdateShowMap(char mine_map[ROW + 2][COL + 2],
//	   char show_map[ROW + 2][COL + 2], int row, int col)
//{
//	int mine_count = 0;
//	mine_count = (mine_map[row - 1][col - 1] - '0')
//		+ (mine_map[row - 1][col] - '0')
//		+ (mine_map[row - 1][col + 1] - '0')
//		+ (mine_map[row][col - 1] - '0')
//		+ (mine_map[row][col + 1] - '0')
//		+ (mine_map[row + 1][col - 1] - '0')
//		+ (mine_map[row + 1][col] - '0')
//		+ (mine_map[row + 1][col + 1] - '0');
//	show_map[row][col] = '0' + mine_count;
//}
//
//void Game()
//{
//	//初始化地图（mine_map，show_map）,布置地图
//	Init(mine_map, show_map);
//	//打印地图
//	DisplayMap(show_map);
//	while (1)
//	{
//		int row = 0;
//		int col = 0;
//		int not_mine_count = 0;
//		printf("请输入坐标：");
//		scanf("%d %d", &row, &col);
//		//判断非法输入
//		if (row <= 0 || row > ROW || col <= 0 || col > COL)
//		{
//			printf("你输入的坐标不合理，请重新输入！\n");
//			continue;
//		}
//		//判断玩家是否踩到地雷，若踩到游戏结束，否则继续执行
//		if (mine_map[row][col] == '1')
//		{
//			DisplayMap(mine_map);
//			printf("游戏结束！\n");
//			break;
//		}
//		//计算没有踩到地雷雷的方块的个数是否等于排除地雷的个数
//		//若相等，获胜，否则继续执行
//		if (not_mine_count == ROW * COL - 10)
//		{
//			DisplayMap(mine_map);
//			printf("扫雷成功！");
//			break;
//		}
//		//游戏没有胜利，就要统计当前位置周围地雷的个数，并显示地图
//		UpdateShowMap(mine_map, show_map, row, col);
//		DisplayMap(show_map);
//	}
//}
//
//void Start()
//{
//	printf("欢迎来到扫雷！\n请选择：\n");
//	printf("开始游戏选择：1\n");
//	printf("退出游戏选择：0\n");
//	printf("请输入你的选择：");
//	while (1)
//	{
//		int choice = 0;
//		scanf("%d", &choice);
//		if (choice == 1)
//		{
//			printf("开始游戏：\n");
//			Game();
//			Start();
//		}
//		if (choice == 0)
//		{
//			printf("退出游戏！\n");
//			break;
//		}
//		break;
//	}
//}
//int main()
//{
//	Start();
//	system("pause");
//	return 0;
//}