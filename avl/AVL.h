#ifndef AVL_H__
#define AVL_H__

struct node
{
   char car[100];
   int price;
   struct node *left;
   struct node *right;
   int height;
};
typedef struct node node;

int height(node *);
node* newNode(char *,int);
int max(int,int);
node *rightRotate(node *);
node *leftRotate(node *);
int getBalance(node *);
node* insert(node *,char [],int);
node* minValueNode(node *);
node* DeleteNode(node *,char []);
void Inorder(node *);
void PriceRange(node *,int,int);
void preorder(node *);
#endif
