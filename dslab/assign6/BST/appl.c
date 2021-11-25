#include "impl.h"
#include<stdio.h>
/*int traversal(struct BST *t,struct BST *p,struct BST *fix)
{
	if(t->left!=NULL)
	if(!traversal(t->left,p,fix))
		return 0;
	if(find(p,t->data)==NULL)
		return 0;
	if(t->right!=NULL)
	if(!traversal(t->right,p,fix))
		return 0;
	if(t==fix)
		return 1;
}
int sameBST(struct BST *t1,struct BST*t2)
{
	if(traversal(t1,t2,t1)==0)
		return 0;
	if(traversal(t2,t1,t2)==0)
		return 0;
	return 1;
}
int count(struct BST*t)
{
	if(t==NULL)
		return 0;
	return(1+count(t->left)+count(t->right));
}
int complete(struct BST* t1,int index,int n)
{
	if(t1==NULL)
		return 1;
	if(index>=n)
		return 0;
	return (complete(t1->left,2*index+1,n)&&complete(t1->right,2*index+2,n));
}

int nodesrange(struct BST*t,int l,int r)
{
	if(t==NULL)
		return 0;
	for(int i=l;i<=r;i++)
	{
		if(t->data==i)
			return (1+nodesrange(t->left,l,r)+nodesrange(t->right,l,r));
	}
	return nodesrange(t->left,l,r)+nodesrange(t->right,l,r);
}*/

int main()
{
	struct BST *t,*t1=NULL,*t2=NULL;
	t=NULL;
	t=insert(t,29);
	insert(t,23);
	insert(t,4);
	insert(t,13);
	insert(t,39);
	insert(t,31);
	insert(t,45);
	insert(t,56);
	insert(t,49);
	inorder(t);
	//levelorder(t);
	struct BST *d=findmin(t);
	printf("\n%d",d->data);
	if(d=find(t,13))
	printf("\nAddress of 13:%p\n",d);
	else
	printf("Not found\n");
	if(d=find(t,3))
		printf("Address of 3:%p",d);
	else
		printf("Not found\n");

	int n=0;
	inorderModify(t,arr,&n);
}
