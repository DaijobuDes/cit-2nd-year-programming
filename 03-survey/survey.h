#pragma once

#if defined(__linux__) || defined(__APPLE__)
#define CLEAR system("clear")
#define PAUSE system("read")
#else
/* else windows */
#define CLEAR system("cls")
#define PAUSE system("pause")
#endif

typedef int* Statistician;

void add(Statistician answer, int* count, int* SIZE, int item);
/***
 * Doubles the size of answer when it is full
 * Data should be sorted after every insertion
***/

float mean(Statistician answer, int count); 
float median(Statistician answer, int count);

int max(Statistician answer, int count);
int min(Statistician answer, int count);
int range(Statistician answer, int count);

void mode(int freq[], int* freqsize, Statistician answer, int count);
/***
 * Determines the mode by counting the number of responses of each type, then
 * selecting the value with the greatest count. 
***/

void histogram(Statistician answer, int count);
/***
 * Produces a histogram to aid in determining the mode graphically. Use asterisks to
 * represents number of occurrences.
***/

int input();
void menu();
void promptToContinue();

