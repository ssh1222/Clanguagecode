#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//��ɲ�����Ϸ

void Game() 
{
	int n = 0;
	printf("��������룺");
	//���Բ��������
	int num = 0;
	srand((unsigned) time(0));
	num = rand() % 100 + 1;
	//�ж�����Ƿ����
	while (1)
	{
		//�������
		scanf("%d", &n);
		if (n < num)
		{
			printf("���С�ˣ����������룺");
			continue;
		}
		else if (n == num)
		{
			printf("��ϲ������ˣ�");
		}
		else
		{
			printf("��´��ˣ����������룺");
			continue;
		}
		break;
	}
	
}
int main()
{
	//������Ϸ
    printf("������Ϸ���ڿ�ʼ!\n");
	Game();
	printf("\n");
	system("pause");
	return 0;
}
