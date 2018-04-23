#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/////////////////////////////////////////////////
// --------------- Structures ---------------- //
/////////////////////////////////////////////////

// ------------- Date structure -------------- //

typedef struct Date
{
    int day;
    int month;
    int year;
} Date;

// ------------- Time structure -------------- //

typedef struct Time
{
    int hour;
    int minutes;
} Time;

// ------------- Event structure ------------- //

typedef struct Event
{
    char *name;
    char *place;
    char *type;
    Date eventDate;
    Time startTime;
    Time endTime;
} Event;

// ------------ Element structure ------------ //

typedef struct Element
{
    Event *evt;
    struct Element *next;
} Element;

// ------------- Liste structure ------------- //

typedef struct Liste
{
    Element *head;
    int size;
} Liste;

/////////////////////////////////////////////////
// ---------------- Functions ---------------- //
/////////////////////////////////////////////////

// --------- List specific functions --------- //

Liste *initListe();

Element *createElement(Event *e);

void addElement(Liste *l, Event *evt);

void removeElement(Liste *l, char *searchName);

// ------------ Prompt functions ------------- //

Date promptDate();

Time promptTime();

Event *promptEvent();

// ------------- Edit functions -------------- //

void editDate(Event *evt);

void editSchedule(Event *evt);

void editDuration(Event *evt);

// ------------ Display functions ------------ //

void displayEvent(Event *evt);

void displayAllEvents(Liste *l);

void displayEventsByType(Liste *l, char *type);

// ------------- Export unctions ------------- //

void exportEvents(Liste *l, char *filename);

// ----------------- Helpers ----------------- //

Liste *filterByType(Liste *l, char *type);

char digitToChar(int n);

char *eventToStr(Event *evt);

int thousands(int n);

int hundreds(int n);

int tens(int n);

int units(int n);