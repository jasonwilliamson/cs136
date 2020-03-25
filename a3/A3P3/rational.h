// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 03, Problem 3
// File: rational.h
// ====================================================
//

#include <stdbool.h>
#include <assert.h>


// a rational structure represents a rational number
//   with a numerator (num) and a deninator (den):
// * for example, num = 1, den = 3 corresponds to a third (1/3)
// * For a valid rational, den can never be 0
struct rational {
    int num;
    int den;
};

// R(n,d) returns the rational n/d
//   requires:  d is non-zero
struct rational R(int n, int d);

// NOTE: for all functions below, the return values will be *simplified*
//       the arguments may not be simplified

// Rules for simplifying rationals:
// * all integers (including zero) must have a den of 1
// * all rationals will use the lowest possible den,
//   so (2/4) will never be returned: instead, (1/2) would be returned
// * the den cannot be negative.  (-1/-2) or (1/-2) are not simplified


// r_add(a,b) adds two rationals a+b
// requires: a,b are valid rationals
struct rational r_add(struct rational a, struct rational b);

// r_sub(a,b) subtracts two rationals a-b
// requires: a,b are valid rationals
struct rational r_sub(struct rational a, struct rational b);

// r_mult(a,b) multiplies two rationals a*b
// requires: a,b are valid rationals
struct rational r_mult(struct rational a, struct rational b);

// r_div(a,b) divides two rationals a/b
// requires: a,b are valid rationals, b is non-zero
struct rational r_div(struct rational a, struct rational b);

// r_equal(a,b) determines if rationals a and b are equal
// requires: a,b are valid rationals
bool r_equal(struct rational a, struct rational b);

