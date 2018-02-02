#include <stdio.h>
#include <stdlib.h>

void afficher(char *chaine)
{
    int i = 0;
    while (*(chaine + i) != '\0')
    {
        if (*(chaine + i) != ' ')
        {
            printf("%c", *(chaine + i));
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    afficher(argv[1]);

    return 0;
}