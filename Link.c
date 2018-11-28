#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//4.模拟实现strcat
//将两个char类型的字符串连接，中间无空格

//实现将一个数组中值拷贝到另一个数组
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
	//将数值arr1的值拷贝在数组arr3里
	Storage(arr1,&arr3[0],size1);
	int size2 = strlen(arr2);
	//将数组arr2的值拷贝在数组arr3里
	Storage(arr2, &arr3[4], size2);
	printf("%s\n", arr3);
}
int main()
{
	Link();
	system("pause");
	return 0;
}
另一种方法：
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//实现strcat

void* Mystrcat(char* dest, const char*src)
{
	//判断字符是否为空，为空程序停止
	assert(dest != NULL);
	assert(src != NULL);
	//让dest指向'\0'的地址
	while (*dest != '\0')
	{
		++dest;
	}
	//将从dest的'\0'开始，将src的值赋值给dest
	while (*dest = *src)
	{
		++dest;
		++src;
	}
	//不要遗落'\0'
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
