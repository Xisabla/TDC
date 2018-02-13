#include <stdlib.h>
#include <stdio.h>

int taille(char *mot)
{
    int i = 0;

    while (*(mot + i) != '\0')
    {
        i++;
    }

    return i;
}

int palindrome(char *mot)
{
    int size = taille(mot);

    for (int i = 0; i < size; i++)
    {
        if (*(mot + i) != *(mot + size - i - 1))
        {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char *argv[])
{
    // Les mots sont pris en arguments

    if (argc < 3)
    {
        return 1;
    }

    char *motA = argv[1];
    char *motB = argv[2];

    int size = taille(motA) + taille(motB) + 1;

    char *mot;

    // Maloc & test pour la mémoire

    mot = (char *)malloc((size) * sizeof(char));

    if (mot == NULL)
    {
        printf("\nMemoire insuffisante");
        return -1;
    }

    // Fusion des deux mots dans "mot"

    for (int i = 0; i <= taille(motA); i++)
    {
        *(mot + i) = *(motA + i);
    }
    for (int i = 0; i <= taille(motB); i++)
    {
        *(mot + i + taille(motA)) = *(motB + i);
    }

    // Dernier caractère du mot

    *(mot + size) = '\0';

    printf("%s\n", mot);

    // Test palindrome

    if (palindrome(mot))
    {
        printf("Il s'agit d'un palindrome");
    }
    else
    {
        printf("Il ne s'agit pas d'un palindrome");
    }

    // On libére la mémoire

    free(mot);

    return 0;
}