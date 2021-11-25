#include "impl.h"
#include<stdio.h>
int main()
{
    struct Queue q1,q2;
    int ch,job,bst;
    q1.f=-1;
    q1.r=-1;
    q1.iter=0;
    q2.f=-1;
    q2.r=-1;
    q2.iter=0;
    printf("Enter size:");
    scanf("%d",&q1.size);
    q2.size=q1.size;
    do
    {
        printf("\n1)Insert 2)Display 3)Exit:");
        scanf(" %d",&ch);
        if(ch==1)
        {
            printf("\nEnter job no. and cpu burst time:");
            scanf(" %d %d",&job,&bst);
            struct data d;
            d.jobno=job;
            d.bst=bst;
            if(isEmpty(&q1))
                enqueue(&q1,d);
            else if(isEmpty(&q2))
                enqueue(&q2,d);
            else
            {
                int avg1=0,avg2=0,sum=0;
                for(int i=q1.f+1;i!=q1.r;i=(++i)%q1.size)
                {
                    sum+=q1.arr[i].bst;
                }
                sum+=q1.arr[q1.r].bst;
                avg1=sum/q1.iter;
                sum=0;
                for(int i=q2.f+1;i!=q2.r;i=(++i)%q2.size)
                {
                    sum+=q2.arr[i].bst;
                }
                sum+=q2.arr[q2.r].bst;
                avg2=sum/q2.iter;
                if(avg1<avg2)
                    enqueue(&q1,d);
                else
                    enqueue(&q2,d);
            }
        
        }
        else if (ch==2)
        {
            printf("\nQueue 1: ");
            disp(&q1);
            printf("\nQueue 2: ");
            disp(&q2);
        } 
    } while (ch!=3);
    
}