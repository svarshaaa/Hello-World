#include "adt.h"
#include<stdio.h>
void init(struct numberADT *N,int n)
{
    N->n=n;
}
void insertElements (struct numberADT *N, int x[10])
{
    int j=0;
    for(int i=0;i<N->n;i++)
    {
        N->arr[j++]=x[i];
    }
}
void selSort(struct numberADT *N)
{
    for(int i=0;i<N->n-1;i++)
    {
        for(int j=i+1;j<N->n;j++)
        {
            if(N->arr[j]<N->arr[i])
            {
                int t=N->arr[j];
                N->arr[j]=N->arr[i];
                N->arr[i]=t;
            }
        }
    }
}
void shellSort(struct numberADT *N)
{
    for(int g=N->n/2;g>0;g/=2)
    {
        for(int i=g;i<N->n;i++)
        {
            int temp=N->arr[i],j;
            for(j=i;j>=g && N->arr[j-g]>temp;j-=g)
            {
                N->arr[j]=N->arr[j-g];    
            }
            N->arr[j]=temp;
        }
    }
}
void display(struct numberADT *N)
{
    for(int i=0;i<N->n;i++)
        printf("%d ",N->arr[i]);
    printf("\n");
}