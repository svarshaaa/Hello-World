#include "adt.h"
#include<stdio.h>
void enqueue(struct Queue *q,struct data d)
{
    if(isFull(q))
        printf("Queue is full");
    else
    {
        q->iter++;
        q->r=(++q->r)%q->size;
        q->arr[q->r]=d;
    }
}

void disp(struct Queue *q)
{
    for(int i=q->f+1;i!=q->r;i=(++i)%q->size)
    {
        printf("%d %d\n",q->arr[i].jobno,q->arr[i].bst);
    }
    printf("%d %d\n",q->arr[q->r].jobno,q->arr[q->r].bst);
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