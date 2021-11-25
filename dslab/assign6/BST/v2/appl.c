#include "impl.h"
#include<stdio.h>
void sameBST(struct BST*t1,struct BST*t2,int arr1[],int arr2[],int *n1,int *n2)
{
	inorderModify(t1,arr1,n1);
	inorderModify(t2,arr2,n2);
	if(*n1!=*n2)
		printf("Not same BST\n");
	else
	{
		for(int i=0;i<*n1;i++)
		{
			if(arr1[i]!=arr2[i])
			{
				printf("Not same BST\n");
				return;
			}
		}
		printf("Same BST\n");
	}
}

int complete(struct BST* t1,int index,int n)
{
    if(t1==NULL)
        return 1;
    if(index>=n)
        return 0;
    return (complete(t1->left,2*index+1,n)&&complete(t1->right,2*index+2,n));
}

int nodesrange(struct BST*t,int arr[],int n,int l,int r)
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>=l && arr[i]<=r)
			count++;
	}
	return count;
}

int main()
{
	struct BST *t=NULL,*p=NULL;
	t=insert(t,10);
	insert(t,5);
	insert(t,50);
	insert(t,1);
	insert(t,40);
	insert(t,100);
	p=insert(p,10);
	insert(p,5);
	insert(p,50);
	insert(p,1);
	insert(p,40);
	insert(p,100);
	int arr1[100],arr2[100];
	int n1=0,n2=0;
	sameBST(t,p,arr1,arr2,&n1,&n2);
	if(complete(t,0,n1))
		printf("Complete tree\n");
	else
		printf("Not a complete tree\n");
	int l,r;
	printf("Limits of range:");
	scanf("%d %d",&l,&r);
	printf("No.of nodes in the given range:%d\n",nodesrange(t,arr1,n1,l,r));
}
