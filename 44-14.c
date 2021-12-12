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


struct node* reversForList(struct node* p_first, struct node* p_second)
{
    if (p_second != 0)
    {
        struct node* p_new = p_second->n;
        p_second->n = p_first;

        return reversForList(p_second, p_new);
    }
    else
    {
        return p_first;
    }
}

struct node* revers(struct node* p)
{
    return reversForList(0, p);
}



int main()
{
    struct node* p = createRec();
    printNode(p);
    struct node lol;
    
    
    printNode(reversForList(0, p));
    

}
