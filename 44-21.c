#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

#define SIZE 500

int x[40];

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
                *pp = p->n;
                printf("%d\n", p_del->d);
                free(p_del);
                break;
            }
            p = p->n;
            i++;
        }
        return;
    }

}

struct node* add(struct node* p_now, int index)
{
    struct node* p_new = (struct node*)malloc(sizeof(struct node));

    p_new->n = 0;
    p_new->d = x[index];
    p_now->n = p_new;

    return p_new;
}


struct node* createRingList()
{
    int dat;
    struct node* p = (struct node*)malloc(sizeof(struct node));
    struct node* p_now = p;

    p->d = x[0];
    p->n = 0;

    for (int i = 1 ; i< 40; i++)
    {
        p_now = add(p_now, i);
    }

    printNode(p);

    p_now->n = p;
    
    return p;
}


int main()
{
    
    for (int i = 0; i < 40; i++)
    {
        x[i] = 1 + i;
    }
    
    struct node* p = createRingList();
    for (int i = 0; i < 40; i++) {
        delNElement(&p, 4);
    }
}
