#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

Stack newStack()
{
	Stack s = (Stack)malloc(sizeof(STACK_HEAD));
	s->count = 0; 
	s->top = NULL;
	return s;
}

Nodeptr createNode(stackItem item)
{
	Nodeptr ptr = (Nodeptr)malloc(sizeof(STACK_NODE));
	ptr->data = item; 
	ptr->next = NULL;
	return ptr;
}

void freeStack(Stack s)
{
	Nodeptr temp;
	while(s->top != NULL)
    {
		temp = s->top;
		s->top = s->top->next;
		temp->next = NULL; 
		free(temp);
		(s->count)--;
	}
}

void push(Stack s,stackItem item)
{
	Nodeptr temp = createNode(item);
	temp->next = s->top;
	s->top = temp;
	(s->count)++; 
}

stackItem pop(Stack s)
{
	Nodeptr temp; 
	temp = s->top; 
	stackItem item = temp->data; 
	s->top = temp->next; 
	temp->next = NULL;
	free(temp);
	(s->count)--;
	return item;
}

stackItem stackTop(Stack s)
{
	return s->top->data;	
}

int isEmpty(Stack s)
{
	return s->top == NULL;
}

void display(Stack s){
	Nodeptr ptr = s->top;
	while(ptr != NULL)
    {
		printf("%c ", (char)ptr->data);
		ptr = ptr->next; 
	}
	printf("\n");
}
