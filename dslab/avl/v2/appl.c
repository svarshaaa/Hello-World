#include<stdio.h>
#include "impl.h"
#include<stdlib.h>
int main()
{
    struct dictionaryADT *D=NULL;
    struct wordMeaning x;
    x.word="bisk";
    x.mean="soup";
    D=insert(D,x);
    x.word="cite";
    x.mean="refer";
    D=insert(D,x);
    x.word="boom";
    x.mean="sound";
    D=insert(D,x);
    x.word="able";
    x.mean="opportunity";
    D=insert(D,x);
    x.word="aged";
    x.mean="old";
    D=insert(D,x);
    x.word="crew";
    x.mean="group of people";
    D=insert(D,x);
    printf("Ascending order:\n");
    inorder(D);
    printf("Searching:\n");
    search(D,"cite");
    return 0;
}