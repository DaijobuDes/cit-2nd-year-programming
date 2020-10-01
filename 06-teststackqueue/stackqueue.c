#include <stdio.h>
#include <stdlib.h>

#include "stackqueue.h"

/* START CREATE */
Stack createStack()
{
    Stack s = (Stack)malloc(sizeof(STACK_HEAD));
    s->count = 0;
    s->top = NULL;
    return s;
}

Queue createQueue()
{
    Queue q = (Queue)malloc(sizeof(QUEUE_HEAD));
    q->front = q->rear = NULL;
    q->count = 0;
    return q;
}

Nodeptr createNode(int item)
{
    Nodeptr ptr = (Nodeptr)malloc(sizeof(NODE));
    ptr->data = item;
    ptr->next = NULL;
    return ptr;
}
/* END CREATE */

/* START OPERATIONS */
void push(Stack s, int item)
{
    Nodeptr ptr = createNode(item);
    ptr->next = s->top;
    s->top = ptr;
    (s->count)++;
}

void pop(Stack s)
{
    Nodeptr ptr = s->top;
    s->top = ptr->next;
    ptr->next = NULL;
    free(ptr);
    (s->count)--;
}

/* START STACK */
void displayStack(Stack s)
{
    Nodeptr ptr = s->top;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int isStackEmpty(Stack s)
{
    return s->top == NULL;
}

int stackTop(Stack s)
{
    return s->top->data;
}

void freeStack(Stack s)
{
    Nodeptr ptr;
    while (s->top != NULL)
    {
        ptr = s->top;
        s->top = s->top->next;
        ptr->next = NULL;
        free(ptr);
        (s->count)--;
    }
}
/* END STACK */

/* START QUEUE */
void enqueue(Queue q, int item)
{
    Nodeptr ptr = createNode(item);
    if (isQueueEmpty(q))
        q->front = ptr;
    else
        q->rear->next = ptr;
    q->rear = ptr;
    (q->count)++;
}

void dequeue(Queue q)
{
    Nodeptr ptr = q->front;
    if (q->count)
        q->rear = NULL;
    q->front = q->front->next;
    ptr->next = NULL;
    free(ptr);
    q->count--;
}

void displayQueue(Queue q)
{
    Nodeptr ptr = q->front;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int isQueueEmpty(Queue q)
{
    return q->count == 0;
}

int queueFront(Queue q)
{
    return q->front->data;
}

void freeQueue(Queue q)
{
    Nodeptr ptr;
    while (q->front != NULL)
    {
        ptr = q->front;
        q->front = q->front->next;
        ptr->next = NULL;
        free(ptr);
        (q->count)--;
    }
}
/* END QUEUE */

void menu()
{
    char menu[] =
    "~~~~~ MENU ~~~~~~\n"
    "1. Insert (Enqueue)\n"
    "2. Delete (Dequeue)\n"
    "0. Exit\n"
    "\n"
    "Enter choice: ";
    printf(menu);
}




