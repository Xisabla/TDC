#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int value;
    struct list *next;
} * list;

typedef struct duolist
{
    list lA;
    list lB;
} duolist;

list createElement(int value);

int isEmpty(list head);
int isIn(list l, int val);
int size(list head);
int count(list head, int value);

int addElement(list head, int value);
list unset(list head, int value, int recursive);
int merge(list head, list with);
list sort(list head);
void purge(list head);
duolist mutual(list lA, list lB);

void display(list head);