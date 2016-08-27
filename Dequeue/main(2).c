#include"Dequeue.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
    dequeue *dq;
    dq=createDequeue(dq);
    int val,temp;
    printf("\n\t\tOperations on Dequeue\n");
    while(1)
    {
        printf("\n\t\t1.Insert Front\n\t\t2.Insert Back\n\t\t3.Erase Front\n\t\t4.Erase Back\n\t\t5.Front Element\n\t\t6.Back Element\n\t\t7.Size of Dequeue\n\t\t8.Print the Dequeue\n\t\t9.Exit\n");
        scanf("%d",&temp);
        if(temp==1)
        {
             scanf("%d",&val);
             dq=insertFront(dq,val);
        }
        else if(temp==2)
        {
             scanf("%d",&val);
             dq=insertBack(dq,val);
        }
        else if(temp==3)
             dq=eraseFront(dq);
        else if(temp==4)
             dq=eraseBack(dq);
        else if(temp==5)
        {
            temp=front(dq);
            if(temp==-1)
                printf("\n\t\tDequeue is Empty!\n"); 
            else
               printf("\n\t\tFront value is=%d\n",temp);
        }
        else if(temp==6)
        {
             temp=back(dq);
             if(temp==-1)
                  printf("\n\t\tDequeue is empty\n");
             else
                  printf("\n\t\tBack value is %d\n",temp);
        }
        else if(temp==7)
	     printf("\n\t\tSize of Dequeue is=%d\n",size(dq));
        else if(temp==8)
             print(dq);
        else if(temp==9)
             break;
        else
             printf("\n\t\tWrong Input! Enter Again.\n");
    }
    return 0;
}
