#define _CRT_SECURE_NO_WARNINGS //interpolycia
#include<stdio.h>
#include<math.h>
#include<time.h>

int interpolationSearch(int array[], int size, int n)
{
    int low = 0;
    int mid;
    int high = size - 1;
    while (1)
    {
        
        if (array[low] == n)
            return low;
        else if (array[high] == n)
            return high;

        if (array[low] == array[high])
            break;
        mid = low + (n - array[low]) * (high - low) / (array[high] - array[low]);
        
        if (n < array[mid])
            high = mid;
        
        else if (n > array[mid])
            low = mid + 1;
        else
            return mid;
        
        
    }
    return -1;
}




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

int compare(const void* x1, const void* x2)
{
	return (*(int*)x1 - *(int*)x2);
}



int main() {
	srand(time(NULL));
	int x[10000];
	float sum1 = 0, sum2 = 0, sum3 = 0;

	clock_t end, start;
	for (int i = 0; i < 10000; i++) {
		x[i] = rand() % 30000;
	}
	for (int i = 0; i < 10000; i++)
	{
		clock_t t0 = clock();
		
		
		searchLine(x, 10000, x[rand() % 10000]);
		
		clock_t t1 = clock() - t0;
		sum1 += (double)t1 / CLOCKS_PER_SEC;

	}

	sum1 = sum1 / 30000;

	qsort(x, 30000, sizeof(int), compare);

	for (int i = 0; i < 10000; i++)
	{
		clock_t t0 = clock();
		
		
		search(x, 0, 9999, x[rand() % 10000]);
		
		clock_t t1 = clock() - t0;
		sum2 += (double)t1 / CLOCKS_PER_SEC;

	}
	sum2 = sum2 / 30000;

	for (int i = 0; i < 10000; i++)
	{
		clock_t t0 = clock();


		interpolationSearch(x, 0, 9999, x[rand() % 10000]);

		clock_t t1 = clock() - t0;
		sum3 += (double)t1 / CLOCKS_PER_SEC;

	}
	sum3 = sum3 / 30000;

	printf("%f, %f, %f", sum1, sum2, sum3);
}
