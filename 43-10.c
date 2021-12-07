#define _CRT_SECURE_NO_WARNINGS //
#include<stdio.h>
#include<math.h>
#include <time.h>

#define SIZE 500

void save(double* arr, char* name)
{
    FILE* f;
    f = fopen(name, "wb");
    for (int i = 0; i < 3; i++)
    {
        fwrite(&arr[i], sizeof(double), 1, f);
    }
    fclose(f);
}

double read( char* name)
{
    FILE* f;
    f = fopen(name, "rb");
    double sum = 0;
    double i;
    while (!feof(f))
    {
        fread(&i, sizeof(double), 1, f);
        if (feof(f))
        {
            break;
        }
        sum += i;
    }
    fclose(f);
    return sum;
}

// C:\\Users\\Igor\\Desktop\\data.dat

int main()
{

    char name[500] = { 0 };
    double x[3] = {1,2,3 };
    scanf("%s", &name);
    save(x, name);

    printf("%f", read(name));
}
