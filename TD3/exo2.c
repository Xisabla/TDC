#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5;
    int *ptr = &a;        // On met l'adresse de a dans le pointeur ptr
    a++;                  // On incrémente a (a = 6 maintenant)
    printf("%d\n", *ptr); // On affiche la valeur via le pointeur (on affiche a)

    return 0;
}