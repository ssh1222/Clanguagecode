#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//4.ģ��ʵ��strcat
//������char���͵��ַ������ӣ��м��޿ո�

//ʵ�ֽ�һ��������ֵ��������һ������
void Storage(char* arr1,char* arr2,int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		arr2[i] = arr1[i];
	}
}
void Link()
{
	char arr1[] = { "abcd" };
	char arr2[] = { "efg" };
	char arr3[100] = { 0 };
	int size1 = strlen(arr1);
	//����ֵarr1��ֵ����������arr3��
	Storage(arr1,&arr3[0],size1);
	int size2 = strlen(arr2);
	//������arr2��ֵ����������arr3��
	Storage(arr2, &arr3[4], size2);
	printf("%s\n", arr3);
}
int main()
{
	Link();
	system("pause");
	return 0;
}
��һ�ַ�����
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//ʵ��strcat

void* Mystrcat(char* dest, const char*src)
{
	//�ж��ַ��Ƿ�Ϊ�գ�Ϊ�ճ���ֹͣ
	assert(dest != NULL);
	assert(src != NULL);
	//��destָ��'\0'�ĵ�ַ
	while (*dest != '\0')
	{
		++dest;
	}
	//����dest��'\0'��ʼ����src��ֵ��ֵ��dest
	while (*dest = *src)
	{
		++dest;
		++src;
	}
	//��Ҫ����'\0'
	*dest = '\0';
	return dest;
}
int main()
{
	char src[] = "1234";
	char dest[100] = "abcd";
	Mystrcat(dest, src);
	printf("%s\n", dest);
	system("pause");
	return 0;
}
