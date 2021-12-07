#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

#define SIZE 500

struct node 
{
    int d;
    struct node* n;
};

#define NODE(TYPE) \
struct Node_##TYPE \
{ \
TYPE d; \
struct Node_##TYPE *n; \
};


void printNode(struct node* f)
{
    struct node* p = f;
    while (p != 0)
    {
        printf("%d \n", p->d);
        p = p->n;
    }
}

void addForNInSqrt(struct node* f, int data)
{
    struct node* p_new = (struct node*)malloc(sizeof(struct node));
    struct node* p = f;
    while (p->n != 0)
    {
        
        p = p->n;
    }
    
    p_new->d = data;
    p->n = p_new;
    p_new->n = 0;
    
}

struct node* inputNode()
{   
    int input;
    scanf("%d", &input);
    struct node first;
    first.d = input;
    first.n = 0;

    struct node* p_first = &first;
    struct node** pp_first = &p_first;

    
    while (scanf("%d", &input) != EOF)
    {
        addForNInSqrt(p_first, input);

    }

    return p_first;
}


int main()
{
    struct node first;
    first.d = 0;
    first.n = 0;

    struct node* p_first = &first;
    struct node** pp_first = &p_first;

   


    p_first = inputNode();
    printNode(p_first);

}
