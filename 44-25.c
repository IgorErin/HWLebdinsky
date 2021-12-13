#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

struct node
{
    int d;
    struct node* nl, * nr;
};

void printNode(struct node* f)
{
    struct node* p = f;

    while (p != 0)
    {
        printf("%d \n", p->d);
        p = p->nr;
    }
    printf("-------\n");
}

struct node* add(int data, struct node* ex_p)
{
    struct node* p = (struct node*)malloc(sizeof(struct node));

    p->nr = 0;
    p->nl = ex_p;
    ex_p->nr = p;
    p->d = data;

    return p;
}

struct node* create()
{
    struct node* p_new = 0;
    struct node** p_save = p_new;
    int data;

    printf("0 if last");
    scanf("%d", &data);

    if (data != 0)
    {
        struct node* p_first = (struct node*)malloc(sizeof(struct node));
        p_first->d = data;
        p_first->nl = 0;
        p_first->nr = 0;
        p_new = p_first;
        p_save = p_new;

        scanf("%d", &data);
    }
    while (data != 0)
    {

        p_new = add(data, p_new);
        scanf("%d", &data);
    }
    return p_save;
}

struct node* copyDList(struct node* f)
{
    if (f == 0)
    {
        return 0;
    }

    struct node* p = f;
    struct node* p_save;

    struct node* p_copy = (struct node*)malloc(sizeof(struct node));
    p_copy->nl = 0;
    p_save = p_copy;

    while (p->nr != 0)
    {
        if (p->nr == 0)
        {
            break;
        }
        p_copy->d = p->d;
        struct node* p_new = (struct node*)malloc(sizeof(struct node));
        p_copy->nr = p_new;
        p_new->nl = p_copy;
        p_copy = p_new;
        p = p->nr;
    }

    p_copy->d = p->d;
    p_copy->nr = 0;
    return p_save;
}


int main()
{
    struct node* p2;
    p2 = create();
    printNode(p2);
    p2 = copyDList(p2);
    printNode(p2);
}
