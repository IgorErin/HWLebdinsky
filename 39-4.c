#define _CRT_SECURE_NO_WARNINGS //39.4

#include<stdio.h>
#include<math.h>
#include <time.h>

int searchLine(int* x, int n, int l) 
{

	for (int i = 0; i < n; i++) 
	{
		if (x[i] == l) 
		{
			return i;
		}

	}

}

int search(int x[], int n, int m, int l) {



	int mid = (n + m) / 2;

	if (x[mid] == l) 
	{
		return mid;
	}

	if (n >= m)
	{
		return -1;
	}

	if (x[mid] > l)
	{
		return search(x, n, mid, l);
	}

	if (x[mid] < l)
	{
		return search(x, mid + 1, m, l);
	}


}

int compare(const void * x1, const void * x2)   
{
  return ( *(int*)x1 - *(int*)x2 );             
}



int main() {
	srand(time(NULL));
	int x[10000];
	float sum1 = 0, sum2 = 0;
	
	clock_t end, start;
	for (int i = 0; i < 10000; i++) {
		x[i] = rand() % 30000;
	}
	for (int i = 0; i < 10000; i++)
	{
		clock_t t0 = clock();
		for (int i = 0; i < 30000; i++) 
		{
			searchLine(x, 10000, x[rand() % 10000]);
		}
		clock_t t1 = clock() - t0;
	    sum1 += (double)t1 / CLOCKS_PER_SEC;
		
	}
	
	sum1 = sum1 / 30000;

	qsort(x, 30000, sizeof(int), compare);

	for (int i = 0; i < 10000; i++) 
	{
		clock_t t0 = clock();
		for (int i = 0; i < 30000; i++)
		{
			search(x, 0, 9999, x[rand() % 10000]);
		}
		clock_t t1 = clock() - t0;
		sum2 += (double)t1 / CLOCKS_PER_SEC;

	}
	sum2 = sum2 / 30000;
	
	printf("%f, %f", sum1, sum2);
}
