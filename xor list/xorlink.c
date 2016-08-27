#include"xorlink.h"
#include<stdlib.h>
#include<stdio.h>
node * getNode()
{
    node *p=(node *)malloc(sizeof(node));
    p->next=NULL;
    p->v=-1;
    return p;
}

node * calXor(node *p,node *q)
{
    return (node *)((unsigned int) (p) ^ (unsigned int) (q));
}

list * create(list *l)
{
    l=(list *)malloc(sizeof(list));
    l->h=getNode();
    l->t=getNode();
    l->h=NULL;
    l->t=NULL;
    return l;
}

int empty(list *l)
{
    if(l->h==NULL && l->t==NULL)
        return 1;
    return 0;
}

list * insert(list *l,int val)
{
    node *p=getNode();
    p->v=val;
    p->next=calXor(l->h,NULL);
    if(!empty(l))
    {
        node *temp=calXor(l->h->next,NULL);
        l->h->next=calXor(temp,p);
    }
    else
        l->t=p;
    l->h=p;
    return l;
}

void tfront(list *l)
{
    if(empty(l))
    {
        printf("\n\t\tList is Empty!\n");
        return ;
    }
    node *cur=l->h;
    node *prev=NULL;
    node *temp;
    printf("\n\t\tThe values of the list are : ");
    while(cur!=NULL)
    {
        printf(" %d ",cur->v);
        temp=calXor(cur->next,prev);
        prev=cur;
        cur=temp;
    }
    printf("\n");
}

void tback(list *l)
{
    if(empty(l))
    {
        printf("\n\t\tList is empty!\n");
        return ;
    }
    node *cur=l->t;
    node *front=NULL;
    node *temp;
    printf("\n\t\tThe values of the list are : ");
    while(cur!=NULL)
    {
        printf(" %d ",cur->v);
        temp=calXor(cur->next,front);
        front=cur;
        cur=temp;
    }
    printf("\n");
}

list * delete(list *l,int val)
{
    if(empty(l))
        printf("\n\t\tList is Empty!Cannot delete an element.\n");
    else if(l->h==l->t)
    {
        if(l->h->v==val)
        {
            l->h=NULL;
            l->t=NULL;
        }
        else
            printf("\n\t\tNumber is not present in list.\n");
    }
    else
    {
        int f=0;
        node *cur=l->h;
        node *prev=NULL;
	node *temp;
        while(cur!=NULL)
        {
            if(cur->v==val)
            {
                if(cur==l->h)
                {
                    node *temp=cur->next;
                    temp->next=calXor(temp->next,cur);
                    temp->next=calXor(temp->next,NULL);
                    l->h=temp;
                    free(cur);
                }
                else if(cur==l->t)
                {
                    prev->next=calXor(prev->next,cur);
                    prev->next=calXor(prev->next,NULL);
                    l->t=prev;
                    free(cur);
                }
                else
                {
                    temp=calXor(prev,cur->next);
                    temp->next=calXor(calXor(temp->next,cur),prev);
                    prev->next=calXor(calXor(prev->next,cur),temp);
                    //free(temp);
                }
                f=1;
                break;
            }
            temp=calXor(cur->next,prev);
            prev=cur;
            cur=temp;
        }
        if(f==0)
            printf("\n\t\tNumber is not present in the list\n");
    }
    return l;
}
