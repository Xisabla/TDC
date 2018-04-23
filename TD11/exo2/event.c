#include "event.h"

// --------- List specific functions --------- //

Liste *initListe()
{
    Liste *l = (Liste *)malloc(sizeof(Liste));

    l->head = NULL;
    l->size = 0;

    return l;
}

Element *createElement(Event *e)
{
    Element *Elt = (Element *)malloc(sizeof(Element));

    if (Elt == NULL)
        return NULL;

    Elt->evt = e;
    Elt->next = NULL;

    return Elt;
}

void addElement(Liste *l, Event *evt)
{
    Element *Elt = createElement(evt);

    if (l->size == 0)
    {
        l->head = Elt;
    }
    else
    {
        Element *current = l->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = Elt;
    }

    l->size++;
}

void removeElement(Liste *l, char *searchName)
{
    Element *previous = NULL;
    Element *current = l->head;

    while (current != NULL)
    {
        if (strcmp(current->evt->name, searchName) == 0)
        {
            if (previous == NULL)
            {
                l->head = current->next;
            }
            else
            {
                previous->next = current->next;
            }

            Element *tmp = current;
            current = current->next;

            free(tmp);
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
}

// ------------ Prompt functions ------------- //

// Prompt Date's information and return the filled Date's structure
Date promptDate()
{
    Date d;

    printf("Jour (jj): ");
    scanf("%d", &d.day);

    printf("Mois (mm): ");
    scanf("%d", &d.month);

    printf("Annee (aaaa): ");
    scanf("%d", &d.year);

    return d;
}

// Prompt Time's information and return the filled Time's structure
Time promptTime()
{
    Time t;

    printf("Heure (hh): ");
    scanf("%d", &t.hour);

    printf("Heure (mm): ");
    scanf("%d", &t.minutes);

    return t;
}

// Prompt Event's information and return the filled Event structure as a pointer
Event *promptEvent()
{
    Event *e = NULL;

    e = (Event *)malloc(sizeof(Event));

    if (e == NULL)
        return NULL;

    char eName[100];
    char ePlace[100];
    char eType[50];
    char c;

    printf("Nom de l'evenement: ");
    scanf("%s", eName);
    e->name = strdup(eName);

    printf("Lieu de l'evenement: ");
    scanf("%s", ePlace);
    e->place = strdup(ePlace);

    printf("Type de l'evenement: ");
    scanf("%s", eType);
    e->type = strdup(eType);

    printf("Date de l'événement: \n");
    e->eventDate = promptDate();

    do
    {
        printf("Definir via un (H)oraire de fin ou via une (D)uree ? ");
        scanf("%c", &c);
    } while (c != 'H' && c != 'D');

    printf("Horaire de debut:\n");
    e->startTime = promptTime();

    if (c == 'H')
    {
        printf("Horaire de fin:\n");
        e->endTime = promptTime();
    }
    else
    {
        Time dt;
        printf("Durée: \n");

        dt = promptTime();

        e->endTime.hour = e->startTime.hour + dt.hour + (e->startTime.minutes + dt.minutes) / 60;
        e->endTime.minutes = (e->startTime.minutes + dt.minutes) % 60;
    }

    return e;
}

// ------------- Edit functions -------------- //

// Edit the Date of an Event
void editDate(Event *evt)
{
    printf("Modification de la date de l'evenement: %s \n", evt->name);
    evt->eventDate = promptDate();
}

// EDit the Schedule of an Event
void editSchedule(Event *evt)
{
    printf("Modification de l'horaire de l'evenement: %s \n", evt->name);
    evt->startTime = promptTime();
}

void editDuration(Event *evt)
{
    Time dt;
    Time t;

    printf("Modification de la duree de l'evenement: %s \n", evt->name);

    printf("Heure (hh): ");
    scanf("%d", &dt.hour);

    printf("Heure (mm): ");
    scanf("%d", &dt.minutes);

    t.hour = evt->startTime.hour + dt.hour + (evt->startTime.minutes + dt.minutes) / 60;
    t.minutes = (evt->startTime.minutes + dt.minutes) % 60;

    evt->endTime = t;
}

// ------------ Display functions ------------ //

void displayEvent(Event *evt)
{
    printf("%20s| %20s| %10s| %2d/%2d/%4d| %2d:%2d| %2d:%2d\n", evt->name, evt->place, evt->type, evt->eventDate.day, evt->eventDate.month, evt->eventDate.year, evt->startTime.hour, evt->startTime.minutes, evt->endTime.hour, evt->endTime.minutes);
}

void displayAllEvents(Liste *l)
{
    Element *current = l->head;

    if (l->size == 0)
    {
        printf("Aucun evenement");
    }
    else
    {
        printf("        Nom         |        Lieu         |   Type    |   Date    | Debut|  Fin \n");
        while (current != NULL)
        {
            displayEvent(current->evt);
            current = current->next;
        }
    }
}

void displayEventsByType(Liste *l, char *type)
{
    displayAllEvents(filterByType(l, type));
}

// ------------- Export unctions ------------- //

void exportEvents(Liste *l, char *filename)
{
    FILE *f;
    f = fopen(filename, "w");

    Element *current = l->head;

    if (f == NULL)
    {
        printf("Impossible d'écrire dans le fichier: %s", filename);
    }
    else
    {
        int i = 0;

        while (current != NULL)
        {
            i++;
            fputs(eventToStr(current->evt), f);
            if (i != l->size)
                fputc('\n', f);
            current = current->next;
        }
    }

    fclose(f);
}

// ----------------- Helpers ----------------- //

Liste *filterByType(Liste *l, char *type)
{
    Liste *filtered = initListe();
    Element *current = l->head;

    while (current != NULL)
    {
        if (current->evt->type == type)
        {
            addElement(filtered, current->evt);
        }
        current = current->next;
    }

    return filtered;
}

char digitToChar(int n)
{
    char dtn[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    if (n > 10 || n < 0)
    {
        return '0';
    }

    return dtn[n];
}

char *eventToStr(Event *evt)
{
    char *name = evt->name;
    char *place = evt->place;
    char *type = evt->type;

    int size = strlen(name) + strlen(place) + strlen(type) + 25;

    char *str = NULL;

    str = (char *)malloc(sizeof(char) * (size + 1));

    if (str == NULL)
        return NULL;

    int offset = 0;

    for (int i = 0; i < strlen(name); i++)
    {
        *(str + offset + i) = *(name + i);
    }

    offset += strlen(name);
    *(str + offset) = ',';
    offset++;

    for (int i = 0; i < strlen(place); i++)
    {
        *(str + offset + i) = *(place + i);
    }

    offset += strlen(place);
    *(str + offset) = ',';
    offset++;

    for (int i = 0; i < strlen(type); i++)
    {
        *(str + offset + i) = *(type + i);
    }

    offset += strlen(type);
    *(str + offset) = ',';
    offset++;

    *(str + offset) = digitToChar(tens(evt->eventDate.day));
    *(str + offset + 1) = digitToChar(units(evt->eventDate.day));
    *(str + offset + 2) = '/';
    *(str + offset + 3) = digitToChar(tens(evt->eventDate.month));
    *(str + offset + 4) = digitToChar(units(evt->eventDate.month));
    *(str + offset + 5) = '/';
    *(str + offset + 6) = digitToChar(thousands(evt->eventDate.year));
    *(str + offset + 7) = digitToChar(hundreds(evt->eventDate.year));
    *(str + offset + 8) = digitToChar(tens(evt->eventDate.year));
    *(str + offset + 9) = digitToChar(units(evt->eventDate.year));
    *(str + offset + 10) = ',';
    *(str + offset + 11) = digitToChar(tens(evt->startTime.hour));
    *(str + offset + 12) = digitToChar(units(evt->startTime.hour));
    *(str + offset + 13) = ':';
    *(str + offset + 14) = digitToChar(tens(evt->startTime.minutes));
    *(str + offset + 15) = digitToChar(units(evt->startTime.minutes));
    *(str + offset + 16) = ',';
    *(str + offset + 17) = digitToChar(tens(evt->endTime.hour));
    *(str + offset + 18) = digitToChar(units(evt->endTime.hour));
    *(str + offset + 19) = ':';
    *(str + offset + 20) = digitToChar(tens(evt->endTime.minutes));
    *(str + offset + 21) = digitToChar(units(evt->endTime.minutes));

    *(str + size) = '\0';

    return str;
}

int thousands(int n)
{
    return ((n - hundreds(n) * 100 - tens(n) * 10 - units(n)) % 10000) / 1000;
}

int hundreds(int n)
{
    return ((n - tens(n) * 10 - units(n)) % 1000) / 100;
}

int tens(int n)
{
    return ((n - units(n)) % 100) / 10;
}

int units(int n)
{
    return n % 10;
}