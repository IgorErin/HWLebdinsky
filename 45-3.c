#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>

struct queue
{
    int x[1000][2];
    int second;
};

void swap(int **x, int **y)
{
    int c = **x;
    **x = **y;
    **y = c;
}

void make_heapfy(int** x, int n, int index)
{
    
    int finit_index = index;

    if (2 * index + 1 < n)
    {
        if (x[finit_index][1] < x[2 * index + 1][1])
        {
            finit_index = 2 * index + 1;
        }
    }
    if (2 * index + 2 < n)
    {
        if (x[finit_index][1] < x[2 * index + 2][1])
        {
            finit_index = 2 * index + 2;
        }
    }

    if (finit_index != index)
    {
        
        //printf("swap %d <-> %d \n", x[finit_index][1], x[index][1]);
        printf("swap %d <-> %d \n", x[finit_index][0], x[index][0]);
        
        swap(&x[finit_index], &x[index]);
        make_heapfy(x, n, finit_index);
    }
    
}

void init(struct queue* p)
{
    p->second = 0;
}


int out(struct queue* p)
{
    int out = p->x[p->second - 1][0];
    p->second -= 1;
    return out;
}

void printNode(struct queue* p)
{
    for (int i = 0; i < p->second; i++)
    {
        printf("%d\n", p->x[i][1]);
    }
}
void push(struct queue* p, int n, int prior)
{
    
    p->x[p->second][0] = n;
    p->x[p->second][1] = prior;
    p->second += 1;

    printNode(p);

    for (int i = p->second - 1; i >= 0; i--)
    {
        make_heapfy((p->x), p->second, i);
    }
    
}
int main()
{
    struct queue p;
    init(&p);
    for (int i = 0; i < 10; i++)
    {
        push(&p, i, i % 5);
        printNode(&p);
        printf("----\n\n");
    }
    printNode(&p);
}
