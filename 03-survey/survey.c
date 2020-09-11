#include <stdio.h>
#include <stdlib.h>

#include "survey.h"

int input()
{
	int item;
	while (1)
    {
		printf("Input num (1-9): ");
		scanf("%d", &item);
		if(item >= 1 && item <= 9)
			return item;
	}
    return item;
}


void add(Statistician answer, int* count, int* SIZE, int item)
/***
 * Doubles the size of answer when it is full
 * Data should be sorted after every insertion
***/
{
    int i, j, temp;

    if (*count == *SIZE)
    {
        *SIZE = (*SIZE) * 2;
        answer = realloc(answer, (*SIZE) * sizeof(int));
    }

    answer[(*count)++] = item;
    for (i = 0; i < *count; i++)
    {
        for (j = i; j > 0; j--)
        {
            if (answer[j-1] > answer[j])
            {
                temp = answer[j-1];
                answer[j-1] = answer[j];
                answer[j] = temp;
            }
        }
    }
    return;
}

float mean(Statistician answer, int count)
{
    int i;
    float avg = 0;
    for (i = 0; i < count; i++)
        avg += answer[i];
    return (float)avg / count;
}

float median(Statistician answer, int count)
{
    int mid = count / 2;
    if (count % 2 != 0)
        return answer[mid];
    else
        return ((answer[mid] + answer[mid+1]) / 2);
}

int max(Statistician answer, int count)
{
    int a, i;
    a = answer[0];
    for (i = 1; i < count; i++)
        a = (answer[i] > a) * answer[i] + !(answer[i] > a) * a;
    return a;
}

int min(Statistician answer, int count)
{
    int a, i;
    a = answer[0];
    for (i = 1; i < count; i++)
        a = (answer[i] < a) * answer[i] + !(answer[i] < a) * a;
    return a;
}

int range(Statistician answer, int count)
{
    return ((answer[count-1]) - (answer[0]));
}

void mode(int freq[], int* freqsize, Statistician answer, int count)
/***
 * Determines the mode by counting the number of responses of each type, then
 * selecting the value with the greatest count. 
***/
{
    int i, item = 0, max = 0, check = 0;
    int arr[9] = {0};

    for (i = 0; i < count; i++)
    {
        item = answer[i];
        arr[item-1]++;
    }

    for (i = 0; i < 9; i++)
    {
        if (max <= arr[i])
            max = arr[i];
    }
    
    for (i = 0; i < 9; i++)
    {
        if (arr[i] == 0)
            continue;
        if (arr[i] != max)
        {
            check = 1;
            break;
        }
        check = 0;
    }
    
    if (check == 0)
        printf("None");
    else
    {
        for (i = 0; i < 9; i++)
        {
            if (arr[i] == max)
            {
                freq[*freqsize] = i + 1;
                (*freqsize)++;
                freq = (int*)realloc(freq, (*freqsize) * sizeof(int));
            }
        }
    }
    return;
}

void histogram(Statistician answer, int count)
/***
 * Produces a histogram to aid in determining the mode graphically. Use asterisks to
 * represents number of occurrences.
***/
{
    printf("\n\nPrinting Histogram\n\n");
    int i, j, k = count, l = 0, m = 0;

    for (i = 9; i >= 1; i--)
    {
        printf("[%d]", i);
        l = 0;
        for (j = k; j >= 0; j--)
        {
            if (answer[j] == i)
            {
                printf(" *");
                l++; k++;
            }
        }
        if (m <= 1)
            m = 1;
        printf("\n");
    }
    printf("  ");
    for (i = 1; i <= m; i++)
        printf(" %d", i);

    return;
}

void menu()
{
    char menu[] =
    "Statistics\n"
    "1. Insert or add element\n"
    "2. Mean\n"
    "3. Median\n"
    "4. Mode\n"
    "5. Max\n"
    "6. Min\n"
    "7. Range\n"
    "8. Histogram\n"
    "9. Exit\n"
    "\n"
    "Enter choice: ";
    printf(menu);
    return;
}

void promptToContinue()
{
    fflush(stdin);
    return;
}
