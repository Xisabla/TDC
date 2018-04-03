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

int min(list l)
{
	int min = 32767;

	while (l != NULL)
	{
		if (l->value < min)
		{
			min = l->value;
		}

		l = l->next;
	}

	return min;
}

list sort(list l)
{
	int m = min(l);

	l = unset(l, m, 0);

	list temp = createElement(m);
	list current;

	int n = size(l);

	for (int i = 0; i < n; i++)
	{
		current = l;

		int m = min(current);

		addElement(temp, m);
		l = unset(l, m, 0);
	}

	return temp;
}

void purge(list l)
{
	list current = l->next;
	list previous;

	while (l != NULL)
	{
		current = l->next;
		previous = l;

		while (current != NULL)
		{
			if (current->value == l->value)
			{
				previous->next = current->next;
				free(current);
				current = previous->next;
			}
			else
			{
				previous = current;
				current = current->next;
			}
		}

		l = l->next;
	}
}

void display(list l)
{
	while (l != NULL)
	{
		printf("|%d|", l->value);
		l = l->next;
	}
}