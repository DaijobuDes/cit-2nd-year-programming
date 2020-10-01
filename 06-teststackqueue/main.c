#include <stdio.h>
#include <stdlib.h>

#include "stackqueue.h"

int main()
{
    /* Stack I/O */
    Stack IStack = createStack();
    Stack OStack = createStack();
    /* Queue I/O */
    Queue IQueue = createQueue();
    Queue OQueue = createQueue();

    int deltop, delfro;
    int run = 1;
    int choice, item, count = 0;

    while (run) // START WHILE LOOP
    {
        CLEAR;
        menu();
        scanf("%d", &choice);

        switch (choice) // START SWITCH
        {
        case 1:
            printf("Enter item: ");
            scanf("%d", &item);
            
            push(IStack, item);
            enqueue(IQueue, item);
            count++;
            break;
        
        case 2:
            if (!count)
            {
                printf("\n\nList is empty. Try placing some first.");
                break;
            }
            deltop = stackTop(IStack);
            pop(IStack);
            enqueue(OQueue, deltop);
            delfro = queueFront(IQueue);
            dequeue(IQueue);
            push(OStack, delfro);
            break;

        case 0:
            /* Terminate the program by ending loop */
            run = 0;
            break;

        default:
            printf("\nIncorrect choice made.");
            break;
        } // END SWITCH

        if (isStackEmpty(IStack) && isQueueEmpty(IQueue))
        {
            printf("\n\nStack and Queue is empty. Terminating...\n ");
            run = 0;
        }
        else
        {
            printf("\n~~~~~~ OUTPUT ~~~~~~\n");
            printf("Output Stack: ");
            displayStack(IStack);
            printf("Output Queue: ");
            displayQueue(IQueue);
        }
        PAUSE;
        fflush(stdin);
    } // END WHILE LOOP

    if (isStackEmpty(IStack) && isQueueEmpty(IQueue))
    {
        printf("\nOutput Stack: ");
        displayStack(OStack);
        free(OStack);

        printf("\nOutput Queue: ");
        displayQueue(OQueue);
        free(OQueue);
    }

    return 0;
}