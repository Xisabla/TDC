#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

list createElement(basketteur val)
{
    list element = (list)malloc(sizeof(struct list));

    element->val = val;
    element->next = NULL;

    return element;
}

int addElement(list current, basketteur val)
{
    list element = createElement(val);

    if (current == NULL)
    {
        return 0;
    }

    if (element == NULL)
    {
        printf("Erreur memoire");
        return -1;
    }

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = element;

    return 1;
}

int count(list head)
{
    int n = 0;

    while (head != NULL)
    {
        n++;
        head = head->next;
    }

    return n;
}

list removePlayer(list head, char *name)
{
    list l = head;

    if (l == NULL || l->next == NULL)
    {
        return NULL;
    }

    list previous = NULL;

    while (l != NULL)
    {
        list temp = l->next;

        if (strcmp((l->val).nom, name) == 0)
        {
            if (previous == NULL)
            {
                head = l->next;
            }
            else
            {
                previous->next = temp;
                free(l);
            }

            return head;
        }

        previous = l;
        l = temp;
    }

    return head;
}

list playersByName(list head, char *name)
{
    list players = NULL;

    while (head != NULL)
    {
        if (strcmp((head->val).nom, name) == 0)
        {
            if (players == NULL)
            {
                players = createElement(head->val);
            }
            else
            {
                addElement(players, head->val);
            }
        }

        head = head->next;
    }

    return players;
}

list playersByRole(list head, char *role)
{
    list players = NULL;

    while (head != NULL)
    {
        if (strcmp((head->val).poste, role) == 0)
        {
            if (players == NULL)
            {
                players = createElement(head->val);
            }
            else
            {
                addElement(players, head->val);
            }
        }

        head = head->next;
    }

    return players;
}

basketteur max(list l)
{
    basketteur m;
    m.points = 0;

    while (l != NULL)
    {
        if ((l->val).points > m.points)
        {
            m = l->val;
        }

        l = l->next;
    }

    return m;
}

list sortList(list l)
{
    basketteur m = max(l);

    list temp = createElement(m);
    l = removePlayer(l, m.nom);

    while (l != NULL)
    {
        m = max(l);
        addElement(temp, m);
        l = removePlayer(l, m.nom);
    }

    return temp;
}

void displayList(list head)
{
    if (head != NULL)
    {
        displayPlayer(head->val);
        displayList(head->next);
    }
}