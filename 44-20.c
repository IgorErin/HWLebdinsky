#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

#define SIZE 500

int x[999];

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
    static int stat = 0;
    struct node* p = (struct node*)malloc(sizeof(struct node));
    int dat;

    p->d = x[stat];
    stat += 1;

    if (x[stat] != 0)
    {
        p->n = createRec();
    }
    else
    {
        p->n = 0;
    }
    return p;
}
int fun(int n, struct node* p)
{
    if (p->d % n == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node* delElmentWhitPointer(struct node* p_first, int par, int (*fun)(int, struct node*))
{
    struct node* p = p_first;

    struct node* p_first_del = p;
    struct node* p_del;

    if (p == 0)
    {
        return 0;
    }
    p = p->n;
    while (p != 0 && p->n != 0)
    {
        if (fun(par, p->n))
        {
            p_del = p->n;
            p->n = (p->n)->n;
            free(p_del);
        }
        p = p->n;
    }
    return p_first_del->n;
    
}
struct node* resheto(struct node* p_first)
{
    struct node* p = p_first;
    while (p != 0 && p->n != 0)
    {
       p = delElmentWhitPointer(p, p->d, fun);
    }
}

int main()
{
    
    for (int i = 0; i < 999; i++)
    {
        x[i] = 2 + i;
    }
    
    struct node* p = createRec();
    //printNode(p);
    resheto(p);
    printNode(p);


}
