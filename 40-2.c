#define _CRT_SECURE_NO_WARNINGS //heapsort // use exist function

#include<stdio.h>
#include<math.h>
#include <time.h>

#define SIZE 500

int main() 
{
	char s[500] = { 0 };
	char ps[500] = { 0 };

	scanf("%s", &s);
	scanf("%s", &ps);

	int lens, lenps;

	for (int i = 0; i < 500; i++) 
	{
		if ((int)s[i] == 0)
		{
			lens = i;
			break;
		}

	}

	for (int i = 0; i < 500; i++)
	{
		if ((int)ps[i] == 0) 
		{
			lenps = i;
			break;
		}

	}

	int ind = 0;
	int count = 0;

	for (int i = 0; i < lens; i++) {
		//printf("%c - %c, %d\n", s[i], ps[ind], ind);
		if (s[i] == ps[0])
		{
			for (int j = 0; j < lenps; j++)
			{
				if (s[i + j] == ps[j])
				{
					ind++;
				}
				else {
					break;
				}
				//printf("%d", ind);
				
			}

			if (ind == lenps)
			{
				count++;
			}
			ind = 0;	
		}
	}

	printf("%d", count);

}
