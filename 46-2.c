#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>


struct bnode
{
    int d;
    struct bnode* l, * r;
};

struct bnode* init(int data, struct bnode* l, struct bnode* r)
{
    struct bnode* p = (struct bnode*)malloc(sizeof(struct bnode));
    p->d = data;
    p->l = l;
    p->r = r;
    return p;
}

void print(struct bnode* p, int n)
{
    if (p == 0)
    {
        return;
    }
    print(p->r, n + 3);
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
    printf("%d\n", p->d);
    print(p->l, n + 3);
}


int fun2(struct bnode* p)
{
    int sum = 0;
    if (p == 0)
    {
        return 0;
    }
    if (p->r != 0)
    {
        if (p->r->r != 0)
        {
            sum++;
        }
        if (p->r->l != 0)
        {
            sum++;
        }
    }
    if (p->l != 0)
    {
        if (p->l->r != 0)
        {
            sum++;
        }
        if (p->l->l != 0)
        {
            sum++;
        }
    }
    return sum;
}

int main()
{

    struct bnode* p = init(1, init(2, init(4, 0, 0), init(5, 0, 0)), init(3, init(6, 0, 0), 0));
    print(p, 0);
    printf("%d", fun(p, 0));


}
