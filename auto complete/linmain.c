#include<stdio.h>
#include"linked.h"
#include<stdlib.h>
#include<string.h>

int main(){
	int i,a;
	list * li;
	li=(list *)malloc(sizeof(list));
	createlist(li);
	printf("Enter no. of elements to enter in list");
	scanf("%d",&a);
	for(i=0;i<a;i++)
		input(li);	
	search(li);
	return 0;	
}
