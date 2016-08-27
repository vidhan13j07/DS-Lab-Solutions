#include"Stack.h"
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
stack * createStack(stack *st)
{
    st=(stack *)malloc(sizeof(stack));
    st->top=getNode();
    return st;
}
int isEmpty(stack *st)
{
   if(st->top==NULL)
       return 0;
    return 1;
}
stack *  push(stack *st,int x)
{
    node *p=getNode();
    p->next=st->top;
    p->info=x;
    st->top=p;
    return st;
}
stack *  pop(stack *st)
{
    if(isEmpty(st)==0)
    {	
         printf("\n\t\tStack is Empty\n");
         return st;
    }
    node *p=st->top;
    st->top=p->next;
    if(p->info!=-1)
         printf("\n\t\tPopped Value=%d\n",p->info);
    else
 	printf("\n\t\tStack is Empty\n");
    free(p);
    return st;
}
int stackTop(stack *st)
{
    if(isEmpty(st)==0)
        return -1;
    node *p=st->top;
    return p->info;
}
