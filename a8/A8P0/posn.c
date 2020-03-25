// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 08, Problem 0b
// File: posn.c
// ====================================================
//

#include "posn.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


// see posn.h for details
struct posn *make_posn(int x, int y) {
    struct posn *p = malloc(sizeof(struct posn));
    p->x = x;
    p->y = y;
    return p;
}

