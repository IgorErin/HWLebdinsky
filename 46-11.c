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
//---------------------------------------------------------------------
struct bnode* fun_for_3(struct bnode* p)
{
    if (p == 0)
    {
        return 0;
    }
    if (p->l == 0)
    {
        return 0;
    }
    
    struct bnode* p_save,* p_for_move;
    p_save = p->l;
    p_for_move = p->r;
    p->l = p_save->l;
    p->r = p_save->r;
    p->back = p_save;
    p_save->l = p;
    p_save->r = p_for_move;

    p->back = 0;
    p->r->back = p;
    p->l->back = p;
    p_save->r->back = p_save;
    return p_save;
}


//---------------------------------------------------------------------
void fun_for_4(struct bnode** p)
{
    struct bnode* b, * a = *p;
    b = a->r;
    *p = b;
    a->r = b->l;
    b->l = a;

    b->back = 0;
    a->back = b;
    a->r->back = a;

}
//---------------------------------------------------------------------
struct bnode* left_yzel(struct bnode* p)
{
    if (p == 0)
    {
        return 0;
    }
    if (p->l == 0)
    {
        return p;
    }
    if (p->l != 0)
    {

        return left_yzel(p->l);
    }

}



void fun_for_8(struct bnode* p, int data)
{
    struct bnode* p_left = left_yzel(p);
    struct bnode* p_new = init(data, 0, 0);

    p_new->back = p_left;
    p_left->l = p_new;

}


//---------------------------------------------------------------------


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

void fun_for_9(struct bnode* p)
{
    struct bnode* p_left = left(p);
    struct bnode* p_del = p_left->l;
    p_left->l = p_del->r;
    p_del->r->back = p_left;
    free(p_del);
    
}

//-----------------------------------------

struct bnode* left_list(struct bnode* p)
{
    if (p == 0)
    {
        return 0;
    }
    if (p->l != 0)
    {
        if (p->l->l != 0 || p->l->r != 0)
        {
            return left_list(p->l);
        }
    }
    else if (p->r != 0)
    {
        if (p->r->l != 0 || p->r->r != 0)
        {
            return left_list(p->r);
        }
        else
        {
            return p;
        }
    }

}

void del_left_list(struct bnode* p)
{
    struct bnode* p_left = left_list(p);
    if (p_left->l != 0)
    {
        free(p_left->l);
        p_left->r = 0;
    }
    else if (p_left->r != 0)
    {
        free(p_left->r);
        p_left->r = 0;
    }
}




int main()
{

    struct bnode* p = init(1, init(2, init(4, 0, init(9, 0, 0)), init(5, init(10, 0, 0), init(11, 0, 0))), init(3, init(6, init(12, 0, 0), init(13, 0, 0)), init(7, init(14, 0, 0), init(15, 0, 0))));
    print(p, 0);
    printf("\n\n\n");
    
    del_left_list(p);
    printf("\n\n\n");
    print(p, 0);

}
