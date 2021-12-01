#define _CRT_SECURE_NO_WARNINGS //interpolycia
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<locale.h>

#define SIZ 500



int main()
{
	setlocale(LC_ALL, "Russian");

	FILE* f;
	f = fopen("C:\\Users\\Igor\\Desktop\\t.txt", "r+", "t");
	char s[SIZ] = { 0 };
	for (int i = 0; i < 3; i++)
	{
		int a = 0;
		int input;
		fscanf(f, "%s", s);
		/*for (int i = 0; i < SIZ; i++)
		{
			printf("%c", s[i]);
		}
		printf(" ");
	}
	printf("\n");*/
	
	while (feof(f) == 0)
	{
		int a = 0;
		int input;
		fscanf(f, "%s", s);
		for (int i = 0; i < SIZ; i++)
		{
			printf("%c", s[i]);
		}
		fscanf(f, "%d", &input);
		
		a += input;
		fscanf(f, "%d", &input);
		a += input;
		printf(" %d", a);
		printf("\n");
		for (int i = 0; i < SIZ; i++)
		{
			s[i] = 0;
		}
	}
	

	
	fclose(f);
}
