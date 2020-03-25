// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 02, Problem 5b
// File: mathfunc.h
// ====================================================

#include <stdbool.h>
#include <assert.h>

// max2(a,b) produces the maximum value between a and b
int max2(const int a, const int b);

// min2(a,b) produces the minimum value between a and b
int min2(const int a, const int b);

// maxfactor(a) produces the largest factor of a
// requires: a >= 1
int maxfactor(const int a);

// is_cube_perfect(a) produces true if a is a positive
// cube-perfect number, otherwise false.
// requires: a > 1
bool is_cube_perfect(const int a);

