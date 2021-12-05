#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

#define SIZE 500

void save(int* arr, char* name)
{
    FILE* f;
    f = fopen(name, "w+");
    for (int i = 0; i < 15; i++)
    {
        fprintf(f, "%d ", arr[i]);
    }
    fclose(f);
}

void load(int* arr, char* name)
{
    FILE* f;
    f = fopen(name, "r+");
    for (int i = 0; i < 15; i++)
    {
        fscanf(f, "%d", &arr[i]);
    }
    fclose(f);
}


int main()
{
    
    char name[500] = { 0 };
    int x[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    scanf("%s", &name);
    save(x, name);
    int y[15];
    load(y, name);

    for (int i = 0; i < 15; i++)
    {
        printf("%d ", y[i]);
    }
}
