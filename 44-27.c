#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

struct node
{
    int d;
    struct node* nl, *nr;
};

void printNode(struct node* f)
{
    struct node* p = f;

    while (p != 0)
    {
        printf("%d \n", p->d);
        p = p->nr;
    }
    printf("-------\n");
}

struct node* add(int data, struct node* ex_p)
{
    struct node* p = (struct node*)malloc(sizeof(struct node));

    p->nr = 0;
    p->nl = ex_p;
    ex_p->nr = p;
    p->d = data;

    return p;
}

struct node* create()
{
    struct node* p_first = (struct node*)malloc(sizeof(struct node));
    struct node*  p_new = p_first;
    int data;

    printf("0 if last\n");
    scanf("%d", &data);

    p_first->d = data;
    p_first->nl = 0;

    while (data != 0)
    {
        scanf("%d", &data);
        p_new = add(data, p_new);
        
    }
    return p_first;
}

struct node* copyDList(struct node* f)
{
    struct node* p = f;
    struct node* p_save = f;
    struct node* p_copy = (struct node*)malloc(sizeof(struct node));
    p_copy->nl = 0;


    while (p->nr != 0)
    {
        p_copy->d = p->d;
        
        if (p->nr == 0)
        {
            break;
        }

        struct node* p_new = (struct node*)malloc(sizeof(struct node));
        p_copy->nr = p_new;
        p_new->nl = p_copy;
        p_copy = p_new;
        p = p->nr;
    }
    p_copy->nr = 0;
    return p_save;
}
//--------------------------------------------
void revers(struct node** pp)
{
    struct node* p = *pp;
    struct node* p_for_change;
    

    while (p != 0)
    {
        p_for_change = p->nl;
        p->nl = p->nr;
        p->nr = p_for_change;
        if (p->nl == 0)
        {
            break;
        }
        p = p->nl;
        
    }
    *pp = p;

}

//----------------------------------------------
struct node* ret_pointer(struct node* p_first, int n)
{
    struct node* p = p_first;
    int i = 0;
    while (p->nr != 0)
    {
        if (i == 0)
        {
            return p_first;
        }
        p_first = p_first->nr;
        i++;
    }
    return 0;
}

struct node* delWhitPointerForRight(struct node *p_first, struct node* p_to_del)
{   

    if (p_to_del == p_first)
    {
        struct node* p_for_del = p_to_del->nr;
        p_to_del->nr->nl = p_to_del->nl;
        free(p_to_del);
        return p_for_del;
    }
    else
    {
        p_to_del->nr->nl = p_to_del->nl;
        p_to_del->nl->nr = p_to_del->nr;
        free(p_to_del);
        return p_first;
    }
}



int main()
{
    
    
    printf("---------\n");
    struct node* p2, *p1;
    p2 = create();
    p1 = ret_pointer(p2, 2);
    //printNode(p2);
    //p2 = delWhitPointerForRight(p2, p1);
    //printNode(p2);
    revers(&p2);
    printNode(p2);
}
