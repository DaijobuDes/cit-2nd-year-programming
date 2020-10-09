#include <stdio.h>
#include <stdlib.h>

#include "InfixToPostfix.h"

int validInput(char infix[])
{
	int ans = 0;
	for (int i = 0; infix[i] != '\n'; i++)
	{
		if (isDigit(infix[i]) != 0 || precedence(infix[i]) != 0)
			ans = 1;
		else
		{
			ans = 0;
			break;
		}
	}
	return ans;
}

void infixtopostfix(char infix[], char postfix[], Stack s)
{
	int j = 0;
	char c;
	for (int i = 0; infix[i] != '\n'; i++)
	{
		c = infix[i];
		if (isDigit(c) != 0)
			postfix[j++] = c;
		else if (precedence(c) != 0)
		{
			while (isEmpty(s) != 1 && precedence(c) <= precedence(stackTop(s)))
				postfix[j++] = pop(s);
			push(s, c);
		}
	}

	while (!isEmpty(s))
		postfix[j++] = pop(s);
	postfix[j] = '\0';
}

int isDigit(stackItem item)
{
	return (int)item >= 48 && (int)item <= 57;
}

int precedence(char c)
{
	int ans = 0;
	if (c == '*' || c == '/' || c == '%')
		ans = 2;
	else if (c == '+' || c == '-')
		ans = 1;
	return ans;
}

float postfixEval(char postfix[], Stack s)
{
	float ans = 0, f1, f2;
	char c;
	for (int i = 0; postfix[i] != '\0'; i++)
	{
		c = postfix[i];
		if (isDigit(c))
			push(s, c - '0');
		else
		{
			f1 = pop(s);
			f2 = pop(s);
			ans = evaluate(f1, f2, c);
			push(s, ans);
		}
	}
	return pop(s);
}

float evaluate(stackItem s1, stackItem s2, float f)
{
	float ans = 0;
	if (f == '*')
		ans = s2 * s1;
	else if (f == '+')
		ans = s2 + s1;
	else if (f == '-')
		ans = s2 - s1;
	else if (f == '/')
		ans = s2 - (float)s1;
	else if (f == '%')
		ans = (int)s2 % (int)s1;
	return ans;
}






