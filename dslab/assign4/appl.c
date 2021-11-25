#include<stdio.h>
#include<stdlib.h>
#include "impl.h"
int twoStacks(struct stackADT *a,struct stackADT *b,int maxsum)
{
    int sum=0,count=0;
    while(sum+a->data[a->top]<=maxsum || sum+b->data[b->top]<=maxsum)
    {
        if(isEmpty(a) && isEmpty(b))
            break;
        if(isEmpty(a))
        {
           sum+=b->data[b->top];
           pop(b); 
        }
        else if(isEmpty(b))
        {
            sum+=a->data[a->top];
            pop(a);
        }
        else if(a->data[a->top]<b->data[b->top])
        {
            sum+=a->data[a->top];
            pop(a);
        }
        else
        {
            sum+=b->data[b->top];
            pop(b);
        }
        count++;
    }
    return count;
}
void main()
{
    int ch,val;
    struct stackADT s;
    printf("Enter max size of stack:");
    scanf(" %d",&val);
    initStack(&s,val);
    do
    {
        printf("1)Push 2)Pop 3)Display top element 4)Display all the elements 5)Exit\n");
        scanf(" %d",&ch);
        if(ch==1)
        {
            printf("Enter a value to push:");
            scanf(" %d",&val);
            push(&s,val);
        } 
        else if(ch==2)
        {
            pop(&s);
        }
        else if(ch==3)
        {
            printf("Top element:%d\n",top(&s));
        }
        else if(ch==4)
        {
            display(&s);
        }
    }while(ch!=5);
    struct stackADT a,b;
    printf("Enter max size of stack1:");
    scanf(" %d",&val);
    initStack(&a,val);
    int valu;
    for(int i=0;i<val;i++)
    {
        printf("Enter value %d:",i+1);
        scanf(" %d",&valu);
        push(&a,valu);
    }
    printf("Enter max size of stack2:");
    scanf(" %d",&val);
    initStack(&b,val);
    
    for(int i=0;i<val;i++)
    {
        printf("Enter value %d:",i+1);
        scanf(" %d",&valu);
        push(&b,valu);
    }
    printf("Enter maxsum:");
    scanf(" %d",&val);
    printf("Max count:%d",twoStacks(&a,&b,val));

}