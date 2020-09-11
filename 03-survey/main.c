#include <stdio.h>
#include <stdlib.h>

#include "survey.h"

int main()
{
    int i, SIZE = 10, freqsize = 0;
    int *freq = (int*)calloc(freqsize, sizeof(int));
    int item, count = 0, choice;

    Statistician answer = (Statistician)malloc(sizeof(int) * SIZE);

    while (1)
    {
        CLEAR;
        menu();
        scanf("%d", &choice);
        printf("\nSize of array: %d\n\n", count);

        switch (choice)
        {
        case 1:
            item = input();
            add(answer, &count, &SIZE, item);
            break;
        case 2:
            printf("\nMean: %.4f", mean(answer, count));
            break;
        case 3:
            printf("\nMedian: %.4f", median(answer, count));
            break;
        case 4:
            freqsize = 0;
            printf("\nMode: ");
            mode(freq, &freqsize, answer, count);
            for (i = 0; i < freqsize; i++)
                printf(" %d", freq[i]);
            break;
        case 5:
            printf("\nMax: %d", max(answer, count));
            break;
        case 6:
            printf("\nMin: %d", min(answer, count));
            break;
        case 7:
            printf("\nRange: %d", range(answer, count));
            break;
        case 8:
            histogram(answer, count);
            break;
        case 9:
            CLEAR;
            free(answer);
            printf("\nProgram exited.");
            return 0;
        default:
            break;
        }
        printf("\n");
        promptToContinue();
        PAUSE;
    }
    return 0;
}
