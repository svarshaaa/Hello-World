struct BST
{
    int data;
    struct BST *left,*right;
};
struct BST * insert(struct BST *t,int x);
struct BST * del(struct BST *t,int x);
void inorder(struct BST *t);
void levelorder(struct BST*t);
struct BST* find(struct BST* t,int x);
struct BST*findmin(struct BST*t);
void inorderModify(struct BST*t,int arr[],int *n);
