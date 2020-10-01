#pragma once

typedef struct node *Nodeptr;

typedef struct node
{
    int data;
    Nodeptr next;
} NODE;

typedef struct
{
    Nodeptr front;
    int count;
    Nodeptr rear;
} QUEUE_HEAD;

typedef struct
{
    int count;
    Nodeptr top;
} STACK_HEAD;

typedef STACK_HEAD *Stack;
typedef QUEUE_HEAD *Queue;

typedef enum {false, true} bool;

Stack createStack();
Queue createQueue();
Nodeptr createNode(int item);

void push(Stack s, int item);
void pop(Stack s);
void displayStack(Stack s);
int isStackEmpty(Stack s);
int stackTop(Stack s);
void freeStack(Stack s);

void enqueue(Queue q, int item);
void dequeue(Queue q);
void displayQueue(Queue q);
int isQueueEmpty(Queue q);
int queueFront(Queue q);
void freeQueue(Queue q);

void menu();

#if defined(__linux__) || defined(__APPLE__)
#define CLEAR system("clear")
#define PAUSE system("read")
#else
#define CLEAR system("cls")
#define PAUSE system("pause")
#endif

