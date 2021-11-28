#define _CRT_SECURE_NO_WARNINGS //heapsort

#include<stdio.h>
#include<math.h>
#include <time.h>

#define SIZE 500

int main() 
{
	char s[500] = { 0 };
	scanf("%s", &s);

	int count = 0;
	int flag = 0;

	for (int i = 0; i < 500; i++)
	{
		if (isdigit(s[i]) && !flag )
		{
			flag = 1;
		}
		if (!isdigit(s[i]) && flag)
		{
			flag = 0;
			count++;
		}

	}

	printf("%d", count);

}
