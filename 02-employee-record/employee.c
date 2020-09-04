#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "employee.h"

void readName(payrecord payroll[], int i)
/*** reads a single name ***/
{
    printf("Enter first, middle and last name: ");
    scanf("%s %s %s", &payroll[i].name.first, &payroll[i].name.middle, &payroll[i].name.last);
    return;
}

void printName(payrecord payroll[], int i)
/*** prints a single name ***/
{
    printf("\nName: %s %s %s", payroll[i].name.first, payroll[i].name.middle, payroll[i].name.last);
    return;
}

void printSummary(double gross, double tax)
/*** prints total tax gross pay and total tax withheld ***/
{
	printf("\nTotal gross pay: %.2f", gross);
	printf("\nTotal tax pay: %.2f\n", tax);
	return;
}

void readRecords(payrecord payroll[], int n)
/*** read payroll input data records until n records have been read ***/
{
	int i;
	for (i = 0; i < n; i++)
	{
		payroll[i].tax_withheld = 0;
		printf("\n+++++++++++++++++ Recording input +++++++++++++++++");
		printf("\nID: %d\n", i + 1);
		
		payroll[i].id = i + 1;
		readName(payroll, i);

		printf("Input number of hours this week: ");
		scanf("%f", &payroll[i].hours);
		printf("Enter hourly rate: ");
		scanf("%f", &payroll[i].rate);

		if (payroll[i].hours > 40)
		{
			payroll[i].regular = 40;
			payroll[i].overtime = payroll[i].hours - 40;
		}
		else
		{
			payroll[i].overtime = 0;
			payroll[i].regular = payroll[i].hours;
		}

		payroll[i].gross = calcRecords(payroll, i, &payroll[i].tax_withheld);
		payroll[i].net = payroll[i].gross - payroll[i].tax_withheld;

		printf("\n+++++++++++++++++ Finished +++++++++++++++++\n");
		PAUSE;
	}
	return;
}

void printRecords(payrecord payroll[], int n)
/*** prints n payroll records ***/
{
    int i;
    for (i = 0; i < n; i++)
    {
		printf("\n+++++++++++++++++ Displaying Record +++++++++++++++++");
        printf("\nID: %d", payroll[i].id);
		printName(payroll, i);
		printf("\nTotal Hours: %.2f", payroll[i].hours);
		printf("\nRegular Payment: %.2f", payroll[i].regular);
		printf("\nOvertime Payment: %.2f", payroll[i].overtime);
		printf("\nHourly Rate: %.2f", payroll[i].rate);
		printf("\nOvertime Rate: %.2f", payroll[i].rate * 1.5);
		printf("\nNet pay: %.2f ", payroll[i].net);
		printSummary(payroll[i].gross, payroll[i].tax_withheld);
		printf("\n+++++++++++++++++ End of Record +++++++++++++++++\n");
		PAUSE;
    }
	return;
}

double calcRecords(payrecord payroll[], int n, double *taxptr)
/***
 * computes regular and overtime pay, and the tax to be withheld
 * also cumulatively sums total gross pay and total tax withheld
 * passes the address of tax initialized to 0 and returns the gross
***/
{
	double gross, temp;
	gross = payroll[n].regular * payroll[n].rate + payroll[n].overtime * payroll[n].rate * 1.5;

	if (gross < 500)
		temp = gross * 0.15;
	else if (gross < 1000)
		temp = gross * 0.28;
	else
		temp = gross * 0.33;

	*taxptr = temp;

	return gross;
}

