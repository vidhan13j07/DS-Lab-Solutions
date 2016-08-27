#ifndef STACK_H__
#define STACK_H__
struct stack
{
	char *A;
	int top;
	int sz;
};
typedef struct stack stack;
void create(stack *);
void push(stack *,char);
char pop(stack *);
char top(stack *);
int isEmpty(stack *);
int isFull(stack *);

#endif
