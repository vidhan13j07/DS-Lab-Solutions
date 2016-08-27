#ifndef LINKED_H_
#define LINKED_H_

typedef struct node
{	char val[50];
	struct node * next;
}node;

typedef struct list
{	node * front;
	int count;
}list;

void createlist(list *);
node * getnode();
void input(list *);
void search(list *);

#endif
