#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>



struct stack
{
    int d;
    struct stack* n;
};

void push(struct stack** p, int i)
{
    
    struct stack* p_new = (struct stack*)malloc(sizeof(struct stack));
    p_new->n = *p;
    p_new->d = i;
    *p = p_new;
    

}

int pop(struct stack** p_first)
{
    if ((*p_first)->n == 0)
    {
        printf("stack is empty\n");
        return 0;
    }
    struct stack* p = *p_first;
    int output = p->d;
    *p_first = (*p_first)->n;
    free(p);
    return output;

}

void empty(struct stack* p_first)
{
    if (p_first->n == 0)
    {
        printf("stack is empty");
    }
    else
    {
        printf("not empty");
    }
}


int main()
{
    
    struct stack x;
    (&x)->n = 0;

   
    struct stack* p = &x;
    struct stack** pp = &p;
    for (int i = 0; i < 10; i++)
    {
        push(pp, i);
    }
    
    for (int i = 0; i < 11; i++)
    {
        printf("%d\n", pop(&p));
    }
    


}
