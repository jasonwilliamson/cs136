// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 03, Problem 4
// File: choose.c
// ====================================================
//

#include "choose.h"
#include <assert.h>
#include <stdio.h>
#include <limits.h>

//static int factorial(const int n);

// choose(n,r) returns the number of ways one can choose
//   r things out of n things.
// requires: r >= 0, n > 0, r <= n
int choose(int n, int r) {
    assert(n > 0);
    assert(r >= 0);
    assert(r <= n);
    assert(factorial(n) < INT_MAX);
    assert((factorial(r) * factorial(n - r)) < INT_MAX);
    assert(factorial(n) / (factorial(r) * (factorial(n - r))) < INT_MAX);
    if ((0 == r) || (0 == (n -r))){
        return 0;
    }else{
        return (factorial(n) / (factorial(r) * (factorial(n - r))));
    }
}


// factorial(n) returns the n! value.
// required: must be intialized with n > 0
int factorial(const int n){
    if (n > 0) {
        return n * factorial(n - 1);
    }else{
        return 1;
    }
}


