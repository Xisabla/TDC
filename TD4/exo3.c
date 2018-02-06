#include <stdlib.h>
#include <stdio.h>

void inverser(int *nbA, int *nbB)
{
    *nbA = *nbA + *nbB; // a' = a + b
    *nbB = *nbA - *nbB; // b' = a = a + b - b = a' - b
    *nbA = *nbA - *nbB; // b = a + b - a = a' - b'
}

int main()
{
    int a = 1;
    int b = 2;

    printf("a = %d, b = %d\n", a, b);

    inverser(&a, &b);

    printf("a = %d, b = %d", a, b);

    return 0;
}