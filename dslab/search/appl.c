#include "impl.h"
#include<stdlib.h>
int main()
{
    struct numberADT*N=(struct numberADT*)malloc(sizeof(struct numberADT));
    init(N,10);
    int arr[100];
    for(int i=0;i<10;i++)
        scanf(" %d",&arr[i]);
    insertElements(N,arr);
    printf("%d\n",lsearchElement(N,7));
    printf("%d\n",bsearchElement(N,7));
    return 0;
}