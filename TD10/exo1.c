#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char **argv)
{
	basketteur A, B, C;

	A.nom = "TrouDuc";
	A.poste = "Feeder";
	A.points = 5;

	B.nom = "Oui";
	B.poste = "Feeder";
	B.points = 13;

	C.nom = "Non";
	C.poste = "OTP Riven";
	C.points = 8;

	list l = createElement(A);
	addElement(l, B);
	addElement(l, C);

	//l = removePlayer(l, "TrouDuc");

	displayList(l);
	printf("Recherche: Nom=Non \n");
	displayList(playersByName(l, "Non"));
	printf("Recherche: Role=Feeder \n");
	displayList(playersByRole(l, "Feeder"));
	printf("Trie:\n");
	displayList(sortList(l));

	return 0;
}