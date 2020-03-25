// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 02, Problem 1
// File: fndivide.c
// ====================================================

// A module that implements divides function without the
// the use of the divides operator, /

#include "fndivide.h"
#include <stdio.h>

// int_abs(n) returns the absolute value of n
static int int_abs(const int n);

// fndivide(a,b) consumes a and b, both int's, and produces
// the result of integer division (a/b) without using the
// divides operator, /
// requires: (b!==0)
// examples: fndivide(11,5) == 2
int fndivide(const int a, const int b) {
    if ((a<0 && b>0)||(a>0 && b<0)){
        if (int_abs(a) >= int_abs(b)){
            return -1 + (fndivide((-1 * (int_abs(a) - int_abs(b))), (int_abs(b))));
        }else{
            return 0;
        }
    }else{
        if (int_abs(a) >= int_abs(b)) {
            return 1 + (fndivide((int_abs(a) - int_abs(b)), int_abs(b)));
        }else{
            return 0;
        }
    }
}

// int_abs(n) returns the absolute value of n
static int int_abs(const int n){
    if (n >= 0) {
        return n;
    } else {
        return n * -1;
    }
}
