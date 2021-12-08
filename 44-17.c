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


void delNElement(struct node** pp, int n)
{

    struct node* p = *pp;
    if (p == 0)
    {
        return;
    }
    if (n == 0)
    {
        *pp = p->n;
        free(p);
    }
    if (n > 0)
    {
        int i = 0;
        while (p->n != 0)
        {
            
            if (i == n - 1)
            {
                struct node* p_del = p->n;
                p->n = (p->n)->n;
                free(p_del);
                break;
            }
            p = p->n;
            i++;
        }
        return;
    }

}


int main()
{
    struct node* p = createRec();
    printNode(p);
    struct node lol;
    
    delNElement(&p, 0);
    printNode(p);
    

}
