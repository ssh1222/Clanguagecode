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
////ʵ��ɨ��
//
////����mine_map��ʹ��'0'��ʾ���ǵ��ף�ʹ��'1'��ʾ�ǵ���
//char mine_map[ROW + 2][COL + 2];
////����show_map,ʹ��'*',��ʾδ�򿪵ķ��飬���ڴ򿪵ģ��þ�������ֱ�ʾ
//char show_map[ROW + 2][COL + 2];
//
////��ʼ����mine_map,show_map������������
//void Init(char mine_map[ROW + 2][COL + 2], char show_map[ROW + 2][COL + 2])
//{
//	//�ֱ������������ֵ����û'0'��'*'
//	memset(mine_map, '0', (ROW + 2)*(COL + 2));
//	memset(show_map, '*', (ROW + 2)*(COL + 2));
//	//srandֱ�Ӷ�timeʹ�ÿ��ܻᶪʧ���ݣ���Ϊ�°汾��time_t��64,
//	//��srand����32λ��unsigned int,���Իᶪʧ���ݡ�
//	srand((unsigned)time(0));
//	int mine_count = MINE_COUNT;
//	while (mine_count > 0)
//	{
//		//�������10������
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
////��ӡ��ͼ
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
//	printf("    ��������������������");
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
////ͳ��row��col��Χ���׵ĸ���������������µ�show_map��
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
//	//��ʼ����ͼ��mine_map��show_map��,���õ�ͼ
//	Init(mine_map, show_map);
//	//��ӡ��ͼ
//	DisplayMap(show_map);
//	while (1)
//	{
//		int row = 0;
//		int col = 0;
//		int not_mine_count = 0;
//		printf("���������꣺");
//		scanf("%d %d", &row, &col);
//		//�жϷǷ�����
//		if (row <= 0 || row > ROW || col <= 0 || col > COL)
//		{
//			printf("����������겻�������������룡\n");
//			continue;
//		}
//		//�ж�����Ƿ�ȵ����ף����ȵ���Ϸ�������������ִ��
//		if (mine_map[row][col] == '1')
//		{
//			DisplayMap(mine_map);
//			printf("��Ϸ������\n");
//			break;
//		}
//		//����û�вȵ������׵ķ���ĸ����Ƿ�����ų����׵ĸ���
//		//����ȣ���ʤ���������ִ��
//		if (not_mine_count == ROW * COL - 10)
//		{
//			DisplayMap(mine_map);
//			printf("ɨ�׳ɹ���");
//			break;
//		}
//		//��Ϸû��ʤ������Ҫͳ�Ƶ�ǰλ����Χ���׵ĸ���������ʾ��ͼ
//		UpdateShowMap(mine_map, show_map, row, col);
//		DisplayMap(show_map);
//	}
//}
//
//void Start()
//{
//	printf("��ӭ����ɨ�ף�\n��ѡ��\n");
//	printf("��ʼ��Ϸѡ��1\n");
//	printf("�˳���Ϸѡ��0\n");
//	printf("���������ѡ��");
//	while (1)
//	{
//		int choice = 0;
//		scanf("%d", &choice);
//		if (choice == 1)
//		{
//			printf("��ʼ��Ϸ��\n");
//			Game();
//			Start();
//		}
//		if (choice == 0)
//		{
//			printf("�˳���Ϸ��\n");
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