#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int value;
    struct list *next;
} * list;

list createElement(int value);
int isEmpty(list head);
int addElement(list head, int value);
int unset(list head, int value, int recursive);
int merge(list head, list with);
int count(list head, int value);
void display(list head);