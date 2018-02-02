#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5;
    int *ptr = &a;

    printf("%d\n", *ptr); // On affiche le pointeur de l'adresse donc la valeur
    printf("%p\n", ptr);  // On affiche l'adresse stockée dans ptr
    printf("%p\n", &a);   // On affiche l'adresse directement depuis &a

    (*ptr)++;             // On fait incrémenter la valeur à la destination du pointeur de l'adresse (à a mdr)
    printf("%d\n", *ptr); // On affiche la valeur (qui a changer)
    printf("%p\n", ptr);
    printf("%p\n", &a);

    *ptr++; // On va à l'adresse suivante

    printf("%d\n", *ptr); // On affiche la valeur contenue dans la nouvelle adresse
    printf("%p\n", ptr);  // On affiche la nouvelle adresse
    printf("%p\n", &a);   // Ancienne adresse

    return 0;
}