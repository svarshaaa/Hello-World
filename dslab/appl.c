#include"impl.h"
#include<stdio.h>
int main()
{
	struct polyADT p1,p2,p3_add,*p3_mul,simp;
	p1.next=NULL;
	p2.next=NULL;
	int coeff,exp,count,ch;

	printf("Enter count of terms of first polynomial:");
	scanf("%d",&count);
	for(int i=0;i<count;i++)
	{
		printf("Enter coefficient and exponent of term %d:",i+1);
		scanf("%d %d",&coeff,&exp);
		insertEnd(&p1,coeff,exp);	
	}

	printf("Enter count of terms of second polynomial:");
	scanf("%d",&count);
	for(int i=0;i<count;i++)
	{
		printf("Enter coefficient and exponent of term %d:",i+1);
		scanf("%d %d",&coeff,&exp);
		insertEnd(&p2,coeff,exp);	
	}
	printf("\nDisplaying polynomial 1:");
	display(&p1);
	printf("\nDisplaying polynomial 2:");
	display(&p2);

	p3_add=polyAdd(&p1,&p2);
	printf("\nDisplaying sum of polynomials:");
	display(&p3_add);

	p3_mul=polyMul(&p1,&p2);
	printf("\nDisplaying product of polynomials:");
	display(p3_mul);

	printf("\nSimplifying polynomial(if there is a need of combining terms):");
	simp=polySimplify(p3_mul);
	display(&simp);

	printf("Degree of polynomial:\n");
	printf("Degree of which polynomial do you want? 1)First 2)Second 3)Sum 4)Product 5)Simplified version ");
	scanf("%d",&ch);
	if(ch==1)
		polyDegree(&p1);
	else if(ch==2)
		polyDegree(&p2);
	else if(ch==3)
		polyDegree(&p3_add);
	else if(ch==4)
		polyDegree(p3_mul);
	else
		polyDegree(&simp);
	printf("\nEvaluating polynomial:\n");
	printf("Which polynomial should be evaluated? 1)First 2)Second 3)Sum 4)Product 5)Simplified version ");
	scanf("%d",&ch);
	if(ch==1)
		polyEvaluate(&p1);
	else if(ch==2)
		polyEvaluate(&p2);
	else if(ch==3)
		polyEvaluate(&p3_add);
	else if(ch==4)
		polyEvaluate(p3_mul);
	else
		polyEvaluate(&simp);	


}
	
	
