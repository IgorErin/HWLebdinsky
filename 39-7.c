#define _CRT_SECURE_NO_WARNINGS //39.7 // accepted

#include<stdio.h>
#include<math.h>
#include <time.h>



int search(int x[], int n, int m, int l) {
	int mid = (n + m) / 2;

	if (n + 1 == m && x[n] == l) 
	{
		return n;
	}
	else if (n + 1 == m && x[m] == l)
	{
		return m;
	}

	if (n >= m)
	{
		return -1;
	}

	if (x[mid] >= l )
	{
		return search(x, n, mid, l);
	}

	if (x[mid] < l )
	{
		return search(x, mid + 1, m, l);
	}


}



int main() {
	int x[23] = { 1,2,3,3,3,3,4,4,4,5,5,5,5,6,6,6,8,8,8,9,10,10,10 };
	printf("%d", search(x, 0, 22, 9));;
}
