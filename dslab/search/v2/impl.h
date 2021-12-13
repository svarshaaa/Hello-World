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
    else if(a[r].elt==key)
        return a[r].ind;
    return -1;
}
void display(struct numberADT*N)
{
    for(int i=0;i<N->n;i++)
        printf("%d ",N->arr[i]);
}

void bsearchElementModify(struct numberADT *N,int key,int ch)
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
    if(a[l+1].elt==key && ch==1)
        printf("Position of second occurence:%d\n",a[l+1].ind+1);
    else if(a[l+1].elt!=key && ch==1)
        printf("No second occurence\n");
    if(ch==2)
    {
        int l2=0,r2=N->n-1;
        while(l2<r2)
        {
            m=(l2+r2)/2;
            if(a[m].elt>key) 
                r2=m-1;
            else
                l2=m;
        }
        printf("Frequency:%d",l2-l+1);
    }
}

void lsearchElementModify(struct numberADT *N1,struct numberADT *N2,int ch)
{
    if(ch==3)
    {
        int f=0,i;
        for(int j=0;j<N1->n;j++)
        {
            f=0;
            for(i=0;i<N2->n;i++)
            {
                if(N2->arr[i]==N1->arr[j])
                {
                    f=1;
                    break;
                }
            }
            if(f==0)
            {
                printf("Two lists are not same\n");
                return;
            }
        }
        printf("Lists are same\n");
    }
    else
    {
        printf("Enter difference:");
        int diff,i;
        scanf(" %d",&diff);
        for(int j=0;j<N1->n;j++)
        {
            int f=0;
            for(i=0;i<N2->n;i++)
            {
                if(N2->arr[i]-N1->arr[j]==diff || N1->arr[j]-N2->arr[i]==diff)
                {
                    f=1;
                    break;
                }
            }
            if(f==1)
            {
                printf("%d %d\n",N1->arr[j],N2->arr[i]);
                return;
            }
        }
        printf("There is no such pair");
    }
}