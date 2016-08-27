#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
    stack *st;
    st=(stack *)malloc(sizeof(stack));
    char k;
    int temp;
    create(st);
    while(1)
    {
        printf("\nOptions\n");
        printf("1.Push in Stack\n2.Pop from Stack\n3.Top element in Stack\n4.Print the stack\n5.Tell the size of stack\n6.Exit\n");
       scanf("%d",&temp);
       if(temp==1)
       {
            scanf(" %c",&k);
            push(st,k);
       }
       else if(temp==2)
       {
           k=pop(st);
           if(k=='\0')
               printf("Stack is Empty!\n");
           else
               printf("%c\n",k);
       }
       else if(temp==3)
       {
           k=top(st);
           if(k=='\0')
               printf("Stack is Empty!\n");
           else
               printf("%c\n",k);
       }
       else if(temp==4)
       {
           for(int i=0;i<st->sz;i++)
               printf("%c ",st->A[i]);
           printf("\n");
       }
       else if(temp==5)
           printf("%d\n",st->top);
       else if(temp==6)
           break;
       else
           printf("Wrong Input!\n");
    }
    return 0;
}
