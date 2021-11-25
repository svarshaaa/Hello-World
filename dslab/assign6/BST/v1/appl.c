#include "impl.h"
#include<stdio.h>
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
	levelorder(t);
	printf("\nAfter deletion:\n");
	del(t,39);
	inorder(t);
	struct BST *d=findmin(t);
	printf("\nMinimum element:%d\n",d->data);
	if(d=find(t,13))
		printf("\nAddress of 13:%p\n",d);
	else
		printf("Not found\n");
	if(d=find(t,3))
		printf("Address of 3:%p",d);
	else
		printf("Not found\n");
}
