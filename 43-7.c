#define _CRT_SECURE_NO_WARNINGS //interpolycia
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

#define SIZ 500

// C:\\Users\\Igor\\Desktop\\t.txt

int sums(char* src)
{
    int sum = 0;
    while (*src) {
        while (*src && !isdigit(*src))
            ++src;
        sum += atoi(src);
        while (*src && isdigit(*src))
            ++src;
    }

    return sum;

}

int main()
{
    char* s = (char*)malloc(SIZ * sizeof(char) + 1);
    char* s1 = (char*)malloc(SIZ * sizeof(char) + 1);
    char* s2 = (char*)malloc(SIZ * sizeof(char) + 1);

    scanf("%s", s);
    scanf("%s", s1);
    
    FILE* in, * out;

    in = fopen(s, "r+");
    out = fopen(s1, "w+");
    
    while (!feof(in))
    {
        int sum = 0;
        int i;
        fgets(s2, SIZ, in);
        sum += sums(s2);
        fprintf(out, "%d\n", sum);
       
    }
    
    fclose(in);
    fclose(out);
}
