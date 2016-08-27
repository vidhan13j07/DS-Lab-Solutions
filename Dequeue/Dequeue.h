#ifndef DEQUEUE_H__
#define DEQUEUE_H__
struct node
{
    int info;
    struct node *next;
};
typedef struct node node;

struct dequeue
{
    node *front;
    node *rear;
};
typedef struct dequeue dequeue;

node * getNode();
dequeue * createDequeue(dequeue *);
dequeue * insertFront(dequeue *,int);
dequeue * insertBack(dequeue *,int);
dequeue * eraseFront(dequeue *);
dequeue * eraseBack(dequeue *);
int front(dequeue *);
int back(dequeue *);
int size(dequeue *);
int empty(dequeue *);
void print(dequeue *);
#endif
