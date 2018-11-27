#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1024

//ͨѶ¼

typedef struct Person
{
	char name[N];
	char sex[N];
	char age[N];
	char phone[N];
	char address[N];
}Person;

typedef struct Addrbook
{
	Person* person_info;
	int size;
	int capacity;
}Addrbook;

Addrbook g_addr_book;

enum
{
	EXIT = 0,
	ADD = 1,
	FIND = 2,
	DEL = 3,
	MODFITY = 4,
	PRINT = 5,
	CLEAR = 6
};

//��ʼ��ͨѶ¼
void Init()
{
	g_addr_book.size = 0;
	g_addr_book.capacity = 5;
	g_addr_book.person_info = (Person*)malloc(sizeof
		(Person)*g_addr_book.capacity);
}

int Menu()
{
	printf("(>^��^<)��\n");
	printf("0.�˳�\n");
	printf("1.���\n");
	printf("2.����\n");
	printf("3.ɾ��\n");
	printf("4.�޸�\n");
	printf("5.��ʾ\n");
	printf("6.���\n");
	printf("(>^��^<)��\n");
	int n = 0;
	printf("��������Ҫִ�еĲ�����");
	scanf("%d", &n);
	if (n<0 || n>6)
	{
		printf("��ѡ��Ĳ���������,������ѡ�񣡣�\n");
	}
	return n;
}

void CheckRealloc()
{
	if (g_addr_book.size < g_addr_book.capacity)
	{
		return;
	}
	g_addr_book.capacity *= 2;
	Person* tmp = (Person*)malloc(sizeof(Person)
		* g_addr_book.capacity);
	for (int i = 0; i < g_addr_book.size; ++i)
	{
		tmp[i] = g_addr_book.person_info[i];
	}
	free(g_addr_book.person_info);
	g_addr_book.person_info = tmp;
}

//��Ӹ�����Ϣ
void ADDPerson()
{
	//����
	CheckRealloc();
	printf("���һ�����û���\n");
	printf("������������");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].name);
	printf("�������Ա�");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].sex);
	printf("���������䣺");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].age);
	printf("������绰���룺");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].phone);
	printf("������סַ��");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].address);
	printf("��ӳɹ���\n");
	g_addr_book.size++;
}

//���Ҹ�����Ϣ
void FINDPerson()
{
	char name[N] = { 0 };
	int count = 0;
	printf("����������˵�name��");
	scanf("%s", &name);
	for (int i = 0; i < g_addr_book.size; i++)
	{
		if (strcmp(name, g_addr_book.person_info[i].name) == 0)
		{
			printf("���ҳɹ���");
			printf("������%s  �Ա�%s  ���䣺%s  �绰��%s  סַ��%s\n",
				g_addr_book.person_info[i].name,
				g_addr_book.person_info[i].sex,
				g_addr_book.person_info[i].age,
				g_addr_book.person_info[i].phone,
				g_addr_book.person_info[i].address);
			count++;
		}
	}
	if (count == 0)
	{
		printf("���û������ڣ�\n");
	}
}

//ɾ��������Ϣ
void DELPerson()
{
	int n = 0;
	printf("������ɾ���˶�Ӧ����ţ�");
	scanf("%d", &n);
	if (n<0 || n >= g_addr_book.size)
	{
		printf("���û�������,ɾ��ʧ�ܣ�\n");
		return;
	}
	if (n != g_addr_book.size)
	{
		strcpy(g_addr_book.person_info[n].name,
			g_addr_book.person_info[g_addr_book.size - 1].name);
		strcpy(g_addr_book.person_info[n].sex,
			g_addr_book.person_info[g_addr_book.size - 1].sex);
		strcpy(g_addr_book.person_info[n].age,
			g_addr_book.person_info[g_addr_book.size - 1].age);
		strcpy(g_addr_book.person_info[n].phone,
			g_addr_book.person_info[g_addr_book.size - 1].phone);
		strcpy(g_addr_book.person_info[n].address,
			g_addr_book.person_info[g_addr_book.size - 1].address);
	}
	--g_addr_book.size;
	printf("ɾ���ɹ���\n");
}

//�޸�һ���˵���Ϣ
void MODFITYPerson()
{
	int n = 0;
	printf("������Ҫ�޸��˵���ţ�");
	scanf("%d", &n);
	if (n<0 || n >= g_addr_book.size)
	{
		printf("���û������ڣ�\n");
		return;
	}
	char name[N] = { 0 };
	char phone[N] = { 0 };
	char sex[N] = { 0 };
	char age[N] = { 0 };
	char address[N] = { 0 };
	printf("��������name��");
	scanf("%s", &name);
	printf("��������sex��");
	scanf("%s", &sex);
	printf("��������age��");
	scanf("%s", &age);
	printf("��������phone��");
	scanf("%s", &phone);
	printf("��������address��");
	scanf("%s", &address);
	strcpy(g_addr_book.person_info[n].name, name);
	strcpy(g_addr_book.person_info[n].sex, sex);
	strcpy(g_addr_book.person_info[n].age, age);
	strcpy(g_addr_book.person_info[n].phone, phone);
	strcpy(g_addr_book.person_info[n].address, address);
	printf("�޸ĳɹ���\n");
}

void Swap(char* arr1, char* arr2)
{
	for (int i = 0; i < N; ++i)
	{
		char tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
}
//�ֵ���
void Qsort()
{
	int n = g_addr_book.size;
	while (n != 1)
	{
		for (int i = 0; i < n - 1; ++i)
		{
			if (strcmp(g_addr_book.person_info[i].name,
				g_addr_book.person_info[i + 1].name) == 1)
			{
				Swap(g_addr_book.person_info[i].name,
					g_addr_book.person_info[i + 1].name);
				Swap(g_addr_book.person_info[i].sex,
					g_addr_book.person_info[i + 1].sex);
				Swap(g_addr_book.person_info[i].age,
					g_addr_book.person_info[i + 1].age);
				Swap(g_addr_book.person_info[i].phone,
					g_addr_book.person_info[i + 1].phone);
				Swap(g_addr_book.person_info[i].address,
					g_addr_book.person_info[i + 1].address);
			}
		}
		--n;
	}
}

//��ӡ�����˵���Ϣ
void PRINTPerson()
{
	if (g_addr_book.size == 0)
	{
		printf("û���û���\n");
		return;
	}
	Qsort();
	int i = 0;
	for (i = 0; i < g_addr_book.size; i++)
	{
		printf("%d ������%s �Ա�%s ���䣺%s �绰��%s סַ��%s\n",
			i, g_addr_book.person_info[i].name,
			g_addr_book.person_info[i].sex,
			g_addr_book.person_info[i].age,
			g_addr_book.person_info[i].phone,
			g_addr_book.person_info[i].address);
	}
	printf("��ʾ�ɹ���\n");
}

//ȷ���Ƿ��˳�
void CLEARPerson()
{
	printf("��������û���Ϣ��\n");
	char n[N] = { 0 };
	printf("���ٴ�ȷ�����Ƿ������yes/no��: ");
	scanf("%s", &n);
	if (strcmp(n, "yes") != 0)
	{
		printf("��ȡ���������\n");
		return;
	}
	g_addr_book.size = 0;
	printf("����ɹ���\n");
}

//ͨѶ¼��Ϣ�ı���
void Save()
{
	FILE* fp = fopen("../text.txt", "w");
	if (fp == NULL)
	{
		printf("�ļ�����ʧ�ܣ�\n");
		return;
	}
	for (int i = 0; i < g_addr_book.size; ++i)
	{
		fwrite(&g_addr_book.person_info[i], sizeof(Person), 1, fp);
	}
	fclose(fp);
	printf("����ɹ���������%d����\n", g_addr_book.size);
}

//�����ļ���Ϣ
void Load()
{
	FILE* fp = fopen("../text.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		return;
	}
	//��һ���µ�Person��Ŷ�����Ϣ
	Person tmp = { 0 };
	while (fread(&tmp, sizeof(tmp), 1, fp))
	{
		g_addr_book.person_info[g_addr_book.size] = tmp;
		++g_addr_book.size;
	}
	fclose(fp);
	printf("���سɹ���������%d����\n", g_addr_book.size);
}

int main()
{
	Init();
	Load();
	while (1)
	{
		int choice = Menu();
		switch (choice)
		{
		case ADD:ADDPerson();
			Save();
			break;
		case FIND:FINDPerson();
			break;
		case DEL:DELPerson();
			Save();
			break;
		case MODFITY:MODFITYPerson();
			Save();
			break;
		case PRINT:PRINTPerson();
			break;
		case CLEAR:CLEARPerson();
			break;
		case EXIT:
			printf("��ӭ�ټ�����\n");
			Save();
			system("pause");
			return 0;
		default:
			break;
		}
	}
	system("pasue");
	return 0;
}
