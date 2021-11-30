#define _CRT_SECURE_NO_WARNINGS //accepted

#include<stdio.h>
#include<math.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 3


int fun(int (x)[SIZE][SIZE], int n, int per, int l)
{

	
	for (int i = 0; i < per; i++)
	{
		for (int j = 0; j < n / per; j++)
		{
			if (x[i][j] == l)
			{
				return per * i + j;
			}
		}
	}

	return -1;
}


int search(int (x)[SIZE][SIZE], int n, int m,int lens, int l)
{



	int mid = (n + m) / 2;

	if (x[mid / lens][mid % lens] == l)
	{

		return mid;

	}
	if (n >= m) {

		return -1;
	}
	if (x[mid / lens][mid % lens] > l)
	{
		return search(x, n, mid, SIZE, l);
	}
	if (x[mid / lens][mid % lens] < l)
	{
		return search(x, mid + 1, m, lens, l);
	}


}



int main() {
	int x[SIZE][SIZE] = { 1,2,3,4,5,6,7,8,9 };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", x[i][j]);
		}
		printf("\n");
	}


	printf("%d \n", fun(x, SIZE * SIZE, SIZE, 5));
	printf("%d", search(x, SIZE * SIZE, 0, SIZE, 5));

}
