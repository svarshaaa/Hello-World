#include<stdio.h>
#include<stdlib.h>
#include "adt.h"
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int height(struct avl *t)
{
    if(t==NULL)
        return -1;
    return t->height;
}

struct avl* insert(struct avl*t, int x)
{
	if(t==NULL)
	{
		t=(struct avl *)malloc(sizeof(struct avl));
		t->data=x;
		t->left=NULL;
		t->right=NULL;
	}
	else if(x<t->data)
	{
		t->left=insert(t->left,x);
        int hdiff=height(t->left)-height(t->right);
        if(hdiff>=2)
        {
            if(x<t->left->data)
                t=singlerotatewithleft(t);
            else
                t=doublerotatewithleft(t);
        }
	}
    else if(x>t->data)
    {
        t->right=insert(t->right,x);
        int hdiff=(height(t->right)-height(t->left));
        if(hdiff>=2)
        {
            if(x>t->right->data)
                t=singlerotatewithright(t);
            else
                t=doublerotatewithright(t);
        }
    }
    t->height=max(height(t->left),height(t->right))+1;
	return t;
}

struct avl * singlerotatewithleft(struct avl*k2)
{
    struct avl *k1;
    k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    return k1;
}

struct avl* singlerotatewithright(struct avl*k2)
{
    struct avl *k1=k2->right;
    k2->right=k1->left;
    k1->left=k2;
    return k1;
}
struct avl* doublerotatewithleft(struct avl*k3)
{
    k3->left=singlerotatewithright(k3->left);
    return singlerotatewithleft(k3);
}
struct avl* doublerotatewithright(struct avl*k3)
{
    k3->right=singlerotatewithleft(k3->right);
    return singlerotatewithright(k3);
}

void inorder(struct avl*t)
{
    if(t->left!=NULL)
        inorder(t->left);
    printf("%d ",t->data);
    if(t->right!=NULL)
        inorder(t->right);
}