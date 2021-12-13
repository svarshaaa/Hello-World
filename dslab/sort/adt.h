struct numberADT
{
    int arr[100],n;
};
void init(struct numberADT *N,int n);
void insertElements (struct numberADT *N, int x[10]);
void selSort(struct numberADT *N);
void shellSort(struct numberADT *N);
void display(struct numberADT *N);
