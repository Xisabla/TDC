#include <stdlib.h>
#include <stdio.h>

void cesar(char *chaine, char key)
{
    int i = 0;

    while (*(chaine + i) != '\0')
    {
        char nb = *(chaine + i);
        char nb_encoded = nb + key;
        nb_encoded = nb_encoded % 256; // ASCII encodé sur 256 bits
        printf("%c", nb_encoded);
        i++;
    }
}

int main()
{
    char mot[20] = "HELLO WORLD";

    cesar(mot, 2);

    return 0;
}