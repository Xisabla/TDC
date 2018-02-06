#include <stdlib.h>
#include <stdio.h>

int min(int *tab)
{
    int i = 0;
    int min = 2147483647;

    while (*(tab + i) != -1)
    {
        if (min > *(tab + i))
        {
            min = *(tab + i);
        }
        i++;
    }

    return min;
}

int main()
{
    int tab[5] = {8, 7, 5, 98, -1};

    printf("%d", min(tab));

    return 0;
}