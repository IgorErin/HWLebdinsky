#define _CRT_SECURE_NO_WARNINGS //accepte
#include<stdio.h>
#include<math.h>
#include <time.h>

#define SIZE 500

struct node
{
    int d;
    struct node* n;
};


void printNode(struct node* f)
{
    struct node* p = f;

    while (p != 0)
    {
        printf("%d \n", p->d);
        p = p->n;
    }

}



struct node* createRec()
{
    struct node* p = 0;
    int dat;

    printf("0 if this is last");
    scanf("%d", &dat);
    if (dat != 0)
    {
        p = (struct node*)malloc(sizeof(struct node));
        p->d = dat;

        
        p->n = createRec();
        
        
        
    }

    return p;
}



int main()
{
    printNode(createRec());

    

}
