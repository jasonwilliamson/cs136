// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 04, Problem 0a
// File: swap.c
// ====================================================
//

#include "swap.h"
#include <stdio.h>
#include <assert.h>

/*
struct posn {
    int x;
    int y;
}; */


// swap(p,q) Swaps the posn structures pointed at by p and q.
// requires: p != NULL, q != NULL
void swap(struct posn *p, struct posn *q) {
    assert(p != NULL);
    assert(q != NULL);
    struct posn tmp = *q;
    *q = *p;
    *p = tmp;
}

