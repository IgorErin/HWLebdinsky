#define _CRT_SECURE_NO_WARNINGS // accepte
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


struct node* copyRec(struct node* p_first)
{
    if (p_first == 0)
    {
        return 0;
    }
    else
    {
        struct node* p_new = (struct node*)malloc(sizeof(struct node));
        p_new->d = p_first->d;
        p_new->n = copyRec(p_first->n);
        return p_new;
    }

}


int main()
{
    struct node* p = createRec();
    printNode(p);
    
    printNode(copyRec(p));
    

}
