#define _CRT_SECURE_NO_WARNINGS //38.2

#include<stdio.h>
#include<math.h>


int f(char x, char y) {
    return x;
}

int max(int x, int y) {
    
    if (x % 2 == 1 && y % 2 == 0) {
        return 1;
    }
    if (x % 2 == 0 && y % 2 == 1) {
        return -1;
    }
    if (x % 2 == y % 2 && x % 2 == 1) {
        if (x < y) {
            return 1;
        }
        if (x > y) {
            return -1;
        }
    }
    if (x % 2 == y % 2 && x % 2 == 0) {
        
        if (x > y) {
            return 1;
        }
        if (x < y) {
            return -1;

        }
    }
}



void fun(int *m,int n, int (*x)(int, int) ) 
{
    
    for (int i = 0; i < n; i++) {
        printf("%d ", m[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
             printf("%d v %d \n", m[j], m[j + 1]);


            if ((*x)(m[j], m[j + 1]) > 0) {
                printf("%d -> %d\n", m[j], m[j + 1]);

                int c = m[j];
                m[j] = m[j + 1];
                m[j + 1] = c;
                for (int i = 0; i < n; i++)
                {
                    printf("%d ", m[i]);
                }
                printf("\n");
            }



        }

    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", m[i]);
    }
    
}




int main()
{
    int x[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    fun(&x, 15, &max);
    printf("\n%d", max(6,2));
}


