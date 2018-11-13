#include<stdio.h>
#include<stdlib.h>

//ģ��ʵ��memmove
//mommove���ڴ�src����count���ֽڵ�dest��
//���Ŀ�������Դ�������ص��Ļ���mommove�ܹ�
//��֤Դ���ڱ�����֮ǰ���ص�������ֽڿ�����Ŀ
//�������У������ƺ�src���ݻᱻ���ġ�

void MomMove(char* src, char* dest, int count)
{
	int i = 0;
	//��src�е��ַ���������dest��
	for (i = 0; i < count; i++)
	{
		dest[i] = src[i];
	}
	//�ٽ�dest������src��������
	for (i = 0; i < count; i++)
	{
		src[i + 2] = dest[i];
	}
	//�������ǵ��ַ�������dest�ַ���֮��
	for (i = 0; i < count; i++)
	{
		src[i + 7] = dest[i + 2];
	}
	//��ӡsrc���ɼ�ʵ��memmove
	printf("%s\n", src);
}

int main()
{
	char src[1024] = "hello";
	char dest[1024] = { 0 };
	int count = 5;
	MomMove(src, dest, count);
	system("pause");
	return 0;
}

��һ�ַ�����
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//ʵ��memmove

void* Mymemmove(void* dest, void*src, size_t num)
{
	//src�ķ�Χ[src,src+num-1];
	assert(dest != NULL);
	assert(src != NULL);
	if (dest <= src || (char*)dest >= (char*)src + num - 1)
	{
		//û���غ���������
		for (size_t i = 0; i < num; i++)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		//�غϺ��ſ���
		dest = (char*)dest + num -1;
		src = (char*)src + num -1;
		for (size_t i = 0; i < num; i++)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest - 1;
			src = (char*)src - 1;
		}
	}
	return dest;
}
int main()
{
	//char dest[100];
	char src[] = "abcdef";
	Mymemmove(src+1, src, sizeof(src));
	printf("%s\n", src);
	system("pause");
	return 0;
}