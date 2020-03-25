// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 05, Problem 1
// File: exponent.c
// ====================================================
//

#include "exponent.h"
#include <stdlib.h>
#include <assert.h>


// exponent(a,b) returns a raised to the power of b (a^b)
// requires: a>0 and b>0
int exponent(int a, int b) {
    assert(a > 0);
    assert(b > 0);
    if (1==a) {
        return a;
    }else{
        int acc = a;
        for (int i = 1; i < b; ++i) {
            acc *= a;
        }
        return acc;
    }
}

