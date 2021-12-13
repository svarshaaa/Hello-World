#include "adt.h"
#include<stdio.h>
void init(struct numberADT *N,int n)
{
    N->n=n;
}
void insertElements(struct numberADT *N,int x[10])
{
    int j=0;
    for(int i=0;i<N->n;i++)
        N->arr[j++]=x[i];
}
int lsearchElement(struct numberADT *N,int key)
{
    int f=0,i;
    for(i=0;i<N->n;i++)
    {
        if(N->arr[i]==key)
        {
            f=1;
            break;
        }
    }
    if(f==1)
        return i;
    return -1;
}
int bsearchElement(struct numberADT *N,int key)
{
    int l,r,m;
    l=0;
    r=N->n-1;
    struct ie a[100];
    int j=0;
    for(int i=0;i<N->n;i++)
    {
        a[j].ind=i;
        a[j++].elt=N->arr[i];
    }
    for(int i=0;i<N->n-1;i++)
    {
        for(j=i+1;j<N->n;j++)
        {
            if(a[j].elt<a[i].elt)
            {
                struct ie t=a[j];
                a[j]=a[i];
                a[i]=t;
            }
        }
    }
    while(l<r)
    {
        m=(l+r)/2;
        if(a[m].elt>=key) 
            r=m;
        else
            l=m+1;
    }
    if(a[l].elt==key)
        return a[l].ind;
    return -1;
}
void display(struct numberADT*N)
{
    for(int i=0;i<N->n;i++)
        printf("%d ",N->arr[i]);
}
