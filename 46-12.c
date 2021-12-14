#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

struct bnode
{
    int d;
    struct bnode* l, * r, * back;
};

struct bnode* init(int data, struct bnode* l, struct bnode* r)
{
    struct bnode* p = (struct bnode*)malloc(sizeof(struct bnode));
    p->back = 0;
    p->d = data;
    p->l = l;
    p->r = r;
    if (l != 0)
    {
        l->back = p;
    }
    if (r != 0)
    {
        r->back = p;
    }
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

void fun(struct bnode* p, struct bnode* p_del)
{
    if (p == 0)
    {
        return 0;
    }
    if (p_del == 0)
    {
        return 0;
    }
    if (p_del->back->l == p_del)
    {
        if (p_del->l != 0)
        {
            p_del->back->l = p_del->l;
        }
        else if (p_del->r != 0)
        {
            p_del->back->l = p_del->r;
        }
    }
    else
    {
        if (p_del->l != 0)
        {
            p_del->back->r = p_del->l;
        }
        else if (p_del->r != 0)
        {
            p_del->back->r = p_del->r;
        }
    }
    free(p_del);
}


int main()
{

    struct bnode* p = init(1, init(2, init(4, 0, init(9, 0, 0)), init(5, init(10, 0, 0), init(11, 0, 0))), init(3, init(6, init(12, 0, 0), init(13, 0, 0)), init(7, init(14, 0, 0), init(15, 0, 0))));
    print(p, 0);
    printf("\n\n\n");

    fun(p, p->l->r);
    printf("\n\n\n");
    print(p, 0);

}
