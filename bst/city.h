#ifndef CITY_H__
#define CITY_H__

struct Node
{
    struct Node *left;
    struct Node *right;
    char *s;
    int x;
    int y;

};
typedef struct Node Node;

Node * createNode(char *,int,int);
Node * searchName(Node *,char *);
Node * searchCoord(Node *,int,int);
Node * insertNode(Node *,char *,int,int);
Node * findMin(Node *);
int distanceNode(Node *,int,int);
Node * deleteNode(Node *,char *);
void printWithin(Node *,int,int,int);
void inorder(Node *);

#endif
