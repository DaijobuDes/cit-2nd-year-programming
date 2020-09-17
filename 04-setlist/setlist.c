#include <stdio.h>
#include <stdlib.h>

#include "setlist.h"

Set initialize()
{
    Set head = NULL;
    return head;
}

nodeptr create(int elem)
{
    nodeptr ptr = (nodeptr)malloc(sizeof(Node));
    ptr->data = elem;
    ptr->next = NULL;
    return ptr;
}


void display(Set s)
{
    nodeptr ptr = s;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return;
}

int contains(Set s, int elem)
{
    nodeptr ptr = s;
    while (ptr != NULL)
    {
        if (ptr->data == elem)
            return 1;
        ptr = ptr->next;
    }
    return 0;
}

Set add(Set s, int elem)
{
    nodeptr t;
    if (contains(s, elem) == 0)
    {
        t = create(elem);
        t->next = s;
        s = t;
    }
    return s;
}

Set getUnion(Set result, Set s1, Set s2)
{
    result = initialize();
    nodeptr p1 = s1, p2 = s2;
    while (p1 != NULL)
    {
        result = add(result, p1->data);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        if (contains(result, p2->data) == 0)
            result = add(result, p2->data);
        p2 = p2->next;
    }
    printf("Success");
    return result;
}

Set intersection(Set result, Set s1, Set s2)
{
    result = initialize();
    nodeptr p1 = s1, p2 = s2;
    while (p1 != NULL)
    {
        if (contains(s2, p1->data) == 1)
            result = add(result, p1->data);
        p1 = p1->next;
    }
    printf("Success");
    return result;
}

Set difference(Set result, Set s1, Set s2)
{
    result = initialize();
    nodeptr p1 = s1, p2 = s2;
    while (p1 != NULL)
    {
        if (contains(s2, p1->data) == 0)
            result = add(result, p1->data);
        p1 = p1->next;
    }
    printf("Success");
    return result;
}

Set symmetricdifference(Set result, Set s1, Set s2)
{
    nodeptr p1 = s1, p2 = s2;
    while (p1 != NULL)
    {
        if (contains(s2, p1->data) == 0)
            result = add(result, p1->data);
        p1 = p1->next;
    }

    while (p2 != NULL)
    {
        if (contains(s1, p2->data) == 0)
            result = add(result, p2->data);
        p2 = p2->next;
    }
    printf("Success");
    return result;
}

int subset(Set s1, Set s2)
{
    nodeptr p1 = s1, p2 = s2;
    while (p1 != NULL)
    {
        if (contains(s2, p1->data) == 0)
            return 0;
        p1 = p1->next;
    }
    return 1;
}

int disjoint(Set s1, Set s2)
{
    nodeptr p1 = s1, p2 = s2;
    while (p1 != NULL)
    {
        if (contains(s2, p1->data) == 1)
            return 0;
        p1 = p1->next;
    }
    return 1;
}

int equal(Set s1, Set s2)
{
    if (subset(s1, s2) && subset(s2, s1))
        return 1;
    return 0;
}

void menu()
{
    char* menu = 
    "~~~~~ Set List ~~~~~\n"
    "1. Add\n"
    "2. Display\n"
    "3. Contains\n"
    "4. Union\n"
    "5. Intersection\n"
    "6. Difference\n"
    "7. Symmetric Difference\n"
    "8. Subset\n"
    "9. Disjoint\n"
    "10. Equal\n"
    "0. Exit\n"
    "\n"
    "Enter a number: ";
    printf(menu);
    return;
}


