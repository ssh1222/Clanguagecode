#include<stdio.h>
#include<stdlib.h>

//递归实现strlen（求字符串的长度）

int strlen(char* arr)
{
	while (*arr == '\0')
	{
		return 0;
	}
	return 1 + strlen(arr + 1);

}

int main()
{

	printf("%d\n", strlen("sunshihao"));
	system("pause");
	return 0;
}