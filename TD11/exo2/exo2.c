#include "event.h"

int main(int argc, char **argv)
{
	// Initialisation de la liste (la liste = l'agenda)
	Liste *l = initListe();

	// On mets quelques evenement bullshit [
	Event evtA;
	Date aDate;
	Time aStart;
	Time aEnd;

	aDate.day = 20;
	aDate.month = 04;
	aDate.year = 2018;

	aStart.hour = 12;
	aStart.minutes = 30;

	aEnd.hour = 18;
	aEnd.minutes = 00;

	evtA.name = "Un nom oui";
	evtA.place = "Un lieu oui";
	evtA.type = "personnel";
	evtA.eventDate = aDate;
	evtA.startTime = aStart;
	evtA.endTime = aEnd;

	Event evtB = evtA;
	evtB.name = "Non";

	Event evtC = evtA;
	evtC.name = "Non2";
	evtC.type = "associatif";

	addElement(l, &evtA);
	addElement(l, &evtB);
	addElement(l, &evtC);
	// ]

	// Edition de date et d'horaire/durée des evenements
	editDate(&evtA);
	editSchedule(&evtA);
	editDuration(&evtA);

	// Saisie d'evenement par l'utilisateur
	addElement(l, promptEvent());

	// Supression d'evenement (par nom)
	removeElement(l, "Un nom oui");

	// Affichage des evenements
	printf("Evenements: \n");
	displayAllEvents(l);

	// Affichage filtré par type
	printf("\n\nEvenements tries pour 'associatif': \n");
	displayEventsByType(l, "associatif");

	// Déportation des evenements
	exportEvents(l, "events.txt");

	return 0;
}