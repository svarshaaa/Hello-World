struct numberADT
{
    int n,arr[100];
};

struct ie
{   
    int ind,elt;
};
void init(struct numberADT *N,int n);
void insertElements(struct numberADT *N,int x[10]);
int lsearchElement(struct numberADT *N,int key);
int bsearchElement(struct numberADT *N,int key);
void display(struct numberADT*N);