#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

int main()
{
	Stack s = newStack();
	stackItem chars[SIZE];

	int status = 0, validity = 0;
	int ask = 1; 
	
	while (ask)
	{
		while (validity != 1)
		{
			printf("Enter symbols, accepted \'(){}[]\': ");
			fgets(chars, SIZE, stdin);
			validity = isValidInput(chars);
		}
		validity = 0;
		status = isValid(s, chars);

		if (status)
			printf("\nMatch found.");
		else
			printf("\nNo match or mismatch found.");

		printDisplay(s, status);
		
		printf("\n\nEnter again? (1/0): ");
		scanf("%d", &ask);
		
		fflush(stdin);
		freeStack(s);

		CLEAR;
	}
	
	return 0;
}
