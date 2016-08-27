#include"city.h"
#include<bits/stdc++.h>
using namespace std;

Node * createNode(char *s,int x,int y)
{
    Node *t=(Node*)malloc(sizeof(Node));
    t->s=(char*)malloc(sizeof(char));
    strcpy(t->s,s);
    t->x=x;
    t->y=y;
    t->left=NULL;
    t->right=NULL;
    return t;
}

Node * searchName(Node *root,char *s)
{
    if(root==NULL || (strcmp(root->s,s)==0))
        return root;
    if(strcmp(root->s,s)>0)
        return searchName(root->left,s);
    return searchName(root->right,s);
}

Node * searchCoord(Node *root,int x,int y)
{
    if(root==NULL || ((x==root->x)&&(y==root->y)))
        return root;
    if(searchCoord(root->left,x,y)==NULL)
        return searchCoord(root->right,x,y);
    return searchCoord(root->left,x,y);
}

Node * insertNode(Node *t,char *s,int x,int y)
{
    if(t==NULL)
        return createNode(s,x,y);
    if(strcmp(t->s,s)>0)
        t->left=insertNode(t->left,s,x,y);
    else if(strcmp(t->s,s)<0)
        t->right=insertNode(t->right,s,x,y);
    return t;
}

Node * findMin(Node *t)
{
    Node *curr=t;
    while(curr->left!=NULL)
        curr=curr->left;
    return curr;
}

int distanceNode(Node *a,int x,int y)
{
    return sqrt((a->x-x)*(a->x-x)+(a->y-y)*(a->y-y));
}

Node * deleteNode(Node *t,char *s)
{
    if(t==NULL)
        return t;
    if(strcmp(t->s,s)>0)
        t->left=deleteNode(t->left,s);
    else if(strcmp(t->s,s)<0)
        t->right=deleteNode(t->right,s);
    else
    {
        if(t->left==NULL)
        {
            Node* temp=t->right;
            t=NULL;
            return temp;
        }
        else if(t->right==NULL)
        {
            Node* temp=t->left;
            t=NULL;
            return temp;
        }
        Node *temp=findMin(t->right);
        strcpy(t->s,temp->s);
        t->right=deleteNode(t->right,temp->s);
    }
    return t;
}

void printWithin(Node *t,int d,int x,int y)
{
    if(t==NULL)
        return;
    printWithin(t->left,d,x,y);
    if(distanceNode(t,x,y)<=d)
        printf("name:%s x-coordinate:%d y:coordinate:%d\n",t->s,t->x,t->y);
    printWithin(t->right,d,x,y);
}

void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("city:%s x-coordinate:%d y-coordinate:%d\n",root->s,root->x,root->y);
    inorder(root->right);
}
