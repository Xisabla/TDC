#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int value;
    struct list *next;
} * list;

list createElement(int value);

int isEmpty(list head);
int size(list head);
int count(list head, int value);

int addElement(list head, int value);
list unset(list head, int value, int recursive);
int merge(list head, list with);
list sort(list head);
void purge(list head);

void display(list head);