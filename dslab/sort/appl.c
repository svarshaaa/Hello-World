#include "impl.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
    struct numberADT *N=(struct numberADT*)malloc(sizeof(struct numberADT));
    int ch;
    int n=10;
    int arr[100];
    do{
        printf("1)Insert elements for new array 2)Selection sort 3)Shell sort 4)Display 5)exit:");
        scanf(" %d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter array size:");
            scanf(" %d",&n);
            init(N,n);
            printf("Enter array elements:");
            for(int i=0;i<n;i++)
                scanf(" %d",&arr[i]);
            insertElements(N,arr);
            break;
        case 2:
            selSort(N);
            break;
        case 3:
            shellSort(N);
            break;
        case 4:
            display(N);
            break;
        default:
            break;
        }
    }while(ch!=5);
    
}