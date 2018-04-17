#include <stdlib.h>
#include "basketteur.h"

typedef struct list
{
    basketteur val;
    struct list *next;
} * list;

list createElement(basketteur val);
int addElement(list current, basketteur val);
int count(list head);
list removePlayer(list head, char *name);
list playersByName(list head, char *name);
list playersByRole(list head, char *role);
list sortList(list l);
void displayList(list head);
