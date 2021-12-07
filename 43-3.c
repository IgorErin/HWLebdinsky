#define _CRT_SECURE_NO_WARNINGS //interpolycia/
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>



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

    in = fopen(s, "rb");
    out = fopen(s1, "wb+");
    

    while (!feof(in))
    {
        fread(&ch, sizeof(char), 1, in);
        fwrite(&ch, sizeof(char), 1, out);
        //printf("%c", ch);
    }

    fclose(in);
    fclose(out);

}
