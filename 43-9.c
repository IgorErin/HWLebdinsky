#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

#define SIZE 500

void save(float* arr, char* name)
{
    FILE* f;
    f = fopen(name, "wb+");
    for (int i = 0; i < 15; i++)
    {
        fwrite(&arr[i], sizeof(float), 1, f);
    }
    fclose(f);
}

void load(float* arr, char* name)
{
    FILE* f;
    f = fopen(name, "rb+");
    for (int i = 0; i < 15; i++)
    {
        fread(&arr[i], sizeof(float), 1, f);
    }
    fclose(f);
}

// C:\\Users\\Igor\\Desktop\\data.dat

int main()
{
    
    char name[500] = { 0 };
    float x[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    scanf("%s", &name);
    save(x, name);
    float y[15];
    load(y, name);

    for (int i = 0; i < 15; i++)
    {
        printf("%f ", y[i]);
    }
}
