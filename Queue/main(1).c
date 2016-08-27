#include"Queue.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
    queue *q;
    int val,temp;
    q=createQueue(q);
    printf("\n\t\tOperations on Queue\n");
    while(1)
    {
        printf("\n\t\t1.Enqueue\n\t\t2.Dequeue\n\t\t3.Exit\n");
        scanf("%d",&temp);
        if(temp==1)
        {
            scanf("%d",&val);
            q=enqueue(q,val);
        }
        else if(temp==2)
            q=dequeue(q);
        else if(temp==3)
            break;
        else
            printf("\n\t\tWrong Input!Enter again\n");
    }
    return 0;
}
