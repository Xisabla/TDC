#include "trajet.h"

void importTrajet(Liste *l, char *filename)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Erreur de lecture de fichier");
    }
    else
    {
        while (getline(&line, &len, fp) != -1)
        {
            *(line + strlen(line) - 1) = '\0';

            Lieu *place = (Lieu *)malloc(sizeof(Lieu));

            place->name = strtok(line, ",");
            place->latitude = (double)atof(strtok(NULL, ","));
            place->longitude = (double)atof(strtok(NULL, ","));

            addElement(l, place);
        }
    }

    fclose(fp);
}

void promptTrajet(Liste *l)
{
    addElement(l, promptLieu());
    printf("\n");
}

double distance(Liste *l)
{
    Element *next;
    double dTotal;
    double d;

    if (l == NULL || l->size < 2)
    {
        return 0;
    }
    Element *current = l->head;
    while (current->next != NULL)
    {
        next = current->next;
        double xA = current->place->latitude;
        double yA = current->place->longitude;
        double xB = next->place->latitude;
        double yB = next->place->longitude;

        d = sqrt((current->place->latitude - next->place->latitude) * (current->place->latitude - next->place->latitude) + (current->place->latitude - next->place->longitude) * (current->place->latitude - next->place->longitude));
        dTotal += d;

        current = current->next;
    }

    return dTotal;
}