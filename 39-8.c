#define _CRT_SECURE_NO_WARNINGS //interpolycia
#include<stdio.h>
#include<math.h>
#include<time.h>

#define SIZE1 3
#define SIZE2 3

int relation(int* x, int* y, int n)
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (x[i] > y[i])
		{
			flag = 1;
			break;
		}
		if (x[i] < y[i])
		{
			flag = -1;
			break;
		}
	}

	return flag;
}



int fun(int (x)[SIZE1][SIZE2], int* y, int low, int high) 
{ 
	

	int mid = (high + low) / 2;

	if (relation(x[mid], y, SIZE2) == 0)
	{
		return mid;
	}
	
	if (low == high)
	{
		return -1;
	}

	if (relation(x[mid], y, SIZE2) > 0)
	{
		fun(x, y, low, mid);
	}

	if (relation(x[mid], y, SIZE2) < 0)
	{
		fun(x, y, mid + 1, high);
	}

}


int main() {
	int x[SIZE1][SIZE2];
	int y[SIZE2];
}
