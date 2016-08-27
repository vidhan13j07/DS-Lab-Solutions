#include"AVL.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int height(node *nd)
{
    if (nd==NULL)
        return 0;
    return nd->height;
}

node* newNode(char * cr,int pr)
{
    node* tp= (node*)malloc(sizeof(node));
    strcpy(tp->car,cr);
    tp->price=pr;
    tp->left=NULL;
    tp->right=NULL;
    tp->height=1;
    return tp;
}
 
int max(int a, int b)
{
    if(a>b)
	return a;
    else
	return b;
} 
 
node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    return x;
}
 
node *leftRotate(node * x)
{
    node *y = x->right;
    node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;
}
int getBalance(node *nd)
{
    if (nd==NULL)
        return 0;
    return (height(nd->left) - height(nd->right));
}
node* insert(node* nd, char cr[], int pr)
{
    if (nd == NULL)
        return (newNode(cr,pr));
    if (strcmp(cr,nd->car) < 0)
        nd->left  = insert(nd->left,cr,pr);
    else
        nd->right = insert(nd->right,cr,pr);
    nd->height = max(height(nd->left), height(nd->right)) + 1;
    int balance = getBalance(nd);
    if (balance > 1 && strcmp(cr,nd->left->car) < 0)
        return rightRotate(nd);
    if (balance < -1 && strcmp(cr,nd->right->car) > 0)
        return leftRotate(nd);
    if (balance > 1 && strcmp(cr,nd->left->car) > 0)
    {
        nd->left =  leftRotate(nd->left);
        return rightRotate(nd);
    }
    if (balance < -1 && strcmp(cr,nd->right->car) < 0)
    {
        nd->right = rightRotate(nd->right);
        return leftRotate(nd);
    }
    return nd;
}

node* minValueNode(node* nd)
{
    node *curr=nd;
    while(curr->left != NULL)
        curr = curr->left;
    return curr;
}

node* DeleteNode(node* root, char cr[])
{
    if(root == NULL)
        return root;
    if(strcmp(cr,root->car)<0)
        root->left = DeleteNode(root->left,cr);
    else if(strcmp(cr,root->car)>0)
        root->right = DeleteNode(root->right,cr);
    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            node *temp=root->left?root->left:root->right;
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
             *root = *temp;
            free(temp);
        }
        else
        {
            node* temp = minValueNode(root->right);
            strcpy(root->car,temp->car);
            root->right = DeleteNode(root->right, temp->car);
        }
    }
    if (root == NULL)
      return root;
    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void Inorder(node *root)
{
    if(root != NULL)
    {
		Inorder(root->left);
        printf("%s\n",root->car);
        Inorder(root->right);
    }
}

void PriceRange(node *root, int low, int high)
{
	if(root==NULL)
		return ;
	PriceRange(root->left,low,high);
	if((root->price >=low)&&(root->price <=high))
		printf("%s\t",root->car);
	PriceRange(root->right,low,high);
}

void preorder(node *root)
{
    if(root==NULL)
        return ;
    printf("%s %d",root->car,root->price);
    preorder(root->left);
    preorder(root->right);
}
