#define _CRT_SECURE_NO_WARNINGS //interpolycia
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

#define SIZ 500

// C:\\Users\\Igor\\Desktop\\t.txt
int main()
{
    FILE* f;

    f = fopen("C:\\Users\\Igor\\Desktop\\t.txt", "rb+");
    
    int i;
    int sum = 0;
    while (!feof(f))
    {
        fscanf(f, "%d", &i);
        sum += i;
    }

    printf("%d", sum);

    fclose(f);
}
