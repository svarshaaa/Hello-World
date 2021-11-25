struct stackADT
{
    int data[100],size,top;
};
void initStack(struct stackADT*s,int si);
void push(struct stackADT *s,int c);
void pop(struct stackADT *s);
int top(struct stackADT *s);
int isFull(struct stackADT *s);
int isEmpty(struct stackADT *s);
void display(struct stackADT *s);
