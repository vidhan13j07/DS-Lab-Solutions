#include"Dequeue.h"
#include<stdio.h>
#include<stdlib.h>
node * getNode()
{
   node *p=(node *)malloc(sizeof(node));
   p->info=-1;
   p->next=NULL;
   return p;
}
dequeue * createDequeue(dequeue *dq)
{
    dq=(dequeue *)malloc(sizeof(dequeue));
    dq->front=getNode();
    dq->rear=getNode();
    return dq;
}
int empty(dequeue *dq)
{
   if((dq->front==NULL && dq->rear==NULL) || (dq->front->info==-1 && dq->rear->info==-1))
         return 1;
   return 0;
}
dequeue * insertFront(dequeue *dq,int x)
{
    node *p=getNode();
    p->info=x;
    if(empty(dq))
    {
         dq->front=p;
         dq->rear=p;
    }
    else
    {
         p->next=dq->front;
         dq->front=p;
    }
    return dq;
}
dequeue * insertBack(dequeue *dq,int x)
{
    node *p=getNode();
    p->info=x;
    if(empty(dq))
    {
         dq->front=p;
         dq->rear=p;
    }
    else
    {
         node *a=dq->rear;
         a->next=p;
         dq->rear=p;
    }
    return dq;
}
dequeue * eraseFront(dequeue *dq)
{
    if(empty(dq))
    {
         printf("\n\t\tDequeue is Empty!\n");
         return dq;
    }
    node *p=dq->front;
    dq->front=p->next;
    printf("\n\t\tDequeued value from front is=%d\n",p->info);
    if(p==dq->rear)
    {
        dq->front=NULL;
        dq->rear=NULL;
    }
    free(p);
    return dq;
}
dequeue * eraseBack(dequeue *dq)
{
    if(empty(dq))
    {
	 printf("\n\t\tDequeue is Empty!\n");
         return dq;
    }
    node *p=dq->front;
    if(p->next!=NULL)
        while(p->next!=dq->rear)
            p=p->next;
    printf("\n\t\tDequeued value from back is=%d\n",dq->rear->info);
    if(p==dq->front)
    {
         dq->front=NULL;
         dq->rear=NULL;
    }
    else
    {
        dq->rear=p;
        p=p->next;
    }
    free(p);
    return dq;
} 
int front(dequeue *dq)
{
    if(empty(dq))
         return -1;
    return dq->front->info;
}
int back(dequeue *dq)
{
    if(empty(dq))
          return -1;
    return dq->rear->info;
}
int size(dequeue *dq)
{
    int sz=0;
    if(!empty(dq))
    {
        node *p=dq->front;
        while(1)
        {
             sz++;
             if(p==dq->rear)
                 break;
             p=p->next;
        }
    }
    return sz;
}
void print(dequeue *dq)
{
    node *p=dq->front;
    if(!size(dq))
    {
        printf("\n\t\tNo elements in the Deque\n");
        return ;
    }
    printf("\n\t\tArray Elements:");
    while(p!=NULL)
    {
        printf("%d  ",p->info);
        p=p->next;
    } 
    printf("\n");
}
