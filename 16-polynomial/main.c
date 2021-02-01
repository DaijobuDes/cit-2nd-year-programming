// GCC paramters
// -Wall

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

typedef int *Polynomial;

// functions

Polynomial newPoly();            // allocate return the pointer
void destroyPoly(Polynomial *p); // set to NULL after freeing
void addTerm(Polynomial p, int coef, int exp);
void display(const Polynomial p);

// return a new polynomial that represents the sum of p1 and p2
Polynomial add(const Polynomial p1, const Polynomial p2);

// return a new polynomial that represents the difference of p1 and p2
Polynomial subtract(const Polynomial p1, const Polynomial p2);

// return a new polynomial that represents the derivative of p1
Polynomial derivative(const Polynomial p);

// compute the value of the polynomial given a value for x
int evaluate(const Polynomial p, int x);

// return 1 if the value of p is constant, 0 otherwise
int isConstant(const Polynomial p);

// return 1 if the value of p is zero (0), 0 otherwise
int isZero(const Polynomial p);

// return 1 if there is coefficient for all exponents, 0 otherwise
int isComplete(const Polynomial p);

int main()
{
    int i;
    Polynomial p1 = newPoly(); 
    
    printf("p1 Constant? %s\n", isConstant(p1) ? "Yes" : "No");
    printf("p1 Complete Polynomial? %s\n", isComplete(p1) ? "Yes" : "No");

    display(p1);

    addTerm(p1, 5, 1);
    printf("p1 Constant? %s\n", isConstant(p1) ? "Yes" : "No");
    printf("p1 Complete Polynomial? %s\n", isComplete(p1) ? "Yes" : "No");
    display(p1);

    Polynomial p2 = newPoly();
    addTerm(p2, -6, 4);
    Polynomial p3 = newPoly();
    p3 = add(p1, p2);
    display(p3);

    destroyPoly(&p3);
    p3 = newPoly();

    p3 = subtract(p1, p2);
    display(p3);

    destroyPoly(&p1);
    destroyPoly(&p2);

    display(p1);
    display(p2);

    addTerm(p3, 6, 5);
    printf("Derivative of : ");
    display(p3);
    Polynomial dx = derivative(p3);
    printf("Derivative is = ");
    display(dx);
    
    Polynomial p4 = newPoly();
    addTerm(p4, 6, 4);
    addTerm(p4, 3, 7);
    addTerm(p4, 2, 5);
    printf("Evaluation of with value 5: ");
    display(p4);
    printf("Value: %d\n", evaluate(p4, 5));

    for(i = 0; i <= MAX; i++)
        p4[i] = 1;
    printf("isComplete? %s", isComplete(p4) ? "Yes" : "No");
    return 0;
}

Polynomial newPoly()
{
    Polynomial poly;
    int i;
    poly = (Polynomial)malloc(sizeof(int) * MAX+1);
    for (i = 0; i <= MAX+1; i++)
    {
        poly[i] = 0;
    }
    return poly;
}

void destroyPoly(Polynomial *p)
{
    free(p);
    p = NULL;
}

void addTerm(Polynomial p, int coef, int exp) // Coefficient and Exponent
{
    p[MAX-exp] += coef;
    return;
}

void display(const Polynomial p) 
{
    int i;

    if(isZero(p)) { printf("Polynomial is Empty\n"); }

    for(i = MAX - 1; i > 1; i--)
    {
        if (p[i] != 0)
        {
            printf("%d", p[i]);
            if (i == MAX - 1)
                printf("x");
            else
                if (i == MAX)
                    printf(" ");
                else
                    printf("x^");
            
            if (i == MAX - 1 || i == MAX)
                printf("+");
            else
                printf("%c", MAX - i + '0');
        
            if (i == 0)
                printf("10");
            else
                printf("");

            if (p[i-1] > 0)
                printf("+");
            else
                printf(" ");
        }
    }
    printf("\n");
    return;
}

Polynomial add(const Polynomial p1, const Polynomial p2)
{
    Polynomial poly = newPoly();
    int i;
    for (i = 0; i <= MAX; i++)
    {
        poly[i] = p1[i] + p2[i];
    }
    return poly;
}

Polynomial subtract(const Polynomial p1, const Polynomial p2)
{
    Polynomial poly = newPoly();
    int i;
    for (i = 0; i < MAX; i++)
    {
        poly[i] = p1[i] - p2[i];
    }
    return poly;
}

Polynomial derivative(const Polynomial p)
{
    Polynomial poly_derivative = newPoly();
    int i;
    for (i = MAX; i > 0; i--)
    {
        poly_derivative[i+1] = p[i] * (MAX - i);
    }
    return poly_derivative;
}

int evaluate(const Polynomial p, int x)
{
    int total = 0, i;
    for (i = 0; i < MAX; i++)
    {
        total += p[i] * (int)pow(x, (MAX - i));
    }
    return total;
}

int isConstant(const Polynomial p)
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        if (p[i] != 0) { return 0; }
    }
    return 1;
}

int isZero(const Polynomial p)
{
    int i;
    for(i = 0; i <= MAX; i++)
    {
        if (p[i] != 0) { return 0; }
    }
    return 1;
}

int isComplete(const Polynomial p)
{
    int i;
    for (i = 0; i <= MAX; i++)
    {
        if (p[i] == 0) { return 0; }
    }
    return 1;
}
