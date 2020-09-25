#pragma once

#define SIZE 100
typedef struct node* Nodeptr;

typedef struct
{
	int count;
	Nodeptr top;
} STACK_HEAD;

typedef STACK_HEAD* Stack;

typedef enum {false, true} bool;

typedef char stackItem; 

typedef struct node
{
	stackItem data;
	Nodeptr next;
} STACK_NODE;

Stack newStack();
void freeStack(Stack s);
void push(Stack s,stackItem item);
void pop(Stack s);
stackItem stackTop(Stack s);
int isEmpty(Stack s);
void display(Stack s);

Nodeptr createNode(stackItem item);
int isValid(Stack s, stackItem chars[]);
int isPair(stackItem item,stackItem top);
int isValidInput(stackItem chars[]);
void printDisplay(Stack s,int status);

#if defined(__linux__) || defined(__APPLE__)
#define CLEAR system("clear")
#define PAUSE system("read")
#else
#define CLEAR system("cls")
#define PAUSE system("pause")
#endif
