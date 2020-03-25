// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 03, Problem 0c
// File: gcd.c
// ====================================================

#include "gcd.h"
#include <stdio.h>

// gcd(a,b) Finds the greatest common divisor of a and b.
int gcd(const int a, const int b) {
    if (0 == b) {
        return a;
    }else{
        return gcd(b, (a % b));
    }
}

