#include "mathfunc.h"

// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 02, Problem 5b
// File: mathfunc.c
// ====================================================


static int largest_divisor(const int a, const int b);
static bool factor_by_three(const int a, const int b);

static const int max_cube_factor = 1290;

// see mathfunc.h for details
int max2(const int a, const int b) {
    if (a > b) {
        return a;
    }else{
        return b;
    }
}


// see mathfunc.h for details
int min2(const int a, const int b) {
    if (a < b) {
        return a;
    }else{
        return b;
    }
}


// see mathfunc.h for details
// // requires: a >= 1
int maxfactor(const int a) {
    assert(a >= 1);
    return (largest_divisor(a, (a / 2)));
}


// see mathfunc.h for details
bool is_cube_perfect(const int a) {
    assert(a > 1);
    if (factor_by_three(a, 2)) {
        return true;
    }else{
        return false;
    }
}


// largest_divisor(a,b) produces the largest factor
// of which b | a is true.
// requires: b <= a
static int largest_divisor(const int a, const int b){
    assert(b <= a);
    if (0 == b) {
        return 0;
    }else if (a == b){
        return b;
    }else if (0 == (a % b)){
        return b;
    }else{
        return (largest_divisor(a, (b - 1)));
    }
}


// factor_by_three(a,b) produces true if a is a
// cube-perfect number, or false otherwise.
// requires: a > 1 , initialized with b = 2
static bool factor_by_three(const int a, const int b){
    if ((b > 1) && b <= max_cube_factor) {
        if (a == (b * b * b)) {
            return true;
        }else{
            return (factor_by_three(a, (b + 1)));
        }
    }else{
        return false;
    }
}


