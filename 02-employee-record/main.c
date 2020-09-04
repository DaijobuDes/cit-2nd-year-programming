#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "employee.h"

int main()
{
	char choice;
	int size;

    while (1)
	{
		printf("Input number of employees: ");
		scanf("%d", &size);
		payrecord payroll[size];

		CLEAR;
		readRecords(payroll, size);

		CLEAR;
		printRecords(payroll, size);

		printf("Again? (y/n): ");
		scanf("%s", &choice);
		if (choice == 'n')
			return 0;
	}
    return 0;
}


