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

#define NODE(TYPE) \
struct Node_##TYPE \
{ \
TYPE d; \
struct Node_##TYPE *n; \
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
void add(struct node** f, int i)
{
    struct node* p = (struct node*)malloc(sizeof(struct node));

    p->n = *f;
    p->d = i;
    *f = p;
}


struct node* addInWithPointer(struct node* f, int n, int dat)
{
    struct node* p = f;
    int i = 0;
    struct node* p_new = (struct node*)malloc(sizeof(struct node));
    p_new->d = dat;

    if (n == 0)
    {
        p_new->n = f;
        return p_new;
    }

    while (p != 0)
    {
        if (i == n - 1)
        {
            p_new->n = p->n;
            p->n = p_new;
            return f;
        }
        i++;
        p = p->n;
    }
}

void addInWithPointerToPointer(struct node** f, int n, int dat)
{
    
    struct node* p = *f;
    struct node** pp = f;
    struct node* p_new = (struct node*)malloc(sizeof(struct node));

    p_new->d = dat;

    int i = 0;

    while (p != 0)
    {
        if (i == n)
        {
            p_new->n = (*pp);
            (*pp) = p_new;
            
        }
       
        
        i++;
        p = p->n;
        pp = &p;
        
    }
    printf("\n");
}

int main()
{
    struct node first;
    first.d = 0;
    first.n = 0;

    struct node* p_first = &first;
    struct node** pp_first = &p_first;

    for (int i = 1; i < 10; i++)
    {
        add(pp_first, i);
    }


    //printNode(p_first);
    //printf("%d \n", p_first);
    printf("%d\n", p_first);
    addInWithPointerToPointer(pp_first, 2, -1);
    printf("%d\n", p_first);
    printf("\n----\n");
    //printf("%d", p_first);
    printNode(p_first);

}
