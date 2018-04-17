#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char **argv)
{
	list l = createElement(99);

	addElement(l, 6);
	addElement(l, 5);
	addElement(l, 8);
	addElement(l, 9);
	addElement(l, 8);
	addElement(l, 3);
	addElement(l, 8);
	addElement(l, 5);
	addElement(l, 3);

	display(l);
	printf("\n");

	purge(l);
	l = sort(l);

	display(l);

	list lB = createElement(8);

	addElement(lB, 5);
	addElement(lB, 7);

	printf("\n");
	display(lB);
	printf("\n");

	duolist ll = mutual(l, lB);

	l = ll.lA;
	lB = ll.lB;

	display(l);
	printf("\n");
	display(lB);

	return 0;
}
