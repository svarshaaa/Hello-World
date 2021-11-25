struct poly
{
	int coeff,exp;
};
struct polyADT
{
	struct poly p;
	struct polyADT * next;
};
void insertEnd(struct polyADT * header,int coeff,int exp);
struct polyADT polyAdd(struct polyADT* p1,struct polyADT* p2);
struct polyADT*polyMul(struct polyADT*p1,struct polyADT *p2);
void display(struct polyADT*header);
struct polyADT polySimplify(struct polyADT*p);
void polyDegree(struct polyADT *p); 
int polyEvaluate(struct polyADT *p);

