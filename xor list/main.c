#include"xorlink.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int ch;
    list *li;
    li=create(li);
    while(1)
    {
        printf("\n\t\t1.Insert\n\t\t2.Print from start to end\n\t\t3.Print from back to start\n\t\t4.Delete a value\n\t\tExit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            int temp;
            printf("\n\t\tEnter the value\n");
            scanf("%d",&temp);
            li=insert(li,temp);
        }
        else if(ch==2)
            tfront(li);
        else if(ch==3)
            tback(li);
        else if(ch==4)
        {
            int temp;
            printf("\n\t\tEnter the value to be deleted\n");
            scanf("%d",&temp);
            li=delete(li,temp);
        }
        else if(ch==5)
            break;
        else
            printf("\n\t\tWrong Input!Enter again.\n");
    }
    return 0;
}
