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

struct anode* fun(struct anode* p, int dat1, int dat2)
{
    if (p == 0)
    {
        return 0;
    }
    p = p->down;
    struct anode* p_check;

    while (p != 0)
    {
        p_check = p->down;
        if (p->dat == dat1)
        {
            while (p_check != 0)
            {
                if (p_check->dat == dat2)
                {
                    return p;
                }
                p_check = p_check->next;
            }
        }
        p = p->next;
    }
    return 0;
}

int main()
{

    struct anode* p_tree = g(1, g(2, g(5, 0, g(6, 0, g(7, g(14, 0,g(15, 0,0)), 0))), g(3, g(8, 0, 0), g(4, g(9, 0, g(10, 0, 0)), 0))), 0);
    print(p_tree, 0);
    printf("%d", fun(p_tree, 2,4)->dat);

}
