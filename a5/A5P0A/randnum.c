// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 05, Problem 0a
// File: randnum.c
// ====================================================
//

#include "randnum.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static bool is_set = false;


// set_seed() will initialize a seed value for
// srand() only once.
void set_seed(void) {
    if (!is_set) {
        is_set = true;
        srand(1234);
    }
}


// randnum() returns a random integer between 5 and 20
// (inclusive)
int randnum(void) {
    set_seed();
    return ((rand() % 16) + 5);
}