#include <stdio.h>
#include <stdlib.h>

void carre(int *nbA, int *nbB, int *nbC, int *nbD)
{
    (*nbA) = (*nbA) * (*nbA);
    (*nbB) = (*nbB) * (*nbB);
    (*nbC) = (*nbC) * (*nbC);
    (*nbD) = (*nbD) * (*nbD);
}

int main()
{
    int nbA = 1, nbB = 2, nbC = 3, nbD = 4;

    printf("%2d - %2d - %2d - %2d\n", nbA, nbB, nbC, nbD);

    carre(&nbA, &nbB, &nbC, &nbD);

    printf("%2d - %2d - %2d - %2d", nbA, nbB, nbC, nbD);

    return 0;
}