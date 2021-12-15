#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

struct bnode
{
    int d;
    struct bnode* l, * r;
};

struct unode
{
    int d;
    struct unode* l, * r, *back;
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
//------------------------------------------------------------------
int total(struct bnode* p)
{
    if (p == 0)
    {
        return 0;
    }
    return p->d + total(p->l) + total(p->r);
}
//------------------------------------------------------------------
int height(struct bnode* p, int count)
{
    if (p == 0)
    {
        return count - 1;
    }
    int left = height(p->l, count + 1);
    int right = height(p->r, count + 1);
    return (left > right ? left : right);
}
//------------------------------------------------------------------
int min(struct bnode* p)
{
    if (p->l == 0 && p->r == 0)
    {
        return p->d;
    }
    else if (p->l != 0 && p->r == 0)
    {
        int left = min(p->l);
        return p->d > left ? left : p->d;
    }
    else if (p->r != 0 && p->l == 0)
    {
        int right = min(p->r);
        return p->d > right ? right : p->d;
    }
    else
    {
        int right = min(p->r);
        int left = min(p->l);
        left = left > right ? right : left;
        return p->d > left ? left : p->d;
    }
}
//------------------------------------------------------------------
struct bnode* find(struct bnode* p, int dat)
{
    if (p == 0)
    {
        return 0;
    }
    if (p->d == dat)
    {
        return p;
    }
    struct bnode* p_return;
    p_return = find(p->r, dat);
    if (p_return)
    {
        return p_return;
    }
    p_return = find(p->l, dat);
    if (p_return)
    {
        return p_return;
    }
    return 0;
}
//------------------------------------------------------------------
void destroy(struct bnode* p)
{
    if (p == 0)
    {
        return;
    }
    destroy(p->l);
    destroy(p->r);
    free(p);
}

//------------------------------------------------------------------
struct bnode* copy(struct bnode* p)
{
    if (p != 0)
    {
        struct bnode* p_new = (struct bnode*)malloc(sizeof(struct bnode));
        p_new->l = copy(p->l);
        p_new->r = copy(p->r);
        p_new->d = p->d;
        return p_new;
    }
    else
    {
        return 0;
    }
}

struct unode* ucopy(struct unode* p, struct unode* p_pred)
{
    if (p != 0)
    {
        struct unode* p_new = (struct unode*)malloc(sizeof(struct unode));
        p_new->back = p_pred;
        p_new->l = copy(p->l, p_new);
        p_new->r = copy(p->r, p_new);
        p_new->back = p_pred;
    }
    else
    {
        return 0;
    }
}

//------------------------------------------------------------------
struct bnode* reflect(struct bnode* p)
{
    if (p != 0)
    {
        struct bnode* p_new = (struct bnode*)malloc(sizeof(struct bnode));
       
        p_new->l = reflect(p->r);
        p_new->r = reflect(p->l);
        p_new->d = p->d;
        return p_new;
    }
    else
    {
        return 0;
    }
}
//------------------------------------------------------------------
int for_alt_sum(struct bnode* p, int left)
{
    if (p == 0)
    {
        return 0;
    }
    if (left)
    {
        return -(p->d) + for_alt_sum(p->l, 1) + for_alt_sum(p->r, 0);
    }
    else
    {
        return +(p->d) + for_alt_sum(p->l, 1) + for_alt_sum(p->r, 0);
    }
    
}

int alt_sum(struct bnode* p)
{
    if (p == 0)
    {
        return 0;
    }
    return for_alt_sum(p->r, 0) + for_alt_sum(p->l, 1);
    
}
//------------------------------------------------------------------



struct bnode* input()
{
    char c;
    int in;
    scanf("%d", &in);
    
    if (!in)
    {
        return 0;
    }
    
    struct bnode* p_new = (struct bnode*)malloc(sizeof(struct bnode));
    p_new->d = in;
    scanf("%c", &c);
    p_new->l = input();
    scanf("%c", &c);
    p_new->r = input();
    scanf("%c", &c);
    return p_new;
}





int main()
{

    struct bnode* p = init(1, init(2, init(4, 0, init(9, 0, 0)), init(5, init(10, init(20,init(-2,0,0),0), 0), init(11, 0, 0))), init(3, init(6, init(12, 0, 0), init(13, 0, 0)), init(7, init(14, 0, 0), init(15, 0, 0))));
    print(p, 0);
    printf("\n\n");
    printf("\n\n");
    struct bnode* l = input();
    print(l, 0);
    

    

}
