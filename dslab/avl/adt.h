struct avl
{
    int data,height;
    struct avl *left,*right;
};
int height(struct avl *t);
struct avl* insert(struct avl*t, int x);
struct avl * singlerotatewithleft(struct avl*k2);
struct avl * singlerotatewithright(struct avl*k2);
struct avl* doublerotatewithleft(struct avl*k3);
struct avl* doublerotatewithright(struct avl*k3);
void inorder(struct avl*t);