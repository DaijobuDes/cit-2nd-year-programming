#include <stdio.h>

#include "airline.h"
// #include "log.h"

#define SIZE 10

void initSeats(int seats[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        seats[i] = 0;
        // log_debug("Value of seats[%d] = 0", i);
    }
    
    return;
}

void displaySeats(int seats[], int size)
{
	int i;
	printf("\n");
	printf("First Class Section\t:");
	for(i = 0; i < size / 2; i++)
	{
			printf(" [%d] ", seats[i]);
			printf("\b");
	}
	printf("\n");
    i = size/2;
    printf("Economy Section\t\t:");
	for(i; i < size; i++)
	{
			printf(" [%d] ", seats[i]);
            printf("\b");
	}
	printf("\n");
	return;
}

int assignSeat(int st[], int size, int seatType)
{
    int seat;
    char choice;
    char fc[] = "First Class", ec[] = "Economy Class";
    if (seatType == 1)
        seat = assignFirstClass(st, size/2);
    else
        seat = assignEconomy(st, size);
    
    if (seat == -1)
    {
        if (seatType == 1)
            printf("The %s is full, would you like to transfer to %s? (y/n): ", fc, ec);
        else
            printf("The %s is full, would you like to transfer to %s? (y/n): ", ec, fc);
        choice = getche();
        if (choice == 'y')
            seatType == 1 ? (seat = assignEconomy(st, size)) : (seat = assignFirstClass(st, size/2));
        else
            return -1;
    }
    return seat;
}

int assignFirstClass(int seats[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (!seats[i])
        {
            seats[i] = 1;
            return i + 1;
        }
    }
    return -1;
}

int assignEconomy(int seats[], int size)
{
    int i;
    for (i = 5; i < size; i++)
    {
        if (!seats[i])
        {
            seats[i] = 1;
            return i + 1;
        }
    }
    return -1;
}

void boardPass(int seat)
{
    int i;
    char border[] = "=============================";
    if (seat <= 5)
    {
        printf(border);
        printf("\nFirst Class Section\n");
        printf("Seat #%d\n", seat);
        printf(border);
    }
    else if (seat <= 10)
    {
        printf(border);
        printf("\nEconomy Section\n");
        printf("Seat #%d\n", seat);
        printf(border);
    }
    return;
}

void Exit(void)
{
    system("exit");
    return;
}
