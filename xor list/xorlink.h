#ifndef XORLINK_H__
#define XORLINK_H__

struct node
{
    int v;
    struct node *next;
};
typedef struct node node;

struct list
{
    node *h;
    node *t;
};
typedef struct list list;

node * getNode();
list * create(list *);
int empty(list *);
node * calXor(node *,node *);
list * insert(list *,int);
void tfront(list *);
void tback(list *);
list * delete(list * ,int);
#endif
