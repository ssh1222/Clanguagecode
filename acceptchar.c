#include<stdio.h>
#include<stdlib.h>

//��дһ�����򣬿���һֱ���ռ����ַ��� 
//�����Сд�ַ��������Ӧ�Ĵ�д�ַ���
//������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ���
//��������ֲ������

int main()
{
	int letter = 0;
	printf("����һ�����̵��ַ���");
	//��ȡһ���ַ�getchar
	letter = getchar();
	if (letter >= 'a' && letter <= 'z')
	{
		//putchar���һ���ַ�
		putchar(letter - 32);
	}
	else if (letter >= 'A' && letter <= 'Z')
	{
		putchar(letter + 32);
	}
	if (0 <= letter <= 9)
		{
			;//�����
		}
	printf("\n");
	system("pause");
	return 0;
}

