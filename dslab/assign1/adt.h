struct student
{
	int m1,m2,m3,regno,total;
	char name[20];
};
struct arr
{
	struct student a[100];
	int n;
};
void insert(struct arr*ptr);
void insertfront(struct arr* ptr,struct student s);
void insertend(struct arr* ptr,struct student s);
void insertmiddle(struct arr* ptr,struct student s,int regcheck);
void display(struct arr*ptr,char name[],int i);
void searchName(struct arr*ptr,char name[]);
void delete(struct arr*ptr,int reg);
void computeResult(struct arr*ptr);
void listResult(struct arr*ptr);
int listClass(struct arr*ptr);
void displayall(struct arr*ptr);
