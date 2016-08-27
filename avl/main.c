#include"AVL.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  node *root=NULL;
  int ch=1,p,low,high;
  char nm[100];
  while(1)
  {
	printf("Enter your choice\n");
  	printf("Press 1 to insert a new detail\n");
  	printf("Press 2 to delete a car detail\n");
  	printf("Press 3 to get all cars in your price range\n");
        printf("4 to print in preorder\n");
  	printf("Press 5 to exit\n");
	scanf("%d",&ch);
	if(ch==1)
        {
	    printf("Enter the car name and price\n");
	    scanf("%s",nm);
	    scanf("%d",&p);
	    root=insert(root,nm,p);
        }
        else if(ch==2)
        {
	    printf("Enter car name to delete\n");
	    scanf("%s",nm);
	    root=DeleteNode(root,nm);
        }
        else if(ch==3)
	{
	    printf("Enter price range\n");
	    scanf("%d %d",&low,&high);
	    PriceRange(root,low,high);
	    printf("\n");
        }
        else if(ch==4)
            preorder(root);
	else if(ch==5)
            break;
        else
	    printf("Wrong Choice\n");
 }
  return 0;
}
