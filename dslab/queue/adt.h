struct Queue
{
    int arr[100],f,r,iter,size;
};
void enqueu(struct Queue *Q, int x);
int dequeue(struct Queue *Q);
void disp(struct Queue *Q);
int isEmpty(struct Queue *Q);
int isFull(struct Queue *Q);
