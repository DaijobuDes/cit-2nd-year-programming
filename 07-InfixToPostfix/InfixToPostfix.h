#pragma once

#define SIZE 100
#include "stack.h"

int validInput(char infix[]);
void infixtopostfix(char infix[], char postfix[], Stack s);
int isDigit(stackItem item);
int precedence(char c);
float postfixEval(char postfix[], Stack s);
float evaluate(stackItem s1, stackItem s2, float f);
