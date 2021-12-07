#define _CRT_SECURE_NO_WARNINGS 
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
    struct node* p = (struct node*)malloc(sizeof(struct node));
    int dat;

    printf("0 if this is last");
    scanf("%d", &dat);
    p->d = dat;

    if (dat != 0)
    {
        p->n = createRec();
    }
    else {
        p->n = 0;
    }
    return p;
}


struct node *copyRec(struct node* p_first)
{
    struct node* p = (struct node*)malloc(sizeof(struct node));
    if (p_first != 0)
    {
        p->d = p_first->d;
    }
    else
    {
        printf("empty list");
    }

    if (p_first->n != 0)
    {
        p->n = copyRec(p_first->n);
    }
    else
    {
        p->n = 0;
    }
    return p;

}

int main()
{
    struct node* p = createRec();
    printNode(p);
    
    printNode(copyRec(p));
    

}
