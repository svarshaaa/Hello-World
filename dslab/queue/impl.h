#include "adt.h"
#include<stdio.h>
void enqueue(struct Queue *q, int x)
{
    if(isFull(q))
        printf("Queue is full");
    else
    {
        q->iter++;
        q->r=(++q->r)%q->size;
        q->arr[q->r]=x;
    }
}

int dequeue(struct Queue *q)
{
    if(isEmpty(q))
        printf("Queue is empty");
    else
    {
        q->iter--;
        q->f=(++q->f)%q->size;
        return q->arr[q->f+1];
    }
}

void disp(struct Queue *q)
{
    for(int i=q->f+1;i!=q->r;i=(++i)%q->size)
    {
        printf("%d ",q->arr[i]);
    }
    printf("%d\n",q->arr[q->r]);
}

int isFull(struct Queue*q)
{
    if(q->iter==q->size)
        return 1;
    else
        return 0;
}

int isEmpty(struct Queue*q)
{
    if(q->iter==0)
        return 1;
    else
        return 0;
}