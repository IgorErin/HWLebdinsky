#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

#define SIZE 500

int main()
{
    int num;
    scanf("%d", &num);
    int x[13] = { 1000, 900, 500, 400, 100,90, 50, 40, 10, 9, 5, 4, 1 };
    char y[13][3] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };


    

    for (int i = 0; i < 13; i++)
    {
        while (num >= x[i])
        {
            printf("%s", y[i]);
            num -= x[i];
        }
    }
}
