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
int fun(struct node* p)
{
    if (p->d % 2 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void delNElement(struct node** pp, int (*fun)(struct node *))
{

    struct node** p = pp;
    if (*p == 0)
    {
        return;
    }
    else
    {
        int i = 0;
        while ((*p)->n != 0)
        {
            
            if (fun(*p))
            {
                struct node* p_del = *p;
                (*p) = (*p)->n;
                free(p_del);
            }
            i++;
            p = &((**p).n);
        }
    }
}
struct node* delElmentWhitPointer(struct node* p_first, int (*fun)(struct node*))
{
    struct node* p = p_first;

    struct node* p_first_del = p_first;
    struct node* p_del;

    if (p == 0)
    {
        return 0;
    }
    if (fun(p))
    {
        p_first_del = p->n;
        p_del = p;
        p = p->n;
        free(p_del);
       

    }
    while (p != 0 && p->n != 0)
    {
        
        if (fun(p->n))
        {
            p_del = p->n;
            p->n = (p->n)->n;
            free(p_del);
        }
        p = p->n;
    }
    return p_first_del;
}


int main()
{
    struct node* p = createRec();
    printNode(p);
    struct node lol;
    
    p = delElmentWhitPointer(p, fun);
    printNode(p);
    

}
