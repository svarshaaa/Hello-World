#include "impl.h"
#include<stdlib.h>
int main()
{
	struct cityADT *c;
	c=(struct cityADT *)malloc(sizeof(struct cityADT));
	c->q=(struct queue *)malloc(sizeof(struct queue));
	c->s=(struct stack *)malloc(sizeof(struct stack));
	c->q->f=c->q->r=-1;
	c->s->top=-1;
	create(c);
	disp(c);
	BFS(c,'A');
	printf("dfs\n");
	DFS(c,'A');
}
