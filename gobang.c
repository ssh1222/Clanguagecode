#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define ROW 5
#define COL 5

//������

//��һ�����鶨������
char g_chess_board[ROW][COL];

//��ʼ������
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
//��ӡ����
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
//�������
void PlayerMove()
{
	while (1)
	{
		int row = -1;
		int col = -1;
		printf("���������꣺");
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= ROW || col < 0 || col >= COL)
		{
			printf("��������겻��������������!\n");
			continue;
		}
		if (g_chess_board[row][col] != ' ')
		{
			printf("��λ���Ѿ����ӣ�����������!\n");
			continue;
		}
		g_chess_board[row][col] = 'x';
		break;
	}
}
//��������
void ComputerMove()
{
	int row = 0;
	int col = 0;
	printf("��������ӣ�\n");
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
//�������и��ӣ�����Ƿ��пո�
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
//���Ӯ��
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
		printf("��һ�ʤ\n");
	}
	else
	if (winner == 'o')
	{
		printf("���Ի�ʤ\n");
	}
	else
	if (winner == 'q')
	{
		printf("ƽ��\n");
	}
	system("pause");
	return 0;
}
