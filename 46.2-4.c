#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

struct anode
{
    int dat;
    struct anode* down, * next;

};


struct anode* g(int dat, struct anode* p_down, struct anode* p_next)
{
    struct anode* p = (struct anode*)malloc(sizeof(struct anode));
    p->dat = dat;
    p->down = p_down;
    p->next = p_next;
    return p;
}

void print(struct anode* p, int offset)
{
    if (p == 0)
    {
        return;

    }

    for (int i = 0; i < offset; i++)
    {
        printf(" ");
    }

    printf("%d\n", p->dat);
    print(p->down, offset + 3);
    print(p->next, offset);
}

void fun(struct anode* p)
{
    if (p == 0)
    {
        return 0;
    }

    p = p->down;
    while (p != 0)
    {
        struct anode* p_next = p->next;
        if (p->next == 0)
        {
            p->next = p->down;
            p->down = 0;
            break;
        }
        struct anode* p_f;
        if (p->down != 0)
        {
            p_f = p->down;
            while (p_f->next != 0)
            {
                p_f = p_f->next;
            }
            p_f->next = p_next;
            p->next = p->down;
            p->down = 0;
        }
        p = p_next;
    }
}

int main()
{

    struct anode* p_tree = g(1, g(2, g(5, 0, g(6, 0, g(7, g(14, 0,g(15, 0,0)), 0))), g(3, g(8, g(24, 0, 0), 0), g(4, g(9, 0, g(10, 0, 0)), 0))), 0);
    print(p_tree, 0);
    int x[4] = { 1, 1, 3, 2 };
    fun(p_tree);
    printf("\n\n\n");
    print(p_tree, 0);

}
