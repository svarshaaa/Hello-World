#include "impl.h"
#include<stdlib.h>
int main()
{
	struct cityADT *c,*c1;
	c=(struct cityADT *)malloc(sizeof(struct cityADT));
	c->q=(struct queue *)malloc(sizeof(struct queue));
	c->s=(struct stack *)malloc(sizeof(struct stack));
	c->q->f=c->q->r=-1;
	c->s->top=-1;
	create(c);
    if(DFSmodify(c,'F','B'))
		printf("There is path from start to end\n");
	else
		printf("There is no path from start to end");
	c1=(struct cityADT *)malloc(sizeof(struct cityADT));
	c1->q=(struct queue *)malloc(sizeof(struct queue));
	c1->s=(struct stack *)malloc(sizeof(struct stack));
	c1->q->f=c1->q->r=-1;
	c1->s->top=-1;
	create(c1);
	BFSmodify(c1);
	
}
