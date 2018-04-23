#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "lieu.h"

// --------------- Structures --------------- //

/* List Element structure */
typedef struct Element
{
	Lieu *place;		  // Place pointer, the "value" of the element
	struct Element *next; // Pointer to the next element, NULL by default
} Element;

/* List structure */
typedef struct Liste
{
	Element *head; // First element of the list (NULL by default)
	int size;	  // Size of the list
} Liste;

// --------------- Functions ---------------- //

/* List initialization */
Liste *initListe();

/* Create an element to add to the list */
Element *createElement(Lieu *place);

/* Add an new element containing the place to the list l */
void addElement(Liste *l, Lieu *place);