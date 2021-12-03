#define _CRT_SECURE_NO_WARNINGS //interpolycia/
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

#define SIZ 500

struct counter_pair {
    int symbol_code;    
    int symbol_count;   
};




int main() {

    struct counter_pair cp[128];        
    char* rc;           
    int j, len;

    
    for (j = 0; j < 128; j++)
    {
        cp[j].symbol_code = j;  
        cp[j].symbol_count = 0; 
    }


    FILE* in;
    char ch;

    in = fopen("C:\\Users\\Igor\\Desktop\\t.txt", "r+");
   
    
    while (!feof(in))
    {
        fscanf(in, "%c", &ch);
        cp[ch].symbol_count += 1;
    }

    fclose(in);
    
    for (j = 0; j < 128; j++)
    {
        if (cp[j].symbol_count == 0)
        {
            continue;
        }
        printf("simbol %c count =  %d \n", cp[j].symbol_code, cp[j].symbol_count);
    }

}
