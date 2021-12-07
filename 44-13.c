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


struct node* revers(struct node* p_first, struct node* p_copy)
{
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->d = p_first->d;
    p->n = p_copy;

    

    if (p_first->n == 0)
    {
        return p;
    }
    else
    {
        return revers(p_first->n, p);
    }
}

struct node* copyRevers(struct node* p_first)
{
    struct node* p_new = (struct node*)malloc(sizeof(struct node));
    if (p_first != 0)
    {
        p_new->d = p_first->d;
        p_new->n = 0;
        return revers(p_first->n, p_new);
    }
    else
    {
        return 0;
    }
}


int main()
{
    struct node* p = createRec();
    printNode(p);
    struct node lol;
    
    
    printNode(copyRevers(p));
    

}
