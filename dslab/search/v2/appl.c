#include "impl.h"
#include<stdlib.h>
int main()
{
    struct numberADT*N=(struct numberADT*)malloc(sizeof(struct numberADT));
    init(N,10);
    int arr[100];
    printf("Enter elements:");
    for(int i=0;i<10;i++)
        scanf(" %d",&arr[i]);
    insertElements(N,arr);
    bsearchElementModify(N,7,1);
    bsearchElementModify(N,7,2);
    struct numberADT*N1=(struct numberADT*)malloc(sizeof(struct numberADT));
    struct numberADT*N2=(struct numberADT*)malloc(sizeof(struct numberADT));
    init(N1,7);
    printf("Enter elements:");
    for(int i=0;i<7;i++)
        scanf(" %d",&arr[i]);
    insertElements(N1,arr);
    init(N2,7);
    printf("Enter elements:");
    for(int i=0;i<7;i++)
        scanf(" %d",&arr[i]);
    insertElements(N2,arr);
    lsearchElementModify(N1,N2,3);
    struct numberADT*N3=(struct numberADT*)malloc(sizeof(struct numberADT));
    init(N3,6);
    printf("Enter elements:");
    for(int i=0;i<6;i++)
        scanf(" %d",&arr[i]);
    insertElements(N3,arr);
    lsearchElementModify(N3,N3,4);
    return 0;
}