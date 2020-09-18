#include <stdio.h>
#include <stdlib.h>

#include "setlist.h"

int main(int argc, char const *argv[])
{
    Set s1 = initialize();
    Set s2 = initialize();
    Set result = initialize();

    const char menuSet[] = "\n1. Set A\n2. Set B: ";
    const char inputSet[] = "\nEnter set: ";
    const char inputElement[] = "\nEnter an element: ";


    int choice, elem, ans, flags;
    while (1)
    {
        CLEAR;
        menu();

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf(menuSet);
            printf(inputSet);
            scanf("%d", &ans);
            printf(inputElement);
            scanf("%d", &elem);

            if (ans == 1)
                s1 = add(s1, elem);
            else if (ans == 2)
                s2 = add(s2, elem);
            else
                printf("\nError: Please enter 1 or 2.");
            break;
        case 2:
            printf(menuSet);
            printf(inputSet);
            scanf("%d", &ans);
            if (ans == 1)
            {
                printf("Set A: ");
                display(s1);
            }
            else if (ans == 2)
            {
                printf("Set B: ");
                display(s2);
            }
            else
                printf("\nError: Please enter 1 or 2.");
            break;
        case 3:
            printf(inputSet);
            scanf("%d", &ans);
            printf(inputElement);
            scanf("%d", &elem);
            if (ans == 1)
                flags = contains(s1, elem);
            else if (ans == 2)
                flags = contains(s2, elem);
            else
                printf("\nError: Please enter 1 or 2.");

            if (flags)
                printf("\nFound on the set.");
            else
                printf("\nNot found on the set.");
            break;
        case 4:
            result = getUnion(result, s1, s2);
            printf("\nSet: ");
            while (result != NULL)
            {
                printf("%d ", result->data);
                result = result->next;
            }
            break;
        case 5:
            result = intersection(result, s1, s2);
            printf("\nSet: ");
            while (result != NULL)
            {
                printf("%d ", result->data);
                result = result->next;
            }
            break;
        case 6:
            result = difference(result, s1, s2);
            printf("\nSet: ");
            while (result != NULL)
            {
                printf("%d ", result->data);
                result = result->next;
            }
            break;
        case 7:
            result = symmetricdifference(result, s1, s2);
            printf("\nSet: ");
            while (result != NULL)
            {
                printf("%d ", result->data);
                result = result->next;
            }
            break;
        case 8:
            flags = subset(s1, s2);
            if (flags)
                printf("\nA subset.");
            else
                printf("\nNot a subset.");
            break;
        case 9:
            flags = disjoint(s1, s2);
            if (flags)
                printf("\nA disjointed set.");
            else
                printf("\nNot a disjointed set.");
            break;
        case 10:
            flags = equal(s1, s2);
            if (flags)
                printf("\nSet is equal.");
            else
                printf("\nSet is not equal");
            break;
        case 0:
            return 0;
            break;
        default:
            printf("\n\nIncorrect choice made.");
            break;
        }
        printf("\n");
        PAUSE;
        fflush(stdin);
    }
    return 0;
}
