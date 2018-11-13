#include<stdio.h>
#include<stdlib.h>

//模拟实现memmove
//mommove用于从src拷贝count个字节到dest；
//如果目标区域和源区域有重叠的话，mommove能够
//保证源串在被覆盖之前将重叠区域的字节拷贝到目
//标区域中，但复制后src内容会被更改。

void MomMove(char* src, char* dest, int count)
{
	int i = 0;
	//将src中的字符串拷贝到dest中
	for (i = 0; i < count; i++)
	{
		dest[i] = src[i];
	}
	//再将dest拷贝到src覆盖区域
	for (i = 0; i < count; i++)
	{
		src[i + 2] = dest[i];
	}
	//将被覆盖的字符串拷贝dest字符串之后
	for (i = 0; i < count; i++)
	{
		src[i + 7] = dest[i + 2];
	}
	//打印src即可简单实现memmove
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

另一种方法：
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//实现memmove

void* Mymemmove(void* dest, void*src, size_t num)
{
	//src的范围[src,src+num-1];
	assert(dest != NULL);
	assert(src != NULL);
	if (dest <= src || (char*)dest >= (char*)src + num - 1)
	{
		//没有重合正常拷贝
		for (size_t i = 0; i < num; i++)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		//重合后反着拷贝
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