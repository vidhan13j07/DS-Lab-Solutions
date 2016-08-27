#include"city.h"
#include<bits/stdc++.h>
using namespace std;

int main()
{
    Node *root=NULL;
    int n;
    while(1)
    {
        printf("Please Select an Option: \n");
        printf("1:Insert a record of city\n2:Search by Name\n3:Search by Coordinate\n4:Print\n5:Delete a city by name\n6:Find city at within a distance\n7:Delete a city by coordinates\n8:EXIT!\n");
        scanf("%d",&n);
        if(n==1)
        {
            char s[50];
            int x,y;
            printf("Please Enter the name of city\n");
            scanf("%s",s);
            printf("Please Enter the Coordinates\n");
            scanf("%d%d",&x,&y);
            root=insertNode(root,s,x,y);
        }
        else if(n==2)
        {
            char s[50];
            printf("Please enter the name you want to search\n");
            scanf("%s",s);
            if(searchName(root,s)==NULL)
                printf("The city with the given name does not exist\n");
            else
            {
                printf("The coordinates are:\n");
                printf("X: %d Y: %d\n",searchName(root,s)->x,searchName(root,s)->y);
            }
        }
        else if(n==3)
        {
            int x,y;
            printf("Please Enter the coordinate you want to search:\n");
            scanf("%d%d",&x,&y);
            if(searchCoord(root,x,y)==NULL)
                printf("The city with the given coordinates does not exist\n");
            else
            {
                printf("The city name is:\n");
                printf("%s\n",searchCoord(root,x,y)->s);
            }
        }
        else if(n==4)
        {
            inorder(root);
            printf("\n");
        }
        else if(n==5)
        {
            char s[50];
            printf("Enter the name of city you want to delete:\n");
            scanf("%s",s);
            root=deleteNode(root,s);
         }
        else if(n==6)
        {
            int d,x,y;
            printf("Enter the coordinates and the distance\n");
            scanf("%d%d%d",&x,&y,&d);
            printWithin(root,d,x,y);
            printf("\n");
        }
        else if(n==7)
        {
            printf("Enter the coordinates:\n");
            int x,y;
            scanf("%d %d",&x,&y);
            Node *temp=searchCoord(root,x,y);
            if(temp==NULL)
                printf("The city does not exist\n");
            else
                root=deleteNode(root,temp->s);
        }
        else if(n==8)
                break;
        else
            printf("Wrong Choice!Enter Again!\n");
    }
    return 0;
}
