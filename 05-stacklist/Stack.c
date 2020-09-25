#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

int isValidInput(stackItem chars[])
{
	int i, value = 0; 
	for (i = 0; chars[i] != '\n'; i++)
	{
		if (chars[i] == '(' || chars[i] == ')' || chars[i] == '[' || chars[i]== ']' || chars[i] == '{' || chars[i]== '}')
			value = 1;
		else 
		{
			value = 0; 
			break;
		}
	}
	return value; 
}

Stack newStack()
{
	Stack s = (Stack) malloc(sizeof(STACK_HEAD));
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
	while (s->top != NULL)
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

void pop(Stack s)
{
	Nodeptr temp; 
	temp = s->top; 
	s->top = temp->next; 
	temp->next = NULL;
	free(temp);
	(s->count)--;
}

stackItem stackTop(Stack s)
{
	return s->top->data;	
}

int isEmpty(Stack s)
{
	return s->top == NULL;
}

int isValid(Stack s, stackItem chars[])
{
	int i, value = 1; 
	// int pair = 1;
	stackItem top;
	// Used \n because used fgets for input
	for (i = 0; chars[i] != '\n'; i++)
	{
		if (chars[i] == '(' || chars[i] == '{' || chars[i] == '[')
			push(s,chars[i]);
		else 
		{
			if (isEmpty(s))
			{
				value = 0;
				break; 
			}
			else 
			{
				top = stackTop(s);
				if (isPair(chars[i], top))
				{
					pop(s);
					value = 1; 
				}
				else
				{
					value = 0; 
					break; 
				}
			}
		}
	}
	return (isEmpty(s) && value == 1);
}

int isPair(stackItem item,stackItem top)
{
	int value;
	if (top == '(' && item == ')')
		value = 1; 
	else if (top == '{' && item== '}')
		value = 1;
	else if (top== '[' && item== ']')
		value = 1; 
	else 
		value = 0;
	return value;  
}

void display(Stack s)
{
	Nodeptr ptr = s->top;
	while (ptr != NULL)
	{
		printf("%c ", ptr->data);
		ptr = ptr->next; 
	}
	printf("\n");
}

void printDisplay(Stack s,int status)
{
	if (status != 1)
	{
		if (s->top != NULL)
		{
			printf("\n\nRemaining Stack: \n");
			display(s);
		}
	} 
	else
		printf("\n\nStack is empty due to balanced symbols.\n");
}
