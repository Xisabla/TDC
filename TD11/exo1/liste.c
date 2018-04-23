#include "liste.h"

Liste *initListe()
{
	Liste *l = (Liste *)malloc(sizeof(Liste));

	l->head = NULL;
	l->size = 0;

	return l;
}

Element *createElement(Lieu *place)
{
	Element *Elt = (Element *)malloc(sizeof(Element));

	if (Elt == NULL)
		return NULL;

	Elt->place = place;
	Elt->next = NULL;

	return Elt;
}

void addElement(Liste *l, Lieu *place)
{
	Element *Elt = createElement(place);

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