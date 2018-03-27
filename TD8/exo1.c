#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Tous ce trouve dans le fichier list.c
// Compilation:
// 		Etape 1: Compiler la bibliothéque "list.c"
//			gcc -c list.c
//		Etape 2: Compiler le fichier en lui donnant la bibliothéque
//			gcc exo1.c -o exo1 list.o

int main(int argc, char **argv)
{
	list l = createElement(42);

	addElement(l, 12);
	addElement(l, 160);
	addElement(l, 12);
	addElement(l, 159);
	addElement(l, 5);
	addElement(l, 209);
	addElement(l, 87);
	addElement(l, 5);
	addElement(l, 185);

	list i = createElement(5);

	addElement(i, 7);

	display(i);

	printf("\n----------------------------------------------------------------\n");

	display(l);

	unset(l, 5, 0);
	unset(l, 12, 1);

	printf("\n----------------------------------------------------------------\n");

	display(l);

	printf("\n----------------------------------------------------------------\n");

	merge(l, i);

	display(l);

	return 0;
}
