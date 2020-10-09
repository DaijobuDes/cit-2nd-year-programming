#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "InfixToPostfix.h"
#include "util.h"

int main()
{
    Stack s = newStack();
    Stack p = newStack();

    char infix[SIZE], postfix[SIZE];
    int run = 1, t = 0;

    while (run)
    {
        while (t != 1)
        {
            printf("Infix: ");
            fgets(infix, SIZE, stdin);
            t = validInput(infix);
        }
        t = 0;

        infixtopostfix(infix, postfix, s);
        printf("\nPostfix: ");
        puts(postfix);

        printf("\nResult: %.2f", postfixEval(postfix, p));

        printf("\n\nContinue operation? (1/0): ");
        scanf("%d", &run);

        fflush(stdin);
        freeStack(s);
        freeStack(p);
        CLEAR;
    }
    return 0;
}