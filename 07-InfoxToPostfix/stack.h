#pragma once

typedef struct node* Nodeptr;

typedef struct
{
	int count;
	Nodeptr top;
} STACK_HEAD;

typedef STACK_HEAD* Stack;

typedef float stackItem; 

typedef struct node 
{
	stackItem data;
	Nodeptr next;
} STACK_NODE;


Stack newStack();
void freeStack(Stack s);
void push(Stack s, stackItem item); 
stackItem pop(Stack s); 
stackItem stackTop(Stack s); 
int isEmpty(Stack s);
void display(Stack s);
Nodeptr createNode(stackItem item);
