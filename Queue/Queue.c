#include"Queue.h"
#include<stdio.h>
#include<stdlib.h>
node * getNode()
{
    node *p;
    p=(node *)malloc(sizeof(node));
    p->info=-1;
    p->next=NULL;
    return p;
}
queue * createQueue(queue *q)
{
    q=(queue *)malloc(sizeof(queue));
    q->front=getNode();
    q->rear=getNode();
    return q;
}
int isEmpty(queue *q)
{
    if((q->front==NULL && q->rear==NULL) || (q->front->info==-1 && q->rear->info==-1))
	return 0;
    return 1;
}
queue * enqueue(queue *q,int x)
{
    node *p;
    p=getNode();
    p->info=x;
    if(isEmpty(q)==0)
    {
        q->front=p;
        q->rear=p;
    }
    else
    {
       node *a=q->rear;
       a->next=p;
       q->rear=p; 
    }
    return q;
}
queue * dequeue(queue *q)
{
    if(isEmpty(q)==0)
    {
         printf("\n\t\tQueue is Empty!\n");
         return q;
    }
    node *p=q->front;
    q->front=p->next;
    printf("\n\t\tDequeued value is:%d\n",p->info);
    if(p==q->rear)
    {
        q->front=NULL;
        q->rear=NULL;
    }
    free(p);
    return q;
}
