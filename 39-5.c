#define _CRT_SECURE_NO_WARNINGS //39.5

#include<stdio.h>
#include<math.h>




int fun(int **x, int n, int l, int per)
{
	for (int i = 0; i < per;i++) 
  {
		for (int j = 0; j < n / per; j++) 
    {

			if (l == x[i][j]) {
				return i * j;
			}

		}
	}
	return -1;


}


int search(int **x, int n, int m, int l)
{



	int mid = (n + m) / 2;

	if (x[mid / 3][mid % 3] == l) 
	{

		return mid;

	}
	if (n >= m) {

		return -1;
	}
	if (x[mid / 3][mid % 3] > l) {
		return search(x, n, mid, l);
	}
	if (x[mid / 3][mid % 3] < l) {
		return search(x, mid + 1, m, l);
	}


}



int main() {
	int x[3][3] = {1,2,3,4,5,6,7,8,9};
	

	fun(x, 9, 5,3);

    
}
