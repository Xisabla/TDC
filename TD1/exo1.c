#include <stdio.h>
#include <stdlib.h>

typedef struct Etudiant_
{
    char *Nom;
    char *Promotion;
    float Notes[10];
} Etudiant;

float moyenneEleve(Etudiant eleve)
{
    float s = 0;

    for (int i = 0; i < 10; i++)
    {
        s += eleve.Notes[i];
    }

    return s / 10;
}

float moyenneClasse(Etudiant classe[30])
{
    float s = 0;
    int i = 0;

    // Ne fonctionne pas :)

    /*while ((void)classe[i] != NULL)
    {
        s += moyenneEleve(classe[i]);
        i++;
    }*/

    return s / i;
}

void afficherNotes(Etudiant eleve)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%1.f ", eleve.Notes[i]);
    }
}

int main()
{
    srand(time(NULL));

    Etudiant jacqueline1;
    for (int i = 0; i < 10; i++)
    {
        jacqueline1.Notes[i] = rand() % 20;
    }

    Etudiant jacqueline2;
    for (int i = 0; i < 10; i++)
    {
        jacqueline2.Notes[i] = rand() % 20;
    }

    Etudiant jacqueline3;
    for (int i = 0; i < 10; i++)
    {
        jacqueline3.Notes[i] = rand() % 20;
    }

    Etudiant jacqueline4;
    for (int i = 0; i < 10; i++)
    {
        jacqueline4.Notes[i] = rand() % 20;
    }

    Etudiant jacqueline5;
    for (int i = 0; i < 10; i++)
    {
        jacqueline5.Notes[i] = rand() % 20;
    }

    Etudiant classe[30] = {jacqueline1, jacqueline2, jacqueline3, jacqueline4, jacqueline5};

    afficherNotes(jacqueline1);
    printf("\n%.01f", moyenneEleve(jacqueline1));
    printf("\n%.01f", moyenneClasse(classe));
}