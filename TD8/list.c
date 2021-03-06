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

list unset(list head, int value, int recursive)
{
	int n = 0;
	list l = head;

	if (l == NULL || l->next == NULL)
	{
		return NULL;
	}

	list previous = NULL;

	while (l != NULL)
	{
		list temp = l->next;

		if (l->value == value && (n == 0 || recursive == 1))
		{
			if (previous == NULL)
			{
				head = l->next;
			}
			else
			{
				previous->next = temp;
				free(l);
				n++;
			}
		}
		else
		{
			previous = l;
		}

		l = temp;
	}

	return head;
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

int size(list l)
{
	int n = 0;

	while (l != NULL)
	{
		l = l->next;
		n++;
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

	return 1;
}

void display(list l)
{
	while (l != NULL)
	{
		printf("|%d|", l->value);
		l = l->next;
	}
}