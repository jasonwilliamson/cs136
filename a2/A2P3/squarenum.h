// ====================================================
// Jason Williamson (20552360)
// CS 136 Spring 2015
// Assignment 02, Problem 3
// File: squarenum.h
// ====================================================

/* CS136 Spring 2015
 * Assignment 2, Problem 3
 * File: squarenum.h
 * A module for working with square numbers.
 * A square number is a non negative integer bigger than 1 that is
 *  the square of an integer bigger than one.
 * examples of squarenum:  4 (the smallest), 9, 16, 25, 36, ...
 */

#include <stdbool.h>

// is_squarenum(i) determines if i is a square number.
// requires: i>=1
bool is_squarenum(const int i);

// next_squarenum(i) returns the smallest square number greater than i.
// requires: i>=0
int next_squarenum(const int i);


// count_sqnum(a,b) counts the number of square numbers
//  between a and b (inclusive).
// requires: a>1,  b>1, b>a
int count_sqnum(const int a, const int b);

