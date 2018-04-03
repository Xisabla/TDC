#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char **argv)
{
	list l = createElement(99);

	addElement(l, 5);
	addElement(l, 8);
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
	return 0;
}
