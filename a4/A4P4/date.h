// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 04, Problem 2
// File: date.h
// ====================================================
//

//date.h
// module for working with date which consists of day, month and year values

#include <stdbool.h>

struct date{
    int month;
    int day;
    int year;
};

// is_valid(d) determines if d is a valid date
// requires:  d is not NULL
bool is_valid(const struct date *d);


// d_eq(d1, d2) determines if date *d1 and *d2 are equal
// requires: d1, d2 are not NULL, *d1, *d2 are valid dates
bool d_eq(const struct date *d1, const struct date *d2);


// greaterthan(d1, d2) determines if d1 is after the d2 date
// requires: d1, d2 are not NULL, and *d1, *d2 are valid dates
bool greaterthan(const struct date *d1, const struct date *d2);


// tomorrow(d) adds one day to the date d
// requires:  d is not NULL, and *d is a valid date
// effects: modifies (increments) the date in *d
//          new value of *d is still a valid date
void tomorrow(struct date *d);


// yesterday(&d) subtracts one day from the date d
// requires: d is not NULL and *d is a valid date.
// effects: modifies (decrements) the date in *d
//          new value of *d is still a valid date
void yesterday(struct date *d);


