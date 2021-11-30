#define _CRT_SECURE_NO_WARNINGS //heapsort

#include<stdio.h>
#include<math.h>
#include <time.h>



void printNameWithTrack() 
{
	char s[500] = { 0 };
	scanf("%s", &s);
	int a = -1;
	for (int i = 0; i < 500; i++)
	{
		if (s[i] == '.')
		{
			a = i;

		}


	}
	if (a >= 0)
	{
		for (int i = 0; i < a; i++)
		{
			printf("%c", s[i]);

		}

		printf(".html");
	}
	printf("\n\n");

}


void printLastFailName()
{
	char s[500] = { 0 };
	scanf("%s", &s);

	int slash1 = -1, slash2 = -1;


	for (int i = 0; i < 500; i++)
	{
		if (s[i] == 92) 
		{
			//printf("1");
			if (slash1 == -1)
			{
				slash1 = i;
				//printf("2");
			}
			else 
			{
				//printf("3");
				slash2 = slash1;
				slash1 = i;
			}
		}
	}
	
	if (slash2 == -1) 
	{
		printf("I can print only name");
	}
	
	else
	{
		for (int i = slash2 + 1; i < slash1; i++) 
		{
			printf("%c", s[i]);
		}
	}
	printf("\n\n");

}

void printNameWithoutShare()
{
	char s[500] = { 0 };
	scanf("%s", &s);

	int m = -1;
	int a = -1;
	for (int i = 0; i < 500; i++)
	{
		if (s[i] == '.')
		{
			m = i;

		}


	}

	for (int i = 0; i < 500; i++)
	{
		if (s[i] == 92)
		{
			a = i;
		}
	}

	if (a >= 0, m >=2) // what ??
	{
		for (int i = a + 1; i < m; i++)
		{
			printf("%c", s[i]);

			if (s[i] == "\0")
			{
				
				break;
			}
		}
		printf("\n\n");
	}


	
}

void printShare()
{
	char s[500] = { 0 };
	scanf("%s", &s);
	int a = -1;
	for (int i = 0; i < 500; i++)
	{
		if (s[i] == '.')
		{
			a = i;

		}


	}
	if (a >= 0)
	{
		for (int i = a + 1; i < 500; i++)
		{
			printf("%c", s[i]);

			if (s[i] == "\0")
			{
				
				break;
			}
		}
		printf("\n\n");
	}


}

void printNameWithShare() 
{
	char s[500] = { 0 };
	scanf("%s", &s);
	int a = -1;
	for (int i = 0; i < 500; i++)
	{
		if (s[i] == 92)
		{
			a = i;

		}


	}
	if (a >= 0)
	{
		for (int i = a + 1; i < 500; i++)
		{
			printf("%c", s[i]);

			if (s[i] == "\0")
			{
				
				break;
			}
		}
		printf("\n\n");
	}

}

void printsWithoutName() 
{
	char s[500] = { 0 };
	scanf("%s", &s);
	int a = -1;
	for (int i = 0; i < 500; i++)
	{
		if (s[i] == '\\' ) 
		{
			a = i;
			
		}

        
	}

	for (int i = 0; i < a + 1; i++)
	{
		printf("%c", s[i]);
	}
	printf("\n\n");
	
}

int main() 
{
    // D:\prog\Fail\name.c
	printsWithoutName();
	printNameWithShare();
	printShare();
	printNameWithoutShare();
	printLastFailName();
	printNameWithTrack();

 }
