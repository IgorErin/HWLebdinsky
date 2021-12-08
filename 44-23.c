#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

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

struct node* add(struct node* p_now, int dat)
{
    struct node* p_new = (struct node*)malloc(sizeof(struct node));

    p_new->n = 0;
    p_new->d = dat;
    p_now->n = p_new;

    return p_new;
}

struct node* create(struct node* p1, struct node* p2)
{
    struct node* p;
    struct node* p_first;
    if (p1 == 0 && p2 == 0)
    {
        return 0;
    }
    else if (p1 == 0 && p2 != 0)
    {
        return p2;
    }
    else if (p2 == 0 && p1 != 0)
    {
        return p1;
    }
    if (p1->d > p2->d)
    {
        p = p2;
        p2 = p2->n;
        p_first = p;
    }
    else
    {
        p = p1;
        p1 = p1->n;
        p_first = p;
    }

    while (p1 != 0 && p2 != 0)
    {
        if (p1->d > p2->d)
        {
            p->n = p2;
            p = p2;
            p2 = p2->n;
        }
        else
        {
            p->n = p1;
            p = p1;
            p1 = p1->n;
        }
    }

    while (p1 != 0)
    {
        p->n = p1;
        p = p1;
        p1 = p1->n;
    }
    while (p2 != 0)
    {
        p->n = p2;
        p = p2;
        p2 = p2->n;
    }
   
    return p_first;;
}

struct node* createRec()
{
    struct node* p = (struct node*)malloc(sizeof(struct node));
    int dat;

    printf("111 if this is last");
    scanf("%d", &dat);
    p->d = dat;

    if (dat != 111)
    {
        p->n = createRec();
    }
    else {
        p->n = 0;
    }
    return p;
}

struct node* sort(struct node* p_first)
{   
    if (p_first == 0)
    {
        return 0;
    }
    else if (p_first->n == 0)
    {
        return p_first;
    }
    struct node* b = p_first->n;
    struct node* c = p_first;
    while (b != 0 && b->n != 0)
    {
        c = c->n;
        b = (b->n)->n;
        printf("1");
    }
    b = c->n;
    c->n = 0;
    printNode(b);
    printf("------\n");
    printNode(p_first);
    printf("\n");
    return create(sort(p_first), sort(b));
    
}

int main()
{
    
    struct node* p1 = createRec();
    printf("---------\n");
    struct node* p2;
    p2 = sort(p1);
    printNode(p2);
    
}
