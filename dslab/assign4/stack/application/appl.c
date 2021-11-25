#include<stdio.h>
#include<stdlib.h>
#include "impl.h"
int twoStacks(struct stackADT *a,struct stackADT *b,int maxsum)
{
    int sum=0,count=0,ch;
    while(1)
    {
        if(isEmpty(a) && isEmpty(b))
            break;
	printf("From stack 1 or stack 2 or break(1 or 2 or 3)?:");
	scanf(" %d",&ch);
        if(ch==1)
        {
	    if(isEmpty(a))
		printf("Stack 1 is empty\n");
	    else
	    {
		    if(a->data[a->top]+sum>maxsum)
			break;
		    sum+=a->data[a->top];
		    pop(a);
            }
        }
        else if (ch==2)
        {
	    if(isEmpty(b))
		printf("Stack 2 is empty\n");
	    else
            {
		    if(b->data[b->top]+sum>maxsum)
			break;
		    sum+=b->data[b->top];
		    pop(b);
	    }
        }
	else
		break;
        count++;
    }
    return count;
}
void main()
{
    int ch,val;
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
