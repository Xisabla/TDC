#pragma once
#include <math.h>
#include "lieu.h"
#include "liste.h"

// --------------- Functions ---------------- //

/* Import from a file into a list */
// BE CAREFULL
// ⚠️⚠️⚠️ The end of your file must be a new line
void importTrajet(Liste *l, char *filename);

/* Prompt a place and insert it into a list */
void promptTrajet(Liste *l);

/* Calculate the total distance for the list */
double distance(Liste *l);