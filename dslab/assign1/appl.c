#include "impl.h"
int main()
{
	struct arr s;
	struct student st;
	int regno,count,ch,regcheck;
	printf("Enter count of students:");
	scanf("%d",&s.n);	
	insert(&s);
	do
	{
		printf("\nEnter choice: 1)Insertfront 2)Insertend 3)Insertmiddle 4)Display information of a student "
		"5)Delete a record 6)Calculate total and find who all have passed "
		"7)List records of students who have passed 8)List the students who have secored first class 9)Display all 10)quit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter information of student that need to be inserted at the front(mark1,mark2,mark3,reg.no,name)\n");
			scanf("%d %d %d %d %s",&st.m1,&st.m2,&st.m3,&st.regno,st.name);
			insertfront(&s,st);
		}
		else if(ch==2)
		{
			printf("Enter information of student that need to be inserted at the end(mark1,mark2,mark3,reg.no,name)\n");
			scanf("%d %d %d %d %s",&st.m1,&st.m2,&st.m3,&st.regno,st.name);
			insertend(&s,st);
		}
		else if(ch==3)
		{

			printf("Enter information of student that need to be inserted at middle and also the "
			"reg.no after which it should be inserted(mark1,mark2,mark3,reg.no,name,reg.no to check)\n");
			scanf("%d %d %d %d %s %d",&st.m1,&st.m2,&st.m3,&st.regno,st.name,&regcheck);
			insertmiddle(&s,st,regcheck);
		}
		else if(ch==4)
		{
			printf("Enter name of stduent whose information should be displayed\n");
			char name[20];
			scanf("%s",name);
			searchName(&s,name);
		}	
		else if(ch==5)
		{
			printf("Enter reg.no of student whose information should be deleted\n");
			scanf("%d",&regcheck);
			printf("Deleting record\n");
			delete(&s,regcheck);
		}	
		else if(ch==6)
		{
			computeResult(&s);
		}
		else if(ch==7)
		{
			listResult(&s);
		}
		else if(ch==8)
		{
			printf("Total of %d students have secured first class\n",listClass(&s));
		}
		else if(ch==9)
			displayall(&s);
	}while(ch!=10);
	return 0;
}
