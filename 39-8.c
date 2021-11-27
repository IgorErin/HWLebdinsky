#include<math.h>
#include <time.h>

int fun(int **x, int *y, int left, int right, int m, int ind) {
	if (ind == m - 1)
	{
		return left;
	}
	int left1, right1, a = 0;

	for (int i = left; i < right; i++) {
		if (x[i][ind] == y[ind])
		{
			left1 = i;
			a = 1;
		}
		if (a == 1 && x[i][ind] != y[ind]) {
			right1 = i;
			return fun(x, y, left1, right1, m, ind + 1);
		}
	}

	if (a == 0) {
		return -1;
	}
}

int main() {

 }
