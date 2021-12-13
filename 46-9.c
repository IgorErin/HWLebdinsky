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



struct bnode* left(struct bnode* p)
{
    if (p == 0)
    {
        return 0;
    }
    if (p->l == 0)
    {
        return 0;
    }
    if (p->l->l == 0)
    {
        return p;
    }
    if (p->l->l != 0)
    {

        return left(p->l);
    }
}

void fun(struct bnode* tree)
{
    struct bnode* p = left(tree);
    struct bnode* p_del = p->l;
    p->l = p_del->r;
    free(p_del);
}

int main()
{

    struct bnode* p = init(1, init(2, init(4, 0, init(9, 0, 0)), init(5, init(10, 0, 0), init(11, 0, 0))), init(3, init(6, init(12, 0, 0), init(13, 0, 0)), init(7, init(14, 0, 0), init(15, 0, 0))));
    print(p, 0);
    printf("\n\n\n");
    fun(p);

    printf("\n\n\n");
    print(p, 0);

}
