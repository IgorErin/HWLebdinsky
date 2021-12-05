#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

#define SIZE 500

int main()
{
    char as[500] = { 0 };
    char bs[500] = { 0 };
    char cs[500] = { 0 };

    scanf("%s", &as);
    scanf("%s", &bs);
    scanf("%s", &cs);

    for (int i = 0; i < 500; i++)
    {
        if (as[i] != 0)
        {
            for (int j = 0; j < 500; j++)
            {
                if (as[i] == bs[j])
                {
                    as[i] = cs[j];
                }
            }
        }
    }

    printf("%s", as);

}
