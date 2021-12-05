#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

#define SIZE 500

int main()
{
    char s[500] = { 0 };
    char *src = s;
    
    scanf("%s", &s);

    int sum = 0;
    while (*src) {
        while (*src && !isdigit(*src))
            ++src;
        sum++;
        while (*src && isdigit(*src))
            ++src;
    }

    printf("%d", sum);
}
