#include <stdlib.h>
#include <stdio.h>

typedef struct date_
{
    int jour;
    int mois;
    int annee;
} date;

int bissex(int annee)
{
    if ((annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0)
    {
        return 366;
    }
    else
    {
        return 365;
    }
}

int nbMois(int mois)
{
    if ((mois <= 7 && mois % 2 == 1) || mois >= 8 && mois % 2 == 0)
    {
        return 31;
    }
    if (mois == 2)
    {
        return 28;
    }
    return 30;
}

int nbJours(date dateA, date dateB)
{
    int compteur = 0;

    if (dateA.annee > dateB.annee || (dateA.annee == dateB.annee && dateA.mois > dateB.mois) || (dateA.annee == dateB.annee && dateA.mois == dateB.mois && dateA.jour > dateB.jour))
    {
        date temp;
        temp = dateA;
        dateA = dateB;
        dateB = temp;
    }

    for (int i = dateA.annee + 1; i < dateB.annee; i++)
    {
        compteur += bissex(i);
    }

    for (int j = dateA.mois; j < 12; j++)
    {
        compteur += nbMois(j);
        if (j == 12)
        {
            j = 1;
        }
        if (j == dateB.mois)
        {
            break;
        }
    }

    if (dateB.jour > dateA.jour)
    {
        compteur += dateB.jour - dateA.jour;
    }
    else
    {
        compteur += dateA.jour - dateB.jour;
    }
    return compteur;
}

int main()
{
    date dateA;
    dateA.jour = 2;
    dateA.mois = 2;
    dateA.annee = 1943; // Stalingrad

    date dateB;
    dateB.jour = 25;
    dateB.mois = 1;
    dateB.annee = 2018;

    printf("%d", nbJours(dateA, dateB));

    return 0;
}