#include <stdio.h>
#include <stdlib.h>

void swap(char *table, int posA, int posB)
{
    char temp = *(table + posA);
    *(table + posA) = *(table + posB);
    *(table + posB) = temp;
}

void alphabetique(char *chaine)
{
    int n = 0;

    while (*(chaine + n) != '\0')
    {
        n++;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (*(chaine + i) > *(chaine + i + 1))
            {
                swap(chaine, i, i + 1);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    char mot[20] = "saluttoutlemonde";

    alphabetique(&mot);

    printf("%s", mot);

    return 0;
}