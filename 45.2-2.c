#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

struct node
{
    struct node* n;
    int d;
};

struct queue
{
    struct node* p1,* p2;
};

void init(struct queue* p)
{
    p->p1 = 0;
    p->p2 = 0;

}

void add(struct queue* p, int data)
{
    struct node* p_new = (struct node*)malloc(sizeof(struct node));

    p_new->d = data;

    if (p->p1 == 0)
    {
        printf("init");
        p->p1 = p_new;
        p->p2 = p_new;
        
    }

    else
    {
        p->p2->n = p_new;
        p->p2 = p_new;
        
    }
}

int out(struct queue* p)
{
    if (p->p2 == 0)
    {
        printf("empty");
        return 0;
    }
    else if (p->p1 == p->p2)
    {
        int out = p->p1->d;
        free(p->p1);
        p -> p1 = 0;
        p -> p2 = 0;
        return out;
    }
    else
    {
        int out = p->p1->d;
        
        struct node* p_for_del = p->p1;

        p->p1 = p->p1->n;

        free(p_for_del);

        return out;
    }
}



int main()
{
    struct queue x;
    init(&x);

    for (int i = 0; i < 10; i++)
    {
        add(&x, i);

    }
    printf("-----");
    //printNode(&x);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", out(&x));
    }

    for (int i = 0; i < 10; i++)
    {
        add(&x, i);

    }
    
    
}
