#include<stdio.h>
#include "adt.h"
void initStack(struct stackADT*s,int si)
{
    s->top=-1;
    s->size=si;
}

void push(struct stackADT *s,int c)
{
    if(isFull(s))
        printf("Stack is full\n");
    else
    {
        s->top++;
        s->data[s->top]=c;
    }
}

void pop(struct stackADT *s)
{
    if(isEmpty(s))
        printf("Stack is empty\n");
    else
        s->top--;
}

int top(struct stackADT *s)
{
	if(isEmpty(s))
		return -1;
	else
    		return s->data[s->top];
}

int isFull(struct stackADT *s)
{
    if(s->top==s->size-1)
        return 1;
    else
        return 0;
}

int isEmpty(struct stackADT *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}

void display(struct stackADT *s)
{
    int x=s->top;
    while(x!=-1)
    {
        printf("%d\n",s->data[x]);
        x--;
    }
}
