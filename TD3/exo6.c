#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5;
    int b = 10;

    int *ptrX = &a; // pointeur x -> a
    int *ptrY = &b; // pointeur y -> b

    b++; // b = b + 1 = 11 | En mode normal
    a++; // a = a + 1 = 6  | En mode normal

    *ptrX = a + b;     // a = a + b = 17 | En mode pointeur et normal
    *ptrY = b + *ptrX; // b = b + a = 28 | En mode pointeur et normal et pointeur

    (*ptrY)++; // b = b + 1 = 29 | En mode pointeur
    (*ptrX)++; // a = a + 1 = 18 | En mode pointeur

    printf("%d\n", *ptrX); // affiche a
    printf("%d\n", *ptrY); // affiche b

    /*** V2 ***/
    /*
    int a = 5;
    int b = 10;

    int *ptrX = &a; // pointeur x -> a
    int *ptrY = &b; // pointeur y -> b

    b++; // b = b + 1 = 11 | En mode normal
    a++; // a = a + 1 = 6  | En mode normal

    *ptrX = a + b;     // a = a + b = 17 | En mode pointeur et normal
    *ptrY = b + *ptrX; // b = b + a = 28 | En mode pointeur et normal et pointeur

    ptrX = ptrY; // ptrX pointe desormais vers b
    (*ptrX)++;   // b = b + 1 = 29 | En mode pointeur

    printf("%d\n", *ptrX); // affiche b | En mode pointeur
    printf("%d\n", *ptrY); // affiche b | En mode pointeur
    */
}