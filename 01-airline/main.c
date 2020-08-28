#include <stdio.h>
#include <string.h>

#ifdef __linux__ /* For linux systems */
#include <stdlib.h>
#define CLEAR system("clear")
#elif _WIN32 /* For Windows systems */
#include <windows.h>
#define CLEAR system("cls")
#endif

// #include "log.h" /* For console debug output */

#include "airline.h"
#define SIZE 10

int main()
{
    int seatType, seats[SIZE], seat;
    char choice;

    initSeats(seats, SIZE);
    do
    {
        CLEAR;
        printf("Welcome to MGM Airlines!\n");
        displaySeats(seats, SIZE);

        printf("\nType 1 for First Class\nType 2 for Economy Class: ");
        scanf("%d", &seatType);

        seat = assignSeat(seats, SIZE, seatType);

        if (seat == -1)
        {
            CLEAR;
            printf("\nSeats are full.");
            printf("\nNext flight leaves in 3 hours.");
            (void)getche();
            Exit();
        }
        CLEAR;
        boardPass(seat);
        displaySeats(seats, SIZE);

        printf("\n\nDo you want to enter again? (yes/no): ");
        choice = getche();
        if (choice == 'n')
        {
            CLEAR;
            printf("\nNext flight leaves in 3 hours.");
            (void)getche();
        }
    } while (choice != 'n');


    return 0;
}
