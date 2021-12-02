#define _CRT_SECURE_NO_WARNINGS //interpolycia
#include<stdio.h>
#include<math.h>
#include<time.h>


#define SIZ 500


// C:\\Users\\Igor\\Desktop\\t.txt
int main()
{
    char* s = (char*)malloc(SIZ * sizeof(char) + 1);
    char* s1 = (char*)malloc(SIZ * sizeof(char) + 1);

    scanf("%s", s);
    scanf("%s", s1);

    FILE* in, * out;
    char ch;

    in = fopen(s, "r");
    out = fopen(s1, "r+");

    while (!feof(out))
    {
        getc(out);
    }
    while (!feof(in))
    {
        ch = getc(in);
        putc(ch, out);
    }

    fclose(in);
    fclose(out);
}
