#include<stdio.h>
#include<stdlib.h>

//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4��
//���ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ�
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
//������ A:murderer != A
//      B:murderer == C
//      C:murderer == D
//      D:murderer != D 

int main()
{
	char murderer = 0;
    for(murderer = 'A'; murderer <= 'D'; murderer++)
    {
		if ((murderer != 'A') +
			(murderer == 'C') +
			(murderer == 'D') +
			(murderer != 'D') == 3)
		{
			printf("%c\n", murderer);
		}
    }
	system("pause");
	return 0;
}