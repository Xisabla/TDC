#include "lieu.h"

Lieu *promptLieu()
{
    char name[100];
    Lieu *place = (Lieu *)malloc(sizeof(Lieu));

    printf("Nom du lieu: ");
    scanf("%s", name);
    place->name = strdup(name);

    printf("Latitude: ");
    scanf("%lf", &(place->latitude));

    printf("Longitude: ");
    scanf("%lf", &(place->longitude));

    return place;
}