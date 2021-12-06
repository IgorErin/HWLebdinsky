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

#define LEN(TYPE) \
int len(struct Node_##TYPE* f) \
{ \
    struct Node_##TYPE* p = f; \
    int i = 0; \
    while (p != 0) \
    { \
        i++; \
        p = p->n; \
    } \
    return i; \
}

struct node* pointerToSecond(struct node* f)
{
    return f->n;
}

struct node* pointerToLastEL(struct node* f)
{
    struct node* p = f, *p1;
    
    while (p != 0)
    {
        p1 = p;
        p = p->n;
    }
    return p1;
}

struct node* pointerToNEl(struct node* f, int n)
{
    struct node* p = f;
    int i = 0;
    while (p != 0)
    {
        i++;
        p = p->n;
        if (i == n)
        {
            return p;
        }
    }
}

#define POINTERTONEL(TYPE) \
struct node* pointerToNElForAll(struct Node_##TYPE* f, int n) \
{ \
    struct Node_##TYPE* p = f; \
    int i = 0; \
    while (p != 0) \
    { \
        i++; \
        p = p->n; \
        if (i == n) \
        { \
            return p; \
        } \
    } \
}

void nodePrint(struct node* f)
{
    struct node* p = f;
    int i = 0;
    printf("%d", p->d);
    while (p != 0)
    {
        p = p->n;
        printf("%d", p->d);
    }
}

int count(struct node* f,_Bool (*funBool)(struct node*))
{
    struct node* p = f;
    int i = 0;
    while (p != 0)
    {
        if ((*funBool)(p))
        {
            i++;
        }
        p = p->n;
    }

    return i;
}

int firstWhitData(struct node* f, int dat)
{
    struct node* p = f;
    while (p != 0)
    {
        if (p->d == dat)
        {
            return p;
        }
        p = p->n;
    }
    return 0;
}

int LastWhitData(struct node* f, int par)
{
    struct node* p = f, *output = 0;
    while (p != 0)
    {
        if (p->d == par)
        {
            output = p;
        }
        p = p->n;
    }
    return output;
}

int main()
{}
