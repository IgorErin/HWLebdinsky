#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

struct bnode
{
    int d;
    int key;
    struct bnode* l, * r;
};


struct bnode* init(int data, struct bnode* l, struct bnode* r)
{
    struct bnode* p = (struct bnode*)malloc(sizeof(struct bnode));
    p->d = data;
    p->l = l;
    p->r = r;
    p->key = data;
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
    printf("%d \n", p->d);
    print(p->l, n + 3);
}

struct bnode* search(struct bnode* p, int key)
{

    if (p == 0)
    {
        return 0;
    }
    
    if (p->key == key)
    {
        return p;
    }
    else if (p->key > key)
    {
        return search(p->l, key);
    }
    else
    {
        return search(p->r, key);
    }
}

void insert(struct bnode** p, int key, int dat)
{
    if ((*p) == 0)
    {
        (*p) = (struct bnode*)malloc(sizeof(struct bnode));
        (*p)->key = key;
        (*p)->d = dat;
        (*p)->l = 0;
        (*p)->r = 0;
        return;
    }
    else
    {
        if ((*p)->key > key)
        {
            insert(&(**p).l, key, dat);
        }
        else
        {
            insert(&(**p).r, key, dat);
        }
    }
}



void del(struct bnode* p, int key)
{
    if (p == 0)
    {
        return 0;
    }
    struct bnode* p_save;
    while (p->key != key)
    {
        p_save = p;
        if (p->key > key)
        {
            p = p->l;
        }
        else
        {
            p = p->r;
        }
    }

    
}

int main()
{

    struct bnode* p = init(10, init(7, init(6,init(5,0,0),0), init(5, 0, 0)), init(15, init(12, 0, 0), init(18, 0, 0)));
    print(p, 0);
    printf("%d", search(p, 5)->d);

}
