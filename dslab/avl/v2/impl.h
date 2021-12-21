#include<stdio.h>
#include<stdlib.h>
#include "adt.h"
#include<string.h>
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int height(struct dictionaryADT *D)
{
    if(D==NULL)
        return -1;
    return D->height;
}

struct dictionaryADT* insert(struct dictionaryADT*D, struct wordMeaning x)
{
	if(D==NULL)
	{
		D=(struct dictionaryADT *)malloc(sizeof(struct dictionaryADT));
		D->data=x;
		D->left=NULL;
		D->right=NULL;
	}
	else if(strcmp(x.word,D->data.word)<0)
	{
		D->left=insert(D->left,x);
        int hdiff=height(D->left)-height(D->right);
        if(hdiff>=2)
        {
            if(strcmp(x.word,D->left->data.word)<0)
                D=singlerotatewithleft(D);
            else
                D=doublerotatewithleft(D);
        }
	}
    else if(strcmp(x.word,D->data.word)>0)
    {
        D->right=insert(D->right,x);
        int hdiff=(height(D->right)-height(D->left));
        if(hdiff>=2)
        {
            if(strcmp(x.word,D->right->data.word)>0)
                D=singlerotatewithright(D);
            else
                D=doublerotatewithright(D);
        }
    }
    D->height=max(height(D->left),height(D->right))+1;
	return D;
}

struct dictionaryADT * singlerotatewithleft(struct dictionaryADT*k2)
{
    struct dictionaryADT *k1;
    k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    return k1;
}

struct dictionaryADT* singlerotatewithright(struct dictionaryADT*k2)
{
    struct dictionaryADT *k1=k2->right;
    k2->right=k1->left;
    k1->left=k2;
    return k1;
}
struct dictionaryADT* doublerotatewithleft(struct dictionaryADT*k3)
{
    k3->left=singlerotatewithright(k3->left);
    return singlerotatewithleft(k3);
}
struct dictionaryADT* doublerotatewithright(struct dictionaryADT*k3)
{
    k3->right=singlerotatewithleft(k3->right);
    return singlerotatewithright(k3);
}

void inorder(struct dictionaryADT*D)
{
    if(D->left!=NULL)
        inorder(D->left);
    printf("%s,%s\n",D->data.word,D->data.mean);
    if(D->right!=NULL)
        inorder(D->right);
}

void search(struct dictionaryADT *D,char *word)
{
    if(strcmp(D->data.word,word)>0)
        search(D->left,word);
    else if(strcmp(D->data.word,word)<0)
        search(D->right,word);
    else
    {
        printf("Meaning of %s:%s\n",word,D->data.mean);
        return;
    }
    return;
}