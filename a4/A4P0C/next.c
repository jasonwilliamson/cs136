// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 04, Problem 0c
// File: next.c
// ====================================================
//

#include "next.h"
#include <stdio.h>

static int call_count = 0;

// next() The first call to next returns 1, each call after
//   that returns 1 higher than the previous call.
// effects: increments call_count by one each time function is
//          called.
int next(void) {
    ++call_count;
    return call_count;
}


