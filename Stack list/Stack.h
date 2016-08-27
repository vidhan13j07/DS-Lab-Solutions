#ifndef STACK_H__
#define STACK_H__
struct node
{
    int info;
    struct node* next;
};
typedef struct node node;

struct stack
{
    node *top;
};
typedef struct stack stack;

node * getNode();
stack * createStack(stack *);
int isEmpty(stack *);
stack * push(stack *,int);
stack * pop(stack *);
int stackTop(stack *);

#endif
