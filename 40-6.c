#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

#define SIZE 500

void rev(char *s1, char *s11)
{
    int a = 0;
    for (int i = 499; i >= 0; i--)
    {

        if (s1[i] == 0)
        {
            continue;
        }
        else
        {
            s11[a] = s1[i];
            a++;

        }
    }
}

int main()
{
    char s1[500] = { 0 };
    char s2[500] = { 0 };

    char s11[500] = { 0 };
    char s12[500] = { 0 };

    char output[500] = { 0 };

    scanf("%s", &s1);
    scanf("%s", &s2);

    rev(s1, s11);
    rev(s2, s12);
}
