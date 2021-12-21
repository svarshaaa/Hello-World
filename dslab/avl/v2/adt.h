struct wordMeaning
{
    char *word,*mean;
};
struct dictionaryADT
{
    struct wordMeaning data;
    int height;
    struct dictionaryADT *left,*right;
};
int height(struct dictionaryADT *D);
struct dictionaryADT* insert(struct dictionaryADT*D, struct wordMeaning x);
struct dictionaryADT * singlerotatewithleft(struct dictionaryADT*k2);
struct dictionaryADT * singlerotatewithright(struct dictionaryADT*k2);
struct dictionaryADT* doublerotatewithleft(struct dictionaryADT*k3);
struct dictionaryADT* doublerotatewithright(struct dictionaryADT*k3);
void inorder(struct dictionaryADT*D);