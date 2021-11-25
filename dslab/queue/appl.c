#include "impl.h"
#include<stdio.h>
int main()
{
    struct Queue q;
    int ch,val;
    q.f=-1;
    q.r=-1;
    q.iter=0;
    printf("Enter size:");
    scanf("%d",&q.size);
    do
    {
        printf("\n1)Enqueue 2)Dequeue 3)Display 4)Exit:");
        scanf(" %d",&ch);
        if(ch==1)
        {
            printf("\nEnter element:");
            scanf(" %d",&val);
            enqueue(&q,val);
        }
        else if (ch==2)
        {
            dequeue(&q);
        }
        else if(ch==3)
        {
            disp(&q);
        } 
    } while (ch!=4);
    
}