#include "list.h"

list createElement(int value)
{
	list element = (list)malloc(sizeof(list));
	element->value = value;
	element->next = NULL;

	return element;
}

int isEmpty(list head)
{
	return (head == NULL);
}

int addElement(list current, int value)
{
	list element = createElement(value);

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

int unset(list l, int value, int recursive)
{
	int n = 0;

	if (l == NULL)
	{
		return 0;
	}

	if (l->next == NULL)
	{
		return 0;
	}

	list previous = l;
	l = l->next;

	while (l != NULL)
	{
		if (l->value == value && ((n == 0) || (n > 0 && recursive == 1)))
		{
			list temp = l->next;
			previous->next = temp;
			free(l);
			l = temp;
			n++;
		}
		else
		{
			previous = l;
			l = l->next;
		}
	}
}

int count(list l, int value)
{
	int n = 0;

	while (l != NULL)
	{
		if (l->value == value)
			n++;
		l = l->next;
	}

	return n;
}

int merge(list current, list l)
{
	if (current == NULL || l == NULL)
	{
		return 0;
	}

	while (current->next != NULL)
	{
		current = current->next;
	}

	current->next = l;
}

void display(list l)
{
	while (l != NULL)
	{
		printf("|%d|", l->value);
		l = l->next;
	}
}