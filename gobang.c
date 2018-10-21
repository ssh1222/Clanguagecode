#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ROW 5
#define COL 5

//五子棋

//用一个数组定义棋盘
char g_chess_board[ROW][COL];

//初始化棋盘
void Init()
{
	int row = 0;
	int col = 0;
	for (row = 0; row < ROW; row++)
	{
		for (col = 0; col < COL; col++)
		{
			g_chess_board[row][col] = ' ';
		}
	}
}
//打印棋盘
void Print()
{
	int row = 0;
	int col = 0;
	for (row = 0; row < ROW; row++)
	{
		printf("| %c | %c | %c | %c | %c |\n", g_chess_board[row][0],
			g_chess_board[row][1], g_chess_board[row][2],
			g_chess_board[row][3], g_chess_board[row][4]);
		if (row != ROW - 1)
		{
			printf("|---|---|---|---|---|\n");
		}
	}
}
//玩家落子
void PlayerMove()
{
	while (1)
	{
		int row = -1;
		int col = -1;
		printf("请输入坐标：");
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= ROW || col < 0 || col >= COL)
		{
			printf("输入的坐标不合理，请重新输入!\n");
			continue;
		}
		if (g_chess_board[row][col] != ' ')
		{
			printf("该位置已经有子，请重新输入!\n");
			continue;
		}
		g_chess_board[row][col] = 'x';
		break;
	}
}
//电脑落子
void ComputerMove()
{
	int row = 0;
	int col = 0;
	printf("请电脑落子：\n");
	while (1)
	{
		row = rand() % ROW;
		col = rand() % COL;
		if (g_chess_board[row][col] == ' ')
		{
			g_chess_board[row][col] = 'o';
			break;
		}
	}
}
//遍历所有格子，检测是否有空格
int IsFull()
{
	int row = 0;
	int col = 0;
	for (row = 0; row < ROW; row++)
	{
		for (col = 0; col < COL; col++)
		{
			if (g_chess_board[row][col] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
//检测赢家
char CheckWinner()
{
	int row = 0;
	int col = 0;
	for (row = 0; row <ROW; row++)
	{
		if (g_chess_board[row][0] == g_chess_board[row][1]
			&& g_chess_board[row][0] == g_chess_board[row][2]
			&& g_chess_board[row][0] == g_chess_board[row][3]
			&& g_chess_board[row][0] == g_chess_board[row][4]
			&& g_chess_board[row][0] != ' ')
		{
			return g_chess_board[row][0];
		}
	}
	for (col = 0; col < COL; col++)
	{
		if (g_chess_board[0][col] == g_chess_board[1][col]
			&& g_chess_board[0][col] == g_chess_board[2][col]
			&& g_chess_board[0][col] == g_chess_board[3][col]
			&& g_chess_board[0][col] == g_chess_board[4][col]
			&& g_chess_board[0][col] != ' ')
		{
			return g_chess_board[0][col];
		}
	}
	if (g_chess_board[0][0] == g_chess_board[1][1]
		&& g_chess_board[0][0] == g_chess_board[2][2]
		&& g_chess_board[0][0] == g_chess_board[3][3]
		&& g_chess_board[0][0] == g_chess_board[4][4]
		&& g_chess_board[0][0] != ' ')
	{
		return g_chess_board[0][0];
	}
	if (g_chess_board[0][4] == g_chess_board[1][3]
		&& g_chess_board[0][4] == g_chess_board[2][2]
		&& g_chess_board[0][4] == g_chess_board[3][1]
		&& g_chess_board[0][4] == g_chess_board[4][0]
		&& g_chess_board[0][4] != ' ')
	{
		return g_chess_board[0][4];
	}
	if (IsFull())
	{
		return 'q';
	}
	return ' ';
}

int main()
{
	char winner = ' ';
	Init();
	while (1)
	{
		Print();
		PlayerMove();
		winner = CheckWinner();
		if (winner != ' ')
		{
			break;
		}
		ComputerMove();
		winner = CheckWinner();
		if (winner != ' ')
		{
			break;
		}
	}
	if (winner == 'x')
	{
		printf("玩家获胜\n");
	}
	else
	if (winner == 'o')
	{
		printf("电脑获胜\n");
	}
	else
	if (winner == 'q')
	{
		printf("平局\n");
	}
	system("pause");
	return 0;
}
