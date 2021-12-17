#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

struct dsnode
{
    int d;
    int key;
    struct bnode* l, * r;
};


struct dsnode* init(int data, struct dsnode* l, struct dsnode* r)
{
    struct dsnode* p = (struct dsnode*)malloc(sizeof(struct dsnode));
    p->d = data;
    p->l = l;
    p->r = r;
    return p;
}

void print(struct dsnode* p, int n)
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
    printf("%d, kye = %d\n", p->d, p->key);
    print(p->l, n + 3);
}
//------------------------------------------------------------------
int digit(int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        x /= 2;
    }

    return x % 2;
}
//-------------------------------------------------------------------


struct dsnode* search(struct dsnode* p, int key, int count)
{
    if (p == 0)
    {
        return 0;
    }
    if (key == p->key)
    {
        return p;
    }
    else
    {
        int n = digit(key, count);
        if (n == 0)
        {
            return search(p->l, key, count + 1);
        }
        else
        {
            return search(p->r, key, count + 1);
        }
    }
}
//------------------------------------------------------------------------------------
void insert(struct dsnode* p, int dat, int key)
{
    if (p == 0)
    {
        return 0;
    }

    int a = 1;
    struct dsnode* p_save ;

    while (key > p->key)
    {
        p_save = p;
        if (digit(key, a))
        {
            p = p->r;
        }
        else
        {
            p = p->l;
        }
        if (p == 0)
        {
            break;
        }
        a++;
    }

    struct dsnode* p_new = (struct dsnode*)malloc(sizeof(struct dsnode));
    p_new->l = 0;
    p_new->r = 0;
    p_new->d = dat;
    if (digit(key, a))
    {
        p_save->r = p_new;
    }
    else
    {
        p_save->l = p_new;
    }
}
//------------------------------------------------------------------------
void del(struct dsnode* p, int key)
{

    if (p == 0)
    {
        return 0;
    }

    int a = 0;
    struct dsnode* p_save;

    while (key > p->key)
    {
        a++;
        p_save = p;
        if (digit(key, a))
        {
            p = p->r;
        }
        else
        {
            p = p->l;
        }
    }
    if (p == 0)
    {
        return;
    }
    if (digit(key, a))
    {
        free(p_save->r);
        p_save->r = 0;
    }
    else
    {
        free(p_save->l);
        p_save->l = 0;
    }

}



int main()
{

    struct bnode* p = init(1, init(2, init(4, 0, init(9, 0, 0)), init(5, init(10, init(20,init(-2,0,0),0), 0), init(11, 0, 0))), init(3, init(6, init(12, 0, 0), init(13, 0, 0)), init(7, init(14, 0, 0), init(15, 0, 0))));
    print(p, 0);
    printf("\n\n");
    printf("\n\n");
}
