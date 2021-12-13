struct cityADT
{
	int data[20][20],rsize,csize;
	struct queue *q;
	struct stack *s;
};

void create(struct cityADT *c);
void disp(struct cityADT *c);
void BFS(struct cityADT *c,char st);
void DFS (struct cityADT *c,char st);
void BFSmodify(struct cityADT *c);
int DFSmodify(struct cityADT *c,char st,char end);

struct queue
{
	int f,r,arr[100];
};

void enqueue(struct queue *q,int x);
int dequeue(struct queue *q);
int isEmpty(struct queue *q);

struct stack
{
	int top,arr[100];
};


void push(struct stack *s,int x);
int pop(struct stack*s);
int issEmpty(struct stack *s);


