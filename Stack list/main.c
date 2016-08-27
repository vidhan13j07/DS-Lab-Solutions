#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
    stack *s;
    int val,temp;
    s=createStack(s);
    while(1)
    {
        printf("\n\t\t1.Push\n\t\t2.Pop\n\t\t3.TopElement\n\t\t4.Exit\n");
        scanf("%d",&temp);
        if(temp==1)
        {
            scanf("%d",&val);
            s=push(s,val);
        }
        else if(temp==2)
            s=pop(s);
        else if(temp==3)
        {
            val=stackTop(s);
            if(val==-1)
                printf("\n\t\tStack is Empty\n");
            else
                printf("\n\t\tTop element of stack is:%d\n",val);
        }
        else if(temp==4)
            break;
        else
            printf("\n\t\tWrong Input!Enter again\n");
    }
    return 0;
}
