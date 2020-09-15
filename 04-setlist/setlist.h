#pragma once

typedef struct node* nodeptr;

typedef struct node
{
    int data;
    nodeptr next;
} Node;

typedef Node* Set;

Set initialize();
void display(Set s);
Set add(Set s, int elem);
int contains(Set s, int elem);
void getUnion(Set result, Set s1, Set s2);
void intersection(Set result, Set s1, Set s2);
void difference(Set result, Set s1, Set s2);
void symmetricdifference(Set result, Set s1, Set s2);
int subset(Set s1, Set s2);
int disjoint(Set s1, Set s2);
int equal(Set s1, Set s2);


#if defined(__linux__) || defined(__APPLE__)
#define CLEAR system("clear")
#define PAUSE system("read")
#else
#define CLEAR system("cls")
#define PAUSE system("pause")
#endif
