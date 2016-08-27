#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>
void create(stack *s)
{
    s->sz=500;
    s->top=0;
    s->A=(char *)malloc(s->sz*sizeof(char));
}
void push(stack *s,char st)
{
    if(isFull(s)==0)
    {
         printf("\nStack is Full!You cannot insert more\n");
         return ;
    }
    s->A[s->top++]=st;
}
char pop(stack *s)
{
    if(isEmpty(s)==0)
          return '\0';
    s->top--;
    char st=s->A[s->top];
    s->A[s->top]='\0';
    return st;
}
char top(stack *s)
{
    if(isEmpty(s)==0)
           return '\0';
    return s->A[s->top-1];
}
int isFull(stack *s)
{
    if(s->top==s->sz)
	return 0;
    return 1;
}
int isEmpty(stack *s)
{
    if(s->top==0)
         return 0;
    return 1;
}
