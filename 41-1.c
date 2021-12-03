#define _CRT_SECURE_NO_WARNINGS //heapsort/

#include<stdio.h>
#include<math.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 500

struct avto
{
	float price;
	char color;
	int quantity;
	int quantityHorseForces;
	_Bool Bool;
};


void inicial(struct avto *x, int n)
{
	for (int i = 0; i < n; i++)
	{
		x[i].Bool = false;
	}
}

void fillIn(struct avto* x, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (x[i].Bool)
		{
			printf("Enter the price");
			scanf("%f", &x[i].price);
			printf("Enter the color");
			scanf("%c", &x[i].color);
			printf("Enter the quantity");
			scanf("%d", &x[i].quantity);
			printf("Enter the quantityHorseForces");
			scanf("%d", &x[i].quantityHorseForces);
		}
	}
}

void traid(struct avto* x, int n)
{
	int a;
	scanf("enter number %d\n", &a);
	if (a >= n)
	{
		printf("Error");
	}
	else
	{
		x[a - 1].Bool = false;
	}
}

void information(struct avto* x, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (x[i].Bool)
		{
			printf("nuber : %d\n", i + 1);
			printf("price : %f\n", x[i].price);
			printf("color : %c", x[i].color);
			printf("quantity : %d", x[i].quantity);
			printf("quantityHorseForces : %d", x[i].quantityHorseForces);
		}
	}
}


int main() 
{
	struct avto m[10];

	int input;
	printf("Choose what you want \n, enter 1 if you wont to initialize,\n 2 if you want to fill in,\n");
	printf("3 if you want to traid,\n 4 if you wnat to giv information\n, 5 if you want exit");
	scanf("%d", &input);
	while (input != 5)
	{
		if (input == 1)
		{
			inicial(&m, 10);
		}
		if (input == 2)
		{
			fillIn(&m, 10);
		}
		if (input == 3)
		{
			traid(&m, 10);
		}
		if (input == 4)
		{
			information(&m, 10);
		}
		printf("Please choose next");
		printf("Choose what you want \n, enter 1 if you wont to initialize,\n 2 if you want to fill in,\n");
		printf("3 if you want to traid,\n 4 if you wnat to giv information\n, 5 if you want exit");
		scanf("%d", &input);
	}


}
