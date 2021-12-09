#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<math.h>
#include <time.h>



struct queue
{
    int first, second;
    int x[1000];
};

void insert(struct queue* p, int i)
{
    if (p->second >= 1000)
    {
        printf("overflow");
    }
    else
    {
        p->x[p->second] = i;
        p->second += 1;
    }
}
int out(struct queue* p)
{
    if (p->first < p->second)
    {
        int i = p->x[p->first];
        p->first += 1;
        return i;
    }
    else
    {
        printf("queue is empty\n");
        return 0;
    }
}
void isempty(struct queue* p)
{
    if (p->second <= p->first)
    {
        printf("empty\n");
    }
    else
    {
        printf("not empty");
    }
}

int main()
{
    struct queue x;
    x.first = 0;
    x.second = 0;
    for (int i = 0; i < 1000; i++)
    {
        
        isempty(&x);
    }
    //for (int i = 0; i < 1000; i++)
    //{
       // printf("%d\n", out(&x));
    //}

}
