#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --------------- Structures --------------- //

/* Place structure */
typedef struct Lieu
{
	char *name;		  // Name of the place
	double latitude;  // You know it :)
	double longitude; // You know it :)
} Lieu;

// --------------- Functions ---------------- //

/* Prompt a palce's information and return the place as pointer */
Lieu *promptLieu();