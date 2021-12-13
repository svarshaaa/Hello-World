#include "adt.h"
#include<stdio.h>
int isEmpty(struct queue *q)
{
	if(q->f==q->r)
		return 1;
	return 0;
}
void enqueue(struct queue *q,int x)
{
	q->r++;
	q->arr[q->r]=x;
}
int dequeue(struct queue *q)
{
	return q->arr[++q->f];
}
void create(struct cityADT *c)
{
	int n,e;
	printf("Enter no.of vertices and edges:");
	scanf("%d %d",&n,&e);
	int x;
	printf("Enter edges:");
	char ch[10];
	c->rsize=n;
	c->csize=n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			c->data[i][j]=0;
	}
	for(int i=0;i<e;i++)
	{
		scanf(" %s",ch);
		char a=ch[0];
		char b=ch[1];
		c->data[a-65][b-65]=1;
	}
}	
void disp(struct cityADT *c)
{
	printf("Displaying:\n");
	for(int i=0;i<c->rsize;i++)
	{
		for(int j=0;j<c->csize;j++)
		{
			printf("%d ",c->data[i][j]);
		}
		printf("\n");
	}
}

void BFS(struct cityADT *c,char st)
{
	printf("BFS:\n");
	int v[100];
	for(int i=0;i<c->rsize;i++)
		v[i]=1;
	for(int i=st-65;i<c->rsize;i++)
	{
		if(v[i]==1)
		{
			enqueue(c->q,i);
			v[i]=-1;
			printf("%c\n",i+65);
			while(!isEmpty(c->q))
			{
				int z=dequeue(c->q);
				for(int j=0;j<c->csize;j++)
				{
					if(c->data[z][j]==1 && v[j]!=-1)
					{
						v[j]=-1;
						printf("%c\n",(char)(65+j));
						enqueue(c->q,j);
					}
				}
			}
		}
	}
	for(int i=0;i<st-65;i++)
	{
		if(v[i]==1)
		{
			enqueue(c->q,i);
			v[i]=-1;
			printf("%c\n",i+65);
			while(!isEmpty(c->q))
			{
				int z=dequeue(c->q);
				for(int j=0;j<c->csize;j++)
				{
					if(c->data[z][j]==1 && v[j]!=-1)
					{
						v[j]=-1;
						printf("%c\n",(char)(65+j));
						enqueue(c->q,j);
					}
				}
			}
		}
	}
}

void push(struct stack *s,int x)
{
	s->top++;
	s->arr[s->top]=x;
}		
int pop(struct stack *s)
{
	s->top--;
	return s->arr[s->top+1];
}

int issEmpty(struct stack *s)
{
	if(s->top==-1)
		return 1;
	return 0;
}

int gettop(struct stack *s)
{
	return s->arr[s->top];
}

void DFS(struct cityADT *c,char st)
{
	int v[100];
	for(int i=0;i<c->rsize;i++)
		v[i]=1;
	for(int i=st-65;i<c->rsize;i++)
	{
		if(v[i]==1)
		{
			printf("%c\n",i+65);
			v[i]=-1;
			push(c->s,i);
			while(!issEmpty(c->s))
			{
				int f=0;
				int z=gettop(c->s);
				for(int i=0;i<c->csize;i++)
				{
					if(c->data[z][i]==1 && v[i]!=-1)
					{
						printf("%c\n",i+65);
						push(c->s,i);
						v[i]=-1;
						f=1;
						break;	
					}
				}
				if(f==0)
					pop(c->s);
			}
		}
	}
	for(int i=0;i<st-65;i++)
	{
		if(v[i]==1)
		{
			printf("%c\n",i+65);
			v[i]=-1;
			push(c->s,i);
			while(!issEmpty(c->s))
			{
				int f=0;
				int z=gettop(c->s);
				for(int i=0;i<c->csize;i++)
				{
					if(c->data[z][i]==1 && v[i]!=-1)
					{
						printf("%c\n",i+65);
						push(c->s,i);
						v[i]=-1;
						f=1;
						break;	
					}
				}
				if(f==0)
					pop(c->s);
			}
		}
	}
}
