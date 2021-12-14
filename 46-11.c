#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>


struct bnode
{
    int d;
    struct bnode* l, * r, *back;
};

struct bnode* init(int data, struct bnode* l, struct bnode* r)
{
    struct bnode* p = (struct bnode*)malloc(sizeof(struct bnode));
    p->back = 0;
    p->d = data;
    p->l = l;
    p->r = r;
    l->back = p;
    r->back = p;
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


struct bnode* fun(struct bnode* p)
{
    if (p == 0)
    {
        return 0;
    }
    if (p->l != 0)
    {
        if (p->l->l != 0 || p->l->r != 0)
        {
            return fun(p->l);
        }
    }
    else if (p->r != 0)
    {
        if (p->r->l != 0 || p->r->r != 0)
        {
            return fun(p->r);
        }
        else
        {
            return p;
        }
    }

}

void del_left_list(struct bnode* p)
{
    struct bnode* p_to_del = fun(p);

    if (p_to_del->l != 0)
    {
        free(p_to_del->l);
        p_to_del->l = 0;
    }
    else
    {
        free(p_to_del->r);
        p_to_del->r = 0;
    }

}



int main()
{

    struct bnode* p = init(1, init(2, init(4, init(8, 0, 0), init(9, 0, 0)), init(5, init(10, 0, 0), init(11, 0, 0))), init(3, init(6, init(12, 0, 0), init(13, 0, 0)), init(7, init(14, 0, 0), init(15, 0, 0))));
    print(p, 0);
    printf("\n\n\n");
    del_left_list(p);

    printf("\n\n\n");
    print(p, 0);

}
