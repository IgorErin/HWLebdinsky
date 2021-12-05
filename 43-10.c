#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

#define SIZE 500



void read(char* name)
{
    FILE* f;
    f = fopen(name, "rb+");
    float sum = 0; 
    float i;
    while (!feof(f))
    {
        fread(&i, sizeof(float), 1, f);
        printf("%f", i);
    }
    
    fclose(f);
}

// C:\\Users\\Igor\\Desktop\\data.dat

int main()
{
    
    char name[500] = { 0 };
    float x[5] = { 1, 2, 3, 4, 5};
    scanf("%s", &name);
    
 
    read(name);

   
}
