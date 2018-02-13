#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void swap(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void triABulle(double *notes, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (*(notes + j) > *(notes + j + 1))
            {
                swap((notes + j), (notes + j + 1));
            }
        }
    }
}

double moyenne(double *notes, int n)
{
    double s = 0;

    for (int i = 0; i < n; i++)
    {
        s += *(notes + i);
    }

    return s / n;
}

double mediane(double *notes, int n)
{
    if (n % 2 == 1)
    {
        return *(notes + n / 2);
    }

    return (*(notes + n / 2) + *(notes + n / 2 - 1)) / 2;
}

double ecartType(double *notes, int n)
{
    double s = 0;
    double moy = moyenne(notes, n);

    for (int i = 0; i < n; i++)
    {
        s += pow(*(notes + i) - moy, 2);
    }

    return sqrt(s / (double)n);
}

int main()
{
    srand(time(NULL));

    int n;

    printf("Saisir le nomdre de notes: ");
    scanf("%d", &n);

    // Malloc

    double *notes;
    notes = (double *)malloc(n * sizeof(double));

    if (notes == NULL)
    {
        printf("Memoire insuffisante");
        return -1;
    }

    // Init notes (random)

    for (int i = 0; i < n; i++)
    {
        *(notes + i) = ((double)rand() / (double)(RAND_MAX)) * 20;
    }

    // Tri notes

    triABulle(notes, n);

    // Affichage notes

    for (int i = 0; i < n; i++)
    {
        printf("Note n %2d: %2.2f\n", i + 1, *(notes + i));
    }

    printf("\nMoyenne: %2.2f\n", moyenne(notes, n));
    printf("Mediane: %2.2f\n", mediane(notes, n));
    printf("Ecart-type: %2.2f\n", ecartType(notes, n));

    // On libére la mémoire

    free(notes);

    return 0;
}