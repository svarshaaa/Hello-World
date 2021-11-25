#include<stdio.h>
#include<stdlib.h>
#include "impl.h"
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
		int x=top(&s);
		if(x!=-1)
            printf("Top element:%d\n",x);
		else
			printf("Stack empty\n");
        }
        else if(ch==4)
        {
            display(&s);
        }
    }while(ch!=5);

}
