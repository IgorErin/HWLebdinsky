#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

#define SIZE 500

int main()
{
	char main_str[500] = { 0 };
	char sub_str[500] = "abs";

	scanf("%s", &main_str);
	scanf("%s", &sub_str);
	
	int sub_str_count = 0;	

	char* tmp = main_str;	

	
	while ((tmp = strstr(tmp, sub_str)) != NULL)
	{
		tmp++;
		sub_str_count++;
	}
	printf("%d", sub_str_count);
}
