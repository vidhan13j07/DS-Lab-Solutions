#ifndef QUEUE_H__
#define QUEUE_H__

struct node
{
    int info;
    struct node *next;
};
typedef struct node node;

struct queue
{
    node *front;
    node *rear;
};
typedef struct queue queue;
node * getNode();
queue * createQueue(queue *);
queue * enqueue(queue *,int);
queue * dequeue(queue *);
int isEmpty(queue*);

#endif
