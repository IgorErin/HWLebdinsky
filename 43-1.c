#define _CRT_SECURE_NO_WARNINGS //interpolycia
#include<stdio.h>
#include<math.h>
#include<time.h>

#define SIZE1 3
#define SIZE2 3


int main()
{
	

	FILE* f;
	f = fopen("C:\\Users\\Igor\\Desktop\\l.txt", "w+", "t");
	fprintf(f, "sinx x \n");
	for (int i = 0; i < 10; i++) {
		fprintf(f,"%.4f %.4f \n", sin((float)i / 10),(float) i / 10);
	}
	fclose(f);
}
