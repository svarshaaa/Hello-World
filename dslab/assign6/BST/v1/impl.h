#include "adt.h"
#include<stdlib.h>
#include<stdio.h>
struct BST * insert(struct BST *t,int x)
{
	if(t==NULL)
	{
		t=(struct BST *)malloc(sizeof(struct BST));
		t->data=x;
		t->left=NULL;
		t->right=NULL;
	}
	else
	{
		if(x<t->data)
			t->left=insert(t->left,x);
		else
			t->right=insert(t->right,x);
	}
	return t;
}
struct BST* del(struct BST *t,int x)
{
	struct BST* temp;
	if(x<t->data) 
		t->left=del(t->left,x);
	else if(x>t->data)
		t->right=del(t->right,x);
	else if(t->left && t->right)
	{
		temp=findmin(t->right);
		t->data=temp->data;
		t->right=del(t->right,t->data);
	}
	else
	{
		temp=t;
		if(t->right==NULL)
			t=t->left;
		else if(t->left==NULL)
			t=t->right;
		free(temp);
	} 
	return t;
}

void inorder(struct BST *t)
{
	if(t->left!=NULL)
		inorder(t->left);
	printf("%d ",t->data);
	if(t->right!=NULL)
		inorder(t->right);
}

int height(struct BST*t)
{
    if (t== NULL)
        return 0;
    else {
        int lheight = height(t->left);
        int rheight = height(t->right);
 
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void printorder(struct BST*t,int lvl)
{
    if(t==NULL)
        return;
    if(lvl==1)
        printf("%d ",t->data);
    printorder(t->left,lvl-1);
    printorder(t->right,lvl-1);
}
void levelorder(struct BST*t)
{
    int h=height(t);
    for (int i=1;i<=h;i++)
    {
        printf("\nLevel %d:",i);
        printorder(t,i);
    }
}

struct BST* find(struct BST* t,int x)
{
	if(t==NULL)
	{
	return NULL;
	}
	if(t->data<x)
		return find(t->right,x);
	else if(t->data>x)
		return find(t->left,x);
	else
		return t;
}
struct BST* findmin(struct BST*t)
{
	if(t->left!=NULL)
		return findmin(t->left);
	return t;
}

