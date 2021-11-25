#include "adt.h"
#include<stdio.h>
#include<string.h>
void insert(struct arr*ptr)
{
	for(int i=0;i<ptr->n;i++)
	{
		printf("Student %d: (mark1,mark2,mark3,reg.no,name)\n",i+1);
		scanf("%d %d %d %d %s",&ptr->a[i].m1,&ptr->a[i].m2,&ptr->a[i].m3,&ptr->a[i].regno,ptr->a[i].name);
	}
}
	
void insertfront(struct arr *ptr,struct student s)
{
	for(int i=ptr->n-1;i>=0;i--)
	{
		ptr->a[i+1]=ptr->a[i];
	}
	ptr->a[0]=s;
	ptr->n++;
}

void insertend(struct arr*ptr,struct student s)
{
	ptr->a[ptr->n]=s;
	ptr->n++;
}

void insertmiddle(struct arr*ptr,struct student s,int regcheck)
{
	int index;
	for(int i=ptr->n-1;i>=0;i--)
	{
		if(ptr->a[i].regno==regcheck)
		{
			index=i;
			break;
		}
		else
			ptr->a[i+1]=ptr->a[i];
	}
	printf("%d",index);
	ptr->a[index+1]=s;
	ptr->n++;
}

void display(struct arr*ptr,char name[],int i)
{
	printf("Reg.no:%d Name:%s Mark1:%d Mark2:%d Mark3:%d\n",ptr->a[i].regno,ptr->a[i].name,ptr->a[i].m1,ptr->a[i].m2,ptr->a[i].m3);
}

void searchName(struct arr *ptr,char nam[20])
{
	for(int i=0;i<ptr->n;i++)
	{
		if(strcmp(ptr->a[i].name,nam)==0)
		{
			display(ptr,nam,i);
		}
	}
}

void delete(struct arr*ptr,int reg)
{
	int f=0;
	for(int i=0;i<ptr->n;i++)
	{
		if(f==1)
			ptr->a[i-1]=ptr->a[i];
		else if(ptr->a[i].regno==reg)
			f=1;			
	}
	ptr->n--;
}

void computeResult(struct arr*ptr)
{
	int tot=0;
	for(int i=0;i<ptr->n;i++)
	{
		tot=0;
		tot+=ptr->a[i].m1+ptr->a[i].m2+ptr->a[i].m3;
		ptr->a[i].total=tot;
		if(tot/3<45)
			printf("%s has failed\n",ptr->a[i].name);
		else
			printf("%s has passed\n",ptr->a[i].name);
	}
}

void listResult(struct arr*ptr)
{
	struct student pass_s;
	printf("List of students who have passed\n");
	for(int i=0;i<ptr->n;i++)
	{
		printf("%d\n",ptr->a[i].total);
		if(ptr->a[i].total/3>=45)
			display(ptr,ptr->a[i].name,i);
	}
} 

int listClass(struct arr*ptr)
{
	int count=0;
	printf("List of students who have secured first class\n");
	for(int i=0;i<ptr->n;i++)
	{
		if(ptr->a[i].total/3>90)
		{
			count++;
			display(ptr,ptr->a[i].name,i);;
		}
	}
	return count;
}

void displayall(struct arr*ptr)
{
	for(int i=0;i<ptr->n;i++)
	{
		display(ptr,ptr->a[i].name,i);
	}
}

