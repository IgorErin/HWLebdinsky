#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>



struct stack
{
    int x[1000];
    int count;
};

void push(int input, struct stack* p_to_stack)
{
    if (p_to_stack->count >= 1000)
    {
        printf("stack overflow");
    }
    else
    {
        p_to_stack->x[p_to_stack->count] = input;
        p_to_stack->count += 1;
    }
}

void empty(struct stack* p_to_stack)
{
    if (p_to_stack->count == 0)
    {
        printf("empty");
    }
    else
    {
        printf("not empty");
    }
}

int pop(struct stack* p_to_stack)
{
    if (p_to_stack->count > 0)
    {
        p_to_stack->count -= 1;
        return p_to_stack->x[p_to_stack->count];
    }
    else
    {
        printf("\nstack is empty\n");
        return 0;
    }
}

int main()
{
    
    struct stack x;
    (&x)->count = 0;

    printf("----");
    
    printf("------");
    printf("%d", pop(&x));
    //printf("%d", x.count);


}
