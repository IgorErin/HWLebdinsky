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
    
    struct node* p = (struct node*)malloc(sizeof(struct node));
    struct node* p_now = p;


    if (p1->d < p2->d)
    {
        p->d = p1->d;
        p1 = p1->n;
    }
    else
    {
        p->d = p2->d;
        p2 = p2->n;
    }

    
    p->n = 0;

    while (p1 != 0 || p2 != 0)
    {
        if (p1 == 0 && p2 == 0)
        {
            break;
        }
        else if (p1 == 0 && p2 != 0)
        {
            
            p_now = add(p_now, p2->d);
            p2 = p2->n;
        }
        else if (p1 != 0 && p2 == 0)
        {
            
            p_now = add(p_now, p1->d);
            p1 = p1->n;
        }
        else if (p1->d < p2->d)
        {
            
            p_now = add(p_now, p1->d);
            p1 = p1->n;
        }
        else if (p1->d >= p2->d)
        {
            
            p_now = add(p_now, p2->d);
            p2 = p2->n;
        }
        
    }
    
    return p;
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



int main()
{
    
    struct node* p1 = createRec();
    printf("---------\n");
    struct node* p2 = createRec();
    struct node* p_out = create(p1, p2);
    printNode(p_out);
    
}
