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
    printf("-------\n");
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
    else
    {
        p->n = 0;
    }
    return p;
}


void delLAstForAll(struct node ** pp)
{
    if (*pp == 0)
    {
        printf("erorr");
        return;
    }

    if ((*pp)->n == 0)
    {
        free(*pp);
        *pp = 0;
        return;
    }


    struct node* p = *pp;
    while ((p->n)->n != 0)
    {
        
        p = p->n;
    }

    free(p->n);
    p->n = 0;
    return;
}


int main()
{
    struct node* p = createRec();
    printNode(p);
    struct node lol;
    
    delLAstForAll(&p);
    printNode(p);
    

}
