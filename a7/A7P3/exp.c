// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 07, Problem 3
// File: exp.c
// ====================================================
//

// A module that provides the funciton fast_exp(int x, int n); where the
// the running time of fast_exp is of O(log n) where n is the value fo the consumed n.

#include "exp.h"
#include <stdio.h>
#include <assert.h>

// sqr(x) consumes an int, x and returns the integer
// value x*x
// time: O(1)
static int sqr(int x){
    return x*x;
}


// fast_exp(x,n) consumes an int, x, and raises it to the power of
// the consumed int, a.
// time: O(logn)
// requires: n >= 0
int fast_exp(int x, int n) {
    assert(n >= 0);
    int total = 1;
    if (n == 0) {
        return 1;
    }else{
        while (n > 0) {
            if (n >= 2) {
                total *= sqr(x);
                --n;
                --n;
            }else{
                total *= x;
                --n;
            }
        }
        
    }
    return total;
}


