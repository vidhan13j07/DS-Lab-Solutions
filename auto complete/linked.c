#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "linked.h"

void createlist(list *li){
	li->front=NULL;
	li->count=0;
}

node * getnode(){
	node* p;
	p=(node *) malloc(sizeof(node));
	return p;
}

void input(list * li){
	int cmp,i,fl=0;
	node * ptr=getnode();
	node * ptr2=li->front;
	node * ptr3=li->front;
	printf("Enter the string\n");
	scanf("%s",ptr->val);
	if(li->front==NULL){
		li->front=ptr;
		li->front->next=NULL;
	}
	else 
	{	cmp=strcmp(ptr->val,ptr2->val);
		while(cmp>=0)
		{	ptr2=ptr2->next;
			if(ptr2==NULL)
			{	fl++;
				break;
			}
			cmp=strcmp(ptr->val,ptr2->val);
			fl++;
		}
		for(i=0;i<fl-1;i++)
			ptr3=ptr3->next;
		if(fl==0)
		{	ptr->next=ptr2;
			li->front=ptr;
		}
		else if(fl!=li->count)
		{	ptr->next=ptr2;
			ptr3->next=ptr;
		}
		else
		{	ptr3->next=ptr;
			ptr->next=NULL;
		}
	}
	li->count++;
}

void search(list *li){
	int i,len,j,fl;
	char str[50];
	node * ptr=li->front;
	printf("Enter your command\n");
	scanf("%s",str);
	len=strlen(str);
	if(li->front==NULL)	printf("\n");
	else{
		for(i=0;i<li->count;i++){
			fl=0;
			for(j=0;j<len;j++){
				if(ptr->val[j]!=str[j]){
					fl=1;
					break;
				}
			}
			if(fl==0)
				printf("%s/ ",ptr->val);
			ptr=ptr->next;
		}
	}
}
