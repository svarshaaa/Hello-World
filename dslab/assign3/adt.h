struct listADT
{
	char c;
	struct listADT * next,*prev;
};
void insertFront(struct listADT *l,char c);
void display(struct listADT *l);
void insertEnd(struct listADT *l,char c);
void insertMiddle(struct listADT *l, char c, char d);
void deleteItem(struct listADT*l, char c);
int searchItem(struct listADT*l, char c);