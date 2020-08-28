#pragma once

#ifdef __linux__
#include <stdlib.h>
#elif _WIN32
#include <windows.h>
#else
NULL
#endif

void initSeats(int seats[], int size);
void displaySeats(int seats[], int size);
void boardPass(int seat);
void Exit(void);

int assignSeat(int st[], int size, int seatType);
int assignFirstClass(int seats[], int size);
int assignEconomy(int seats[], int size);

/* LOGGERS */
/*
FILE *file;

#define APPEND fopen("log.txt", "a+")
#define READ fopen("log.txt", "r+")
#define WRITE fopen("log.txt", "w+")

#define CLOSE fclose(file)
#define NEXTL fprintf(file, "\n")

#ifdef __linux__
#define PAUSE system("read")
#elif _WIN32
#define PAUSE system("pause")
#endif
*/
